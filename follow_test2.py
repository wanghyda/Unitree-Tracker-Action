import numpy as np
from ultralytics import YOLO
import time
from collections import deque
import pyrealsense2 as rs
import torch
import threading
from queue import Queue
import subprocess
import math

class ImprovedRobotFollower:
    def __init__(self, network_interface="eth0", model_path='yolov8n.pt'):
        self.network_interface = network_interface
        
        self.camera_height = 1.4  
        
        # 控制参数 - 提高旋转灵敏度
        self.target_distance = 2.0  # 目标水平距离
        self.max_forward_speed = 0.4
        self.max_side_speed = 0.3
        self.max_turn_speed = 1.0  # 提高最大旋转速度
        
      
        self.kp_distance = 0.6    
        self.kp_center = 0.8      # 降低横向移动权重，优先使用旋转
        self.kp_turn = 2.0        
        #過濾抖動,目前沒有可視化,不清楚相機的抖動扎狀況,但是YOLO識別的置信度看起來還可以
        self.speed_history = deque(maxlen=3)
        self.last_speeds = (0, 0, 0)
       
        self.rotation_threshold = 0.5  
        self.min_turn_speed = 0.3      
        
        print("初始化YOLOv8模型...")
        self.model = YOLO(model_path)
        self.device = 'cuda:0' if torch.cuda.is_available() else 'cpu'
        self.model.to(self.device)
      
        self.use_half = torch.cuda.is_available()
        if self.use_half:
            print("启用FP16推理加速")
        else:
            print("使用FP32推理")
            
        self.confidence_threshold = 0.3
        self.pedestrian_class_id = 0
        self.infer_size = 320

        print("初始化RealSense相机...")
        self.rs_pipe = rs.pipeline()
        self.rs_cfg = rs.config()
        self.rs_cfg.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        self.rs_cfg.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        self.rs_profile = self.rs_pipe.start(self.rs_cfg)
        self.color_intrinsics = None
        self.depth_frame = None
       
        for _ in range(10):
            self.rs_pipe.wait_for_frames()

        self.frame_width = 640
        self.frame_height = 480

        self.tracking_enabled = True
        self.lost_track_count = 0
        self.max_lost_count = 30

        self.frame_queue = Queue(maxsize=1)
        self.stop_event = threading.Event()
        self.capture_thread = threading.Thread(target=self._frame_capture_loop, daemon=True)
        self.capture_thread.start()

        print("预热模型...")
        warm_frame = np.zeros((self.infer_size, self.infer_size, 3), dtype=np.uint8)
        try:
            _ = self.model.predict(warm_frame, imgsz=self.infer_size, verbose=False, 
                                 device=self.device, half=self.use_half)
        except Exception as e:
            print(f"FP16预热失败，使用FP32: {e}")
            self.use_half = False
            _ = self.model.predict(warm_frame, imgsz=self.infer_size, verbose=False, 
                                 device=self.device, half=False)
     
        self.frame_count = 0
        self.start_time = time.time()
        self.last_log_time = time.time()
        
        print("开始自动跟踪...")

    def pixel_to_ground_coordinates(self, u, v)
        if self.depth_frame is None or self.color_intrinsics is None:
            return None
            
        u_int = int(u)
        v_int = int(v)
        
        if u_int < 0 or u_int >= self.frame_width or v_int < 0 or v_int >= self.frame_height:
            return None
            
        depth = self.depth_frame.get_distance(u_int, v_int)
        if depth == 0:
            return None
        
        camera_point = rs.rs2_deproject_pixel_to_point(self.color_intrinsics, [u_int, v_int], depth)
        x_cam, y_cam, z_cam = camera_point
        
        # 转换为地面坐标系,計算兩個投影點之間的距離
        person_height_estimate = 0.9  
        height_difference = self.camera_height - person_height_estimate
        
        if z_cam > 0:
            horizontal_distance = math.sqrt(z_cam**2 - height_difference**2) if z_cam > abs(height_difference) else z_cam
            
            ground_x = x_cam * (horizontal_distance / z_cam) if z_cam > 0 else x_cam
            
            return (ground_x, 0, horizontal_distance)
        
        return (x_cam, 0, z_cam)

    def estimate_foot_position(self, bbox, depth_frame):
        x1, y1, x2, y2 = bbox
        
        foot_u = (x1 + x2) // 2
        foot_v = y2  
        
        foot_v = min(foot_v, self.frame_height - 1)
        
        return self.pixel_to_ground_coordinates(foot_u, foot_v)

    def send_robot_command(self, vx, vy, omega):
        self.speed_history.append((vx, vy, omega))
        vx_smooth = np.mean([s[0] for s in self.speed_history])
        vy_smooth = np.mean([s[1] for s in self.speed_history])
        omega_smooth = np.mean([s[2] for s in self.speed_history])
        
        vx_smooth = np.clip(vx_smooth, -self.max_forward_speed, self.max_forward_speed)
        vy_smooth = np.clip(vy_smooth, -self.max_side_speed, self.max_side_speed)
        omega_smooth = np.clip(omega_smooth, -self.max_turn_speed, self.max_turn_speed)
        
        if abs(vx_smooth) < 0.05: vx_smooth = 0
        if abs(vy_smooth) < 0.05: vy_smooth = 0
        if abs(omega_smooth) < 0.1: omega_smooth = 0
        
        #RPC
        cmd = f'./g1_loco_client --network_interface={self.network_interface} --move="{vx_smooth:.2f} {vy_smooth:.2f} {omega_smooth:.2f}"'
        
        try:
            subprocess.run(cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            self.last_speeds = (vx_smooth, vy_smooth, omega_smooth)
        except Exception as e:
            print(f"DIE: {e}")

    def stop_robot(self):
        cmd = f'./g1_loco_client --network_interface={self.network_interface} --stop_move'
        try:
            subprocess.run(cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        except Exception as e:
            print(f"DIE: {e}")

    def calculate_control(self, ground_point, target_center_x, frame_center_x):
        if ground_point is None:
            return 0, 0, 0
            
        ground_x, ground_y, horizontal_distance = ground_point
       
        distance_error = horizontal_distance - self.target_distance
        vx = self.kp_distance * distance_error
        
        image_offset = (target_center_x - frame_center_x) / frame_center_x
        
        vy = 0  # 默认不横向移动
        omega = 0
        
        if abs(image_offset) > self.rotation_threshold:
            omega = self.kp_turn * image_offset
    
            if abs(omega) < self.min_turn_speed:
                omega = self.min_turn_speed if omega > 0 else -self.min_turn_speed
        else:
            vy = self.kp_center * ground_x
            omega = -0.5 * self.kp_turn * image_offset  
       
        if abs(omega) > 0.2:
            direction = "右转" if omega > 0 else "左转"
            print(f"旋转控制: {direction} (ω={omega:.2f}), 图像偏移: {image_offset:.2f}")
        
        return vx, vy, omega

    def select_best_target(self, detections, depth_frame):
        """选择最佳跟踪目标"""
        if not detections:
            return None
            
        best_detection = None
        best_score = -float('inf')
        
        for det in detections:
            bbox = det['bbox']
            
            ground_point = self.estimate_foot_position(bbox, depth_frame)
            
            if ground_point is None:
                continue
                
            ground_x, ground_y, horizontal_distance = ground_point
           
            center_x = self.frame_width // 2
            center_offset = abs(det['center_x'] - center_x) / center_x
            center_score = 1.0 - center_offset
            
            bbox_width = bbox[2] - bbox[0]
            bbox_height = bbox[3] - bbox[1]
            size_ratio = bbox_width * bbox_height / (self.frame_width * self.frame_height)
            size_score = 1.0 - abs(size_ratio - 0.1)
            
            distance_score = 1.0 / (1.0 + abs(horizontal_distance - self.target_distance))
          
            total_score = distance_score * 0.3 + center_score * 0.5 + size_score * 0.2
            
            if total_score > best_score:
                best_score = total_score
                best_detection = det
                best_detection['ground_point'] = ground_point
        
        return best_detection

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
            
            while not self.frame_queue.empty():
                try:
                    self.frame_queue.get_nowait()
                except:
                    break
                    
            try:
                self.frame_queue.put((frame, depth_frame), timeout=0.01)
            except:
                pass

    def process_frame(self):
        try:
            frame, depth_frame = self.frame_queue.get(timeout=0.1)
        except:
            return None, None, None
            
        self.depth_frame = depth_frame
        
        with torch.inference_mode():
            try:
                results = self.model(
                    frame,
                    conf=self.confidence_threshold,
                    classes=[self.pedestrian_class_id],
                    verbose=False,
                    agnostic_nms=True,
                    iou=0.5,
                    imgsz=self.infer_size,
                    device=self.device,
                    half=self.use_half
                )
            except Exception as e:
                if self.use_half:
                    print(f"FP16推理失败，切换FP32: {e}")
                    self.use_half = False
                    results = self.model(
                        frame,
                        conf=self.confidence_threshold,
                        classes=[self.pedestrian_class_id],
                        verbose=False,
                        agnostic_nms=True,
                        iou=0.5,
                        imgsz=self.infer_size,
                        device=self.device,
                        half=False
                    )
                else:
                    raise
       
        detections = []
        for result in results:
            if not hasattr(result, "boxes") or result.boxes is None:
                continue
                
            for box in result.boxes:
                xyxy = box.xyxy[0].tolist()
                x1, y1, x2, y2 = map(int, xyxy)
               
                if (x2 - x1) < 30 or (y2 - y1) < 60:
                    continue
                    
                x1 = max(0, x1)
                y1 = max(0, y1)
                x2 = min(self.frame_width - 1, x2)
                y2 = min(self.frame_height - 1, y2)
                
                center_x = (x1 + x2) // 2
                center_y = (y1 + y2) // 2
                
                detections.append({
                    'bbox': (x1, y1, x2, y2), 
                    'center_x': center_x, 
                    'center_y': center_y,
                    'confidence': box.conf[0].item()
                })
       
        best_target = self.select_best_target(detections, depth_frame)
        
        return best_target, frame, detections

    def run(self):
        """主运行循环"""
        print("开始改进版跟踪模式...")
        print(f"相机高度: {self.camera_height}m")
        print(f"目标距离: {self.target_distance}m")
        print(f"旋转灵敏度: {self.kp_turn}")
        print("按 Ctrl+C 停止")
        
        frame_center_x = self.frame_width // 2
        
        try:
            while not self.stop_event.is_set():
                start_time = time.time()
           
                target, frame, all_detections = self.process_frame()
                
                if target is not None and 'ground_point' in target:
                    ground_point = target['ground_point']
                    
                    vx, vy, omega = self.calculate_control(ground_point, target['center_x'], frame_center_x)
                   
                    self.send_robot_command(vx, vy, omega)
        
                    current_time = time.time()
                    if current_time - self.last_log_time > 1.0:
                        fps = self.frame_count / (current_time - self.last_log_time)
                        ground_x, ground_y, distance = ground_point
                        image_offset = (target['center_x'] - frame_center_x) / frame_center_x
                        print(f"FPS: {fps:.1f} | 距离: {distance:.2f}m | "
                              f"图像偏移: {image_offset:.2f} | "
                              f"速度: vx={vx:.2f}, vy={vy:.2f}, ω={omega:.2f}")
                        
                        self.frame_count = 0
                        self.last_log_time = current_time
                    
                    self.lost_track_count = 0
                else:
                    self.lost_track_count += 1
                    self.stop_robot()
                    
                    current_time = time.time()
                    if current_time - self.last_log_time > 2.0 and self.lost_track_count > 5:
                        print(f"未检测到目标 ({self.lost_track_count}帧)")
                        self.last_log_time = current_time
                
                self.frame_count += 1
                
                processing_time = time.time() - start_time
                if processing_time < 0.033:  # ~30fps
                    time.sleep(0.033 - processing_time)
                    
        except KeyboardInterrupt:
            print("\n接收到停止信号...")
        finally:
            self.stop_event.set()
            self.stop_robot()
            self.capture_thread.join(timeout=1)
            self.rs_pipe.stop()
            print("STOP")

if __name__ == "__main__":

    follower = ImprovedRobotFollower(
        network_interface="eth0",
        model_path='yolov8n.pt'
    )
    
    follower.run()