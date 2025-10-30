import cv2
import numpy as np
from ultralytics import YOLO
import time
from collections import defaultdict, deque
import pyrealsense2 as rs
import torch
import threading
from queue import Queue
# ROS2 相关
try:
    import rclpy
    from geometry_msgs.msg import PointStamped
except Exception:
    rclpy = None
    PointStamped = None

# 写入2D+3D坐标到txt（追加模式）
def write_coord_to_file(x, y, point_3d=None, file_path="output_coords.txt"):
    # 每次只写一行，覆盖原内容
    with open(file_path, "w") as f:
        if point_3d:
            f.write(f"{point_3d[0]:.4f},{point_3d[1]:.4f},{point_3d[2]:.4f}\n")
        else:
            f.write(f"None,None,None\n")

class YOLOPedestrianTracker:
    def __init__(self, model_path='yolov8n.pt', confidence_threshold=0.25, device='cuda:0', infer_size=320,
                 enable_ros=True, ros_topic='/pedestrian_point', frame_id='camera_color_optical_frame'):
        # 每次启动时清空txt内容
        open("output_coords.txt", "w").close()
        print("CUDA available:", torch.cuda.is_available())
        if torch.cuda.is_available():
            print("Current device:", torch.cuda.current_device())
        else:
            print("当前为CPU推理，未检测到可用GPU！")
        self.model = YOLO(model_path)
        self.device = device
        self.model.to(device)
        # 半精度策略：不手动 model.half()，交给 Ultralytics 内部，否则会在 fuse 时类型冲突
        self.use_half = ('cuda' in device) and torch.cuda.is_available()
        if self.use_half:
            print("启用FP16推理(自动) —— 若发生错误将回退FP32")
        else:
            print("使用FP32推理")
        self.confidence_threshold = confidence_threshold
        self.pedestrian_class_id = 0
        self.infer_size = infer_size  # 推理输入尺寸

        # RealSense初始化
        self.rs_pipe = rs.pipeline()
        self.rs_cfg = rs.config()
        self.rs_cfg.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        self.rs_cfg.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        self.rs_profile = self.rs_pipe.start(self.rs_cfg)
        self.color_intrinsics = None
        self.depth_frame = None
        for _ in range(15):  # 减少预热帧
            self.rs_pipe.wait_for_frames()

        self.frame_width = 640
        self.frame_height = 480
        self.fps = 30
        print(f"输入源: {self.frame_width}x{self.frame_height} @ {self.fps} FPS")

        self.track_id_counter = 0
        self.tracks = defaultdict(dict)
        self.track_history = defaultdict(lambda: deque(maxlen=5))  # 历史长度减小

        self.selected_track_id = None
        self.last_selected_ped = None
        self.selected_track_history = deque(maxlen=20)
        self.lost_track_count = 0
        self.max_lost_count = 40  # 略减少

        self.gating_radius = 120  # 放宽

        self.kalman = None
        self.selected_hist = None  # 已废弃外观匹配
        self.last_frame = None

        self.current_fps = 0.0
        self.fps_win = deque(maxlen=30)
        self.window_name = 'Pedestrian Tracker'

        self.frame_queue = Queue(maxsize=1)  # 只保留最新帧
        self.stop_event = threading.Event()
        self.capture_thread = threading.Thread(target=self._frame_capture_loop, daemon=True)
        self.capture_thread.start()

        # 预热模型（避免首帧延迟）
        warm = np.zeros((self.infer_size, self.infer_size, 3), dtype=np.uint8)
        try:
            _ = self.model.predict(warm, imgsz=self.infer_size, verbose=False, device=self.device, half=self.use_half)
        except Exception as e:
            print("FP16 预热失败，切换FP32:", e)
            self.use_half = False
            _ = self.model.predict(warm, imgsz=self.infer_size, verbose=False, device=self.device, half=False)
        print("模型预热完成")

        # ===== ROS2 初始化 =====
        self.ros_enabled = False
        self.ros_topic = ros_topic
        self.frame_id = frame_id
        if enable_ros and rclpy is not None:
            try:
                rclpy.init(args=None)
                self.ros_node = rclpy.create_node('pedestrian_coord_publisher')
                self.coord_pub = self.ros_node.create_publisher(PointStamped, self.ros_topic, 10)
                self.ros_enabled = True
                self.ros_spin_thread = threading.Thread(target=self._ros_spin_loop, daemon=True)
                self.ros_spin_thread.start()
                print(f"ROS2发布启用: 话题 {self.ros_topic} | frame_id={self.frame_id}")
            except Exception as e:
                print("ROS2初始化失败，已禁用发布:", e)
        else:
            if enable_ros:
                print("未检测到 rclpy，ROS2 发布被禁用")

    def pixel_to_3d(self, u, v):
        if self.depth_frame is None or self.color_intrinsics is None:
            return None
        depth = self.depth_frame.get_distance(u, v)
        if depth == 0:
            return None
        point_3d = rs.rs2_deproject_pixel_to_point(self.color_intrinsics, [u, v], depth)
        return point_3d

    def _log_selected_coord(self, selected_ped):
        ts = time.strftime("%H:%M:%S")
        if self.selected_track_id and selected_ped:
            print(f"[{ts}] ID:{self.selected_track_id} | ({selected_ped['center_x']},{selected_ped['center_y']})")
            point_3d = self.pixel_to_3d(selected_ped['center_x'], selected_ped['center_y'])
            write_coord_to_file(selected_ped['center_x'], selected_ped['center_y'], point_3d)
            if self.ros_enabled and point_3d is not None:
                msg = PointStamped()
                msg.header.stamp = self.ros_node.get_clock().now().to_msg()
                msg.header.frame_id = self.frame_id
                # RealSense deproject 得到的是以相机坐标系(m)为单位的 XYZ
                msg.point.x = float(point_3d[0])
                msg.point.y = float(point_3d[1])
                msg.point.z = float(point_3d[2])
                self.coord_pub.publish(msg)
        elif self.selected_track_id and 0 < self.lost_track_count <= self.max_lost_count:
            pred = self._predict_selected()
            if pred:
                # 遮挡期间不发布（如需发布 NaN 可在此添加）
                print(f"[{ts}] ID:{self.selected_track_id} | 预测({pred[0]},{pred[1]}) 遮挡{self.lost_track_count}/{self.max_lost_count}")

    def _init_kalman(self, cx, cy):
        kf = cv2.KalmanFilter(4, 2)
        kf.transitionMatrix = np.array([[1,0,1,0],[0,1,0,1],[0,0,1,0],[0,0,0,1]], dtype=np.float32)
        kf.measurementMatrix = np.array([[1,0,0,0],[0,1,0,0]], dtype=np.float32)
        kf.processNoiseCov = np.eye(4, dtype=np.float32) * 5e-3
        kf.measurementNoiseCov = np.eye(2, dtype=np.float32) * 3e-2
        kf.errorCovPost = np.eye(4, dtype=np.float32)
        kf.statePost = np.array([[cx],[cy],[0],[0]], dtype=np.float32)
        self.kalman = kf

    def _predict_selected(self):
        if self.kalman is None:
            return None
        pred = self.kalman.predict()
        return int(pred[0,0]), int(pred[1,0])

    def _mouse_click_callback(self, event, x, y, flags, param):
        if event != cv2.EVENT_LBUTTONDOWN or not self.tracks:
            return
        for track_id, track_info in self.tracks.items():
            x1, y1, x2, y2 = track_info['bbox']
            if (x1 - 5) < x < (x2 + 5) and (y1 - 5) < y < (y2 + 5):
                self.selected_track_id = track_id
                self.lost_track_count = 0
                self.last_selected_ped = track_info
                self.selected_track_history.clear()
                center = (track_info['center_x'], track_info['center_y'])
                self.selected_track_history.append(center)
                self._init_kalman(center[0], center[1])
                print(f"选中目标: ID={track_id}")
                self._log_selected_coord(track_info)
                break

    def _calculate_iou(self, bbox1, bbox2):
        inter_x1 = max(bbox1[0], bbox2[0])
        inter_y1 = max(bbox1[1], bbox2[1])
        inter_x2 = min(bbox1[2], bbox2[2])
        inter_y2 = min(bbox1[3], bbox2[3])
        inter_area = max(0, inter_x2 - inter_x1) * max(0, inter_y2 - inter_y1)
        if inter_area == 0:
            return 0.0
        bbox1_area = (bbox1[2] - bbox1[0]) * (bbox1[3] - bbox1[1])
        bbox2_area = (bbox2[2] - bbox2[0]) * (bbox2[3] - bbox2[1])
        union_area = bbox1_area + bbox2_area - inter_area
        if union_area <= 0:
            return 0.0
        return inter_area / union_area

    def _calculate_trajectory_score(self, new_center, history):
        if len(history) < 3:
            return 0.5
        prev_center = history[-1]
        prev_prev_center = history[-2]
        dx = prev_center[0] - prev_prev_center[0]
        dy = prev_center[1] - prev_prev_center[1]
        predicted_center = (prev_center[0] + dx, prev_center[1] + dy)
        distance = np.hypot(new_center[0] - predicted_center[0], new_center[1] - predicted_center[1])
        max_distance = 100
        return max(0.0, 1.0 - (distance / max_distance))

    def _update_tracks(self, detected_pedestrians, frame):
        new_tracks = {}
        assigned_det_idx = set()

        # 先匹配已选目标：使用中心距离 + 简单IoU
        if self.selected_track_id is not None and self.last_selected_ped is not None:
            pred_center = self._predict_selected() or (self.last_selected_ped['center_x'], self.last_selected_ped['center_y'])
            best_i, best_score = -1, 1e9
            for i, det in enumerate(detected_pedestrians):
                cx, cy = det['center_x'], det['center_y']
                dist = np.hypot(cx - pred_center[0], cy - pred_center[1])
                if dist > self.gating_radius:
                    continue
                # 距离优先
                if dist < best_score:
                    best_score = dist
                    best_i = i
            if best_i != -1:
                det = detected_pedestrians[best_i]
                new_tracks[self.selected_track_id] = det
                assigned_det_idx.add(best_i)
                self.last_selected_ped = det
                if self.kalman is not None:
                    meas = np.array([[det['center_x']], [det['center_y']]], dtype=np.float32)
                    self.kalman.correct(meas)

        # 其它轨迹简单IoU匹配
        for i, det in enumerate(detected_pedestrians):
            if i in assigned_det_idx:
                continue
            best_track, best_iou = None, 0.0
            for track_id, track_info in self.tracks.items():
                if track_id == self.selected_track_id:
                    continue
                iou = self._calculate_iou(det['bbox'], track_info.get('bbox',(0,0,0,0)))
                if iou > best_iou and iou > 0.1:
                    best_iou = iou
                    best_track = track_id
            if best_track is not None:
                new_tracks[best_track] = det
                assigned_det_idx.add(i)

        # 未匹配->新轨迹
        for i, det in enumerate(detected_pedestrians):
            if i in assigned_det_idx:
                continue
            new_tracks[self.track_id_counter] = det
            self.track_id_counter += 1

        # 更新历史
        for track_id, info in new_tracks.items():
            center = (info['center_x'], info['center_y'])
            self.track_history[track_id].append(center)
            if track_id == self.selected_track_id:
                self.selected_track_history.append(center)
        self.tracks = new_tracks

    def _frame_capture_loop(self):
        while not self.stop_event.is_set():
            frames = self.rs_pipe.wait_for_frames()
            color_frame = frames.get_color_frame()
            depth_frame = frames.get_depth_frame()
            if not color_frame or not depth_frame:
                continue
            frame = np.asanyarray(color_frame.get_data())
            if self.color_intrinsics is None:
                self.color_intrinsics = color_frame.profile.as_video_stream_profile().get_intrinsics()
            # 优化：只保留最新帧，丢弃旧帧
            while not self.frame_queue.empty():
                try:
                    self.frame_queue.get_nowait()
                except:
                    break
            try:
                self.frame_queue.put((frame, depth_frame), timeout=0.02)
            except:
                pass

    def get_pedestrian_coordinates(self):
        try:
            frame, depth_frame = self.frame_queue.get(timeout=0.5)
        except:
            return {}, None, None
        self.last_frame = frame
        self.depth_frame = depth_frame
        # 推理
        with torch.inference_mode():
            try:
                results = self.model(
                    frame,
                    conf=self.confidence_threshold,
                    classes=[self.pedestrian_class_id],
                    verbose=False,
                    agnostic_nms=True,
                    iou=0.6,
                    imgsz=self.infer_size,
                    device=self.device,
                    half=self.use_half
                )
            except Exception as e:
                if self.use_half:
                    print("运行时FP16失败，回退FP32:", e)
                    self.use_half = False
                    results = self.model(
                        frame,
                        conf=self.confidence_threshold,
                        classes=[self.pedestrian_class_id],
                        verbose=False,
                        agnostic_nms=True,
                        iou=0.6,
                        imgsz=self.infer_size,
                        device=self.device,
                        half=False
                    )
                else:
                    raise
        detected_pedestrians = []
        for result in results:
            if not hasattr(result, "boxes") or result.boxes is None:
                continue
            for box in result.boxes:
                xyxy = box.xyxy[0].tolist()
                x1, y1, x2, y2 = map(int, xyxy)
                if (x2 - x1) < 28 or (y2 - y1) < 56:  # 略减过滤阈值
                    continue
                x1 = max(0, x1)
                y1 = max(0, y1)
                x2 = min(self.frame_width - 1, x2)
                y2 = min(self.frame_height - 1, y2)
                center_x = (x1 + x2) // 2
                center_y = (y1 + y2) // 2
                detected_pedestrians.append({'bbox': (x1, y1, x2, y2), 'center_x': center_x, 'center_y': center_y})

        self._update_tracks(detected_pedestrians, frame)

        selected_ped = None
        if self.selected_track_id is not None:
            if self.selected_track_id in self.tracks:
                selected_ped = self.tracks[self.selected_track_id]
                self.lost_track_count = 0
                self.last_selected_ped = selected_ped
            elif self.lost_track_count < self.max_lost_count and self.last_selected_ped:
                pred = self._predict_selected() or (self.last_selected_ped['center_x'], self.last_selected_ped['center_y'])
                lw = self.last_selected_ped['bbox'][2] - self.last_selected_ped['bbox'][0]
                lh = self.last_selected_ped['bbox'][3] - self.last_selected_ped['bbox'][1]
                px1 = int(pred[0] - lw / 2)
                py1 = int(pred[1] - lh / 2)
                px2 = int(pred[0] + lw / 2)
                py2 = int(pred[1] + lh / 2)
                selected_ped = {'bbox': (px1, py1, px2, py2), 'center_x': int(pred[0]), 'center_y': int(pred[1])}
                self.lost_track_count += 1
            else:
                print(f"目标丢失: ID={self.selected_track_id}")
                self.selected_track_id = None
                self.last_selected_ped = None
                self.kalman = None
                self.selected_track_history.clear()
                self.lost_track_count = 0

        return self.tracks, selected_ped, frame

    def visualize_detection(self, tracks, selected_ped, frame):
        if frame is None:
            return None
        for track_id, track_info in tracks.items():
            x1, y1, x2, y2 = track_info['bbox']
            cx, cy = track_info['center_x'], track_info['center_y']
            is_sel = self.selected_track_id and (track_id == self.selected_track_id)
            color = (0, 0, 255) if is_sel else (0, 255, 0)
            lw = 3 if is_sel else 2
            cv2.rectangle(frame, (x1, y1), (x2, y2), color, lw)
            cv2.circle(frame, (cx, cy), 4, color, -1)
            cv2.putText(frame, f"ID:{track_id}", (x1, y1 - 8), cv2.FONT_HERSHEY_SIMPLEX, 0.55, color, 2)
        if self.selected_track_id and len(self.selected_track_history) > 1:
            for i in range(1, len(self.selected_track_history)):
                cv2.line(frame, self.selected_track_history[i-1], self.selected_track_history[i], (0,200,255), 2)
        if self.selected_track_id and selected_ped:
            status = "Normal" if self.lost_track_count == 0 else f"Shielding({self.lost_track_count}/{self.max_lost_count})"
            cv2.putText(frame, f"ID:{self.selected_track_id} | {status} | ({selected_ped['center_x']},{selected_ped['center_y']})", (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255,255,0), 2)
        else:
            cv2.putText(frame, "Click target | r:Reset | q:Quit", (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,0,0), 2)
        cv2.putText(frame, f"FPS: {self.current_fps:.1f}", (10,60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,255,0), 2)
        return frame

    def _ros_spin_loop(self):
        """后台执行 rclpy.spin_once，确保时间戳等正常工作。"""
        if not self.ros_enabled:
            return
        while rclpy.ok() and not self.stop_event.is_set():
            try:
                rclpy.spin_once(self.ros_node, timeout_sec=0.1)
            except Exception:
                break

    def run(self, output_video=None):
        cv2.namedWindow(self.window_name, cv2.WINDOW_NORMAL)
        cv2.resizeWindow(self.window_name, 1280, 720)
        cv2.setMouseCallback(self.window_name, self._mouse_click_callback)
        try:
            while True:
                t0 = time.time()
                # 采集+推理
                t_cap = time.time()
                tracks, selected_ped, frame = self.get_pedestrian_coordinates()
                t_pred = time.time()
                if frame is None:
                    continue
                self._log_selected_coord(selected_ped)
                # 绘制/显示
                frame = self.visualize_detection(tracks, selected_ped, frame)
                cv2.imshow(self.window_name, frame)
                t_draw = time.time()
                dt = t_draw - t0
                # 统计FPS
                if dt > 0:
                    self.fps_win.append(1.0/dt)
                    self.current_fps = sum(self.fps_win)/len(self.fps_win)
                key = cv2.waitKey(1) & 0xFF
                if key == ord('q'):
                    break
                elif key == ord('r'):
                    self.selected_track_id = None
                    self.last_selected_ped = None
                    self.kalman = None
                    self.selected_track_history.clear()
                    self.lost_track_count = 0
                    print("已重置")
        finally:
            self.stop_event.set()
            self.capture_thread.join(timeout=1)
            # ROS 清理
            if self.ros_enabled:
                try:
                    self.ros_node.destroy_node()
                except Exception:
                    pass
                try:
                    rclpy.shutdown()
                except Exception:
                    pass
            self.rs_pipe.stop()
            cv2.destroyAllWindows()
            print("资源已释放")

if __name__ == "__main__":
    tracker = YOLOPedestrianTracker(
        model_path='yolov8n.pt',
        confidence_threshold=0.25,
        device='cuda:0' if torch.cuda.is_available() else 'cpu',
        infer_size=320,
        enable_ros=True,
        ros_topic='/pedestrian_point',
        frame_id='camera_color_optical_frame'
    )
    tracker.run()
    
    #test：远程推送