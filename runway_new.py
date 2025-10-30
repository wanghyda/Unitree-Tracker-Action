#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
白线分割跑道跟踪系统（两阶段跟踪）
核心思路：
1. 【初始阶段】检测画面中的白色线条（高亮度、低饱和度）
2. 【初始阶段】识别白线之间的跑道区域（两条白线围成的空间）
3. 【初始阶段】鼠标点击选择要跟踪的跑道
4. 【锁定阶段】切换到红色跑道区域分割，持续跟踪跑道中心线
5. 【抗干扰】锁定后不再依赖白线，即使白线插入/并道也能稳定跟踪

用法：
  python runway_new.py --video runway.mp4

交互：
  鼠标左键：点击锁定跑道
  u键：解除锁定
  +/-键：调整白线检测阈值
  [/]键：调整红色饱和度阈值
  d键：切换调试模式（显示红色掩膜）
  w键：切换白线掩膜显示（未锁定时）
  q键：退出
"""

import cv2
import numpy as np
import argparse
from dataclasses import dataclass
import time
from collections import deque

@dataclass
class TrackState:
    lateral_offset_m: float = 0.0
    heading_error_deg: float = 0.0
    timestamp: float = 0.0
    valid: bool = False

class LaneTracker:
    def __init__(self, track_width_m=2.44, white_thresh=180, debug=False):
        self.track_width_m = track_width_m
        self.white_thresh = white_thresh
        self.debug = debug

        self.locked = False
        self.lock_left_line = None
        self.lock_right_line = None
        self.lock_center = None
        self.lock_runway_mask = None
        self.lock_runway_bbox = None
        self.lock_lane_mask = None
        self.loss_count = 0
        self.loss_max = 15

        self.red_sat_thresh = 100
        self.lane_candidates = []
        self.smoothing = 0.7
        self.prev_state = None
        self.center_line_history = deque(maxlen=5)

    def set_threshold(self, thresh):
        self.white_thresh = max(0, min(255, thresh))
        print(f"白线阈值: {self.white_thresh}")

    def set_red_threshold(self, thresh):
        self.red_sat_thresh = max(50, min(200, thresh))
        print(f"红色饱和度阈值: {self.red_sat_thresh}")

    def unlock(self):
        self.locked = False
        self.lock_left_line = None
        self.lock_right_line = None
        self.lock_center = None
        self.lock_runway_mask = None
        self.lock_runway_bbox = None
        self.lock_lane_mask = None
        self.loss_count = 0
        self.center_line_history.clear()
        print("解除锁定")

    def _detect_white_lines(self, frame):
        h, w = frame.shape[:2]
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        h_ch, s_ch, v_ch = cv2.split(hsv)
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        high_value = (v_ch > self.white_thresh).astype(np.uint8) * 255
        low_sat = (s_ch < 60).astype(np.uint8) * 255
        white_mask_hsv = cv2.bitwise_and(high_value, low_sat)
        _, white_mask_gray = cv2.threshold(gray, self.white_thresh, 255, cv2.THRESH_BINARY)
        white_mask = cv2.bitwise_or(white_mask_hsv, white_mask_gray)
        edges = cv2.Canny(gray, 50, 150)
        kernel_edge = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        edges_dilated = cv2.dilate(edges, kernel_edge, iterations=1)
        white_mask = cv2.bitwise_or(white_mask, edges_dilated)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 15))
        white_mask = cv2.morphologyEx(white_mask, cv2.MORPH_CLOSE, kernel, iterations=2)
        white_mask = cv2.morphologyEx(white_mask, cv2.MORPH_OPEN, kernel, iterations=1)
        return white_mask

    def _extract_line_contours(self, white_mask):
        h, w = white_mask.shape
        contours, _ = cv2.findContours(white_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        lines = []
        for cnt in contours:
            area = cv2.contourArea(cnt)
            if area < 100:
                continue
            x, y, bw, bh = cv2.boundingRect(cnt)
            if bh < h * 0.2:
                continue
            M = cv2.moments(cnt)
            if M['m00'] > 0:
                cx = int(M['m10'] / M['m00'])
                cy = int(M['m01'] / M['m00'])
            else:
                cx, cy = x + bw // 2, y + bh // 2
            line_pts = []
            for row_y in range(y, y + bh, 5):
                if row_y >= h:
                    break
                row_indices = np.where(white_mask[row_y, x:x+bw] > 0)[0]
                if row_indices.size > 0:
                    cx_row = x + (row_indices[0] + row_indices[-1]) // 2
                    line_pts.append((cx_row, row_y))
            if len(line_pts) < 10:
                continue
            lines.append({
                'contour': cnt,
                'bbox': (x, y, bw, bh),
                'center': (cx, cy),
                'points': line_pts,
                'area': area
            })
        lines.sort(key=lambda ln: ln['center'][0])
        return lines

    def _extract_lane_candidates(self, lines, frame_shape):
        h, w = frame_shape[:2]
        candidates = []
        if len(lines) < 2:
            return candidates
        for i in range(len(lines) - 1):
            left_line = lines[i]
            right_line = lines[i + 1]
            lane_width = right_line['center'][0] - left_line['center'][0]
            if lane_width < w * 0.05 or lane_width > w * 0.6:
                continue
            lane_cx = (left_line['center'][0] + right_line['center'][0]) // 2
            lane_cy = (left_line['center'][1] + right_line['center'][1]) // 2
            center_pts = []
            left_pts_dict = {pt[1]: pt[0] for pt in left_line['points']}
            right_pts_dict = {pt[1]: pt[0] for pt in right_line['points']}
            for y in sorted(set(left_pts_dict.keys()) & set(right_pts_dict.keys())):
                x_left = left_pts_dict[y]
                x_right = right_pts_dict[y]
                x_center = (x_left + x_right) // 2
                center_pts.append((x_center, y))
            if len(center_pts) < 10:
                continue
            candidates.append({
                'id': i,
                'left_line': left_line,
                'right_line': right_line,
                'center': (lane_cx, lane_cy),
                'width': lane_width,
                'center_pts': center_pts
            })
        return candidates

    def _compute_control(self, runway_mask, runway_contour, h, w):
        if runway_mask is None or runway_contour is None:
            return None
        bbox = cv2.boundingRect(runway_contour)
        x, y, bw, bh = bbox
        center_pts = []
        for row_y in range(y, y + bh, 5):
            if row_y >= h:
                break
            row_indices = np.where(runway_mask[row_y, :] > 0)[0]
            if row_indices.size > 0:
                cx_row = (row_indices[0] + row_indices[-1]) // 2
                center_pts.append((cx_row, row_y))
        if len(center_pts) < 10:
            return None
        pts = np.array(center_pts)
        ys = pts[:, 1].astype(np.float32)
        xs = pts[:, 0].astype(np.float32)
        weights = (ys / h) ** 2 + 0.3
        W = np.diag(weights)
        A = np.vstack([ys, np.ones_like(ys)]).T
        try:
            AtW = A.T @ W
            a, b = np.linalg.inv(AtW @ A) @ (AtW @ xs)
        except:
            a, b = np.linalg.lstsq(A, xs, rcond=None)[0]
        if len(self.center_line_history) > 0:
            hist_a = np.mean([h[0] for h in self.center_line_history])
            hist_b = np.mean([h[1] for h in self.center_line_history])
            temporal_smoothing = 0.6
            a = a * (1 - temporal_smoothing) + hist_a * temporal_smoothing
            b = b * (1 - temporal_smoothing) + hist_b * temporal_smoothing
        self.center_line_history.append((a, b))
        y_ref = h - 10
        x_center = a * y_ref + b
        image_center_x = w / 2
        lateral_offset_px = x_center - image_center_x
        track_width_px = bw
        meters_per_pixel = self.track_width_m / max(track_width_px, 1)
        lateral_offset_m = lateral_offset_px * meters_per_pixel
        heading_deg = np.degrees(np.arctan(a))
        if self.prev_state and self.prev_state.valid:
            lateral_offset_m = self.prev_state.lateral_offset_m * self.smoothing + \
                               lateral_offset_m * (1 - self.smoothing)
            heading_deg = self.prev_state.heading_error_deg * self.smoothing + \
                          heading_deg * (1 - self.smoothing)
        state = TrackState(
            lateral_offset_m=lateral_offset_m,
            heading_error_deg=heading_deg,
            timestamp=time.time(),
            valid=True
        )
        self.prev_state = state
        return state, (a, b, y_ref, x_center, center_pts)

    def _draw_candidate(self, vis, candidate, color, selected=False):
        left_line = candidate['left_line']
        right_line = candidate['right_line']
        cv2.drawContours(vis, [left_line['contour']], -1, color, 2 if not selected else 3)
        cv2.drawContours(vis, [right_line['contour']], -1, color, 2 if not selected else 3)
        cx, cy = candidate['center']
        label = f"Lane #{candidate['id']}"
        cv2.putText(vis, label, (cx - 30, cy),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7 if selected else 0.5,
                    color, 2 if selected else 1)
        cv2.circle(vis, (cx, cy), 6 if selected else 4, color, -1)

    def _draw_tracking(self, vis, fit_params, runway_mask=None):
        h, w = vis.shape[:2]
        a, b, y_ref, x_center, center_pts = fit_params
        if runway_mask is not None:
            colored_mask = np.zeros_like(vis)
            colored_mask[runway_mask > 0] = (0, 100, 255)
            vis = cv2.addWeighted(vis, 0.7, colored_mask, 0.3, 0)
            if self.debug:
                if self.lock_lane_mask is not None:
                    lane_contours, _ = cv2.findContours(self.lock_lane_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
                    if lane_contours:
                        cv2.drawContours(vis, lane_contours, -1, (0, 255, 0), 2)
                        cv2.putText(vis, "Lane Constraint", (10, 90),
                                   cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                if self.lock_runway_bbox is not None:
                    x, y, bw, bh = self.lock_runway_bbox
                    cv2.rectangle(vis, (x, y), (x + bw, y + bh), (255, 0, 255), 2)
                    cv2.putText(vis, "Red Region", (x, y - 10),
                               cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        if center_pts:
            for pt in center_pts:
                cv2.circle(vis, tuple(pt), 2, (255, 255, 0), -1)
        y_top = h // 2
        x_top = int(a * y_top + b)
        cv2.line(vis, (int(x_center), int(y_ref)), (x_top, y_top), (0, 255, 0), 3)
        cv2.circle(vis, (int(x_center), int(y_ref)), 8, (0, 0, 255), -1)
        cv2.line(vis, (w // 2, h), (w // 2, h - 60), (255, 255, 255), 2)
        return vis

    def _detect_red_runway(self, frame, lane_constraint_mask=None):
        h, w = frame.shape[:2]
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        h_ch, s_ch, v_ch = cv2.split(hsv)
        white_mask = ((v_ch > 180) & (s_ch < 60)).astype(np.uint8) * 255
        kernel_white = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))
        white_mask_dilated = cv2.dilate(white_mask, kernel_white, iterations=2)
        lower_red1 = np.array([0, self.red_sat_thresh, 50])
        upper_red1 = np.array([10, 255, 240])
        lower_red2 = np.array([170, self.red_sat_thresh, 50])
        upper_red2 = np.array([180, 255, 240])
        mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
        mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
        red_mask = cv2.bitwise_or(mask1, mask2)
        red_mask = cv2.subtract(red_mask, white_mask_dilated)
        if lane_constraint_mask is not None:
            red_mask = cv2.bitwise_and(red_mask, lane_constraint_mask)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (7, 7))
        red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_CLOSE, kernel, iterations=3)
        red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_OPEN, kernel, iterations=2)
        contours, _ = cv2.findContours(red_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if not contours:
            return None, None
        best_contour = None
        best_score = -1
        for cnt in contours:
            area = cv2.contourArea(cnt)
            min_area = 1000 if lane_constraint_mask is None else 500
            if area < min_area:
                continue
            x, y, bw, bh = cv2.boundingRect(cnt)
            aspect_ratio = bh / (bw + 1e-6)
            bbox_area = bw * bh
            fullness = area / (bbox_area + 1e-6)
            perimeter = cv2.arcLength(cnt, True)
            compactness = (perimeter ** 2) / (area + 1e-6)
            score = 0
            score += np.log(area + 1) * 0.3
            if aspect_ratio > 1.5:
                score += aspect_ratio * 2.0
            else:
                score -= 2.0
            if fullness > 0.4:
                score += fullness * 3.0
            else:
                score -= 1.0
            if compactness < 50:
                score += 2.0
            if self.center_line_history and lane_constraint_mask is not None:
                M = cv2.moments(cnt)
                if M['m00'] > 0:
                    cx = M['m10'] / M['m00']
                    cy = M['m01'] / M['m00']
                    a_hist, b_hist = self.center_line_history[-1]
                    expected_x = a_hist * cy + b_hist
                    dist_to_history = abs(cx - expected_x)
                    if dist_to_history < 20:
                        score += 3.0
                    elif dist_to_history < 40:
                        score += 1.0
                    else:
                        score -= 1.0
            if score > best_score:
                best_score = score
                best_contour = cnt
        if best_contour is None:
            return None, None
        area = cv2.contourArea(best_contour)
        min_area = 1000 if lane_constraint_mask is None else 500
        if area < min_area:
            return None, None
        if lane_constraint_mask is not None:
            x, y, bw, bh = cv2.boundingRect(best_contour)
            aspect_ratio = bh / (bw + 1e-6)
            if aspect_ratio < 1.3:
                if self.debug:
                    print(f"  [DEBUG] 形状不符合跑道特征: aspect_ratio={aspect_ratio:.2f}")
                return None, None
        final_mask = np.zeros((h, w), dtype=np.uint8)
        cv2.drawContours(final_mask, [best_contour], -1, 255, -1)
        return final_mask, best_contour

    def _extract_runway_region(self, frame, candidate):
        h, w = frame.shape[:2]
        lane_mask = np.zeros((h, w), dtype=np.uint8)
        left_line = candidate['left_line']
        right_line = candidate['right_line']
        left_pts = np.array(left_line['points'])
        right_pts = np.array(right_line['points'])
        left_pts_sorted = left_pts[np.argsort(left_pts[:, 1])]
        right_pts_sorted = right_pts[np.argsort(right_pts[:, 1])][::-1]
        polygon = np.vstack([left_pts_sorted, right_pts_sorted])
        cv2.fillPoly(lane_mask, [polygon], 255)
        lane_area = cv2.countNonZero(lane_mask)
        print(f"  [DEBUG] 白线区域面积: {lane_area}")
        runway_mask, runway_contour = self._detect_red_runway(frame, lane_constraint_mask=lane_mask)
        if runway_mask is None:
            print("  [DEBUG] 白线之间未检测到红色区域")
            print("  [提示] 可能原因：")
            print("         1. 跑道不是红色")
            print("         2. 光照太暗")
            print("         3. 白线检测不准确\n")
            return None, None, None
        area = cv2.contourArea(runway_contour)
        area_ratio = area / (lane_area + 1e-6)
        print(f"  [DEBUG] 红色区域面积: {area:.0f}, 占比: {area_ratio*100:.1f}%")
        if area_ratio < 0.3:
            print(f"  [DEBUG] 红色区域占比太小 ({area_ratio*100:.1f}% < 30%)")
            print("  [提示] 跑道可能不是红色，或者白线检测范围过大\n")
            return None, None, None
        x, y, bw, bh = cv2.boundingRect(runway_contour)
        bbox_area = bw * bh
        fullness = area / (bbox_area + 1e-6)
        print(f"  [DEBUG] 边界框: ({x},{y},{bw},{bh}), 填充度: {fullness*100:.1f}%")
        if fullness < 0.4:
            print(f"  [DEBUG] 填充度太低 ({fullness*100:.1f}% < 40%)")
            print("  [提示] 检测到的区域不连续，可能有干扰\n")
            return None, None, None
        print(f"  [DEBUG] ✓ 成功提取红色跑道区域\n")
        return runway_mask, (x, y, bw, bh), lane_mask

    def process(self, frame):
        h, w = frame.shape[:2]
        vis = frame.copy()
        state = TrackState(valid=False)
        fit_params = None
        if self.locked:
            runway_mask, runway_contour = self._detect_red_runway(
                frame, 
                lane_constraint_mask=self.lock_lane_mask
            )
            if runway_mask is not None and runway_contour is not None:
                self.lock_runway_bbox = cv2.boundingRect(runway_contour)
                self.lock_runway_mask = runway_mask
                self.loss_count = max(0, self.loss_count - 1)
                result = self._compute_control(runway_mask, runway_contour, h, w)
                if result:
                    state, fit_params = result
                    vis = self._draw_tracking(vis, fit_params, runway_mask)
                    cv2.putText(vis, f"LOCKED (Red Runway Tracking) | Loss: {self.loss_count}/{self.loss_max}",
                                (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                    cv2.putText(vis, f"Offset: {state.lateral_offset_m:+.2f}m | Heading: {state.heading_error_deg:+.1f}deg",
                                (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 2)
            else:
                self.loss_count += 1
                cv2.putText(vis, f"LOST | {self.loss_count}/{self.loss_max}",
                            (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
                if self.loss_count > self.loss_max:
                    self.unlock()
        else:
            white_mask = self._detect_white_lines(frame)
            lines = self._extract_line_contours(white_mask)
            self.lane_candidates = self._extract_lane_candidates(lines, frame.shape)
            if self.debug:
                vis_mask = cv2.cvtColor(white_mask, cv2.COLOR_GRAY2BGR)
                vis = cv2.addWeighted(vis, 0.7, vis_mask, 0.3, 0)
            if self.lane_candidates:
                palette = [(255, 0, 0), (0, 128, 255), (255, 0, 255), (0, 255, 255),
                           (255, 255, 0), (0, 255, 128), (128, 0, 255), (128, 255, 0)]
                for cand in self.lane_candidates:
                    color = palette[cand['id'] % len(palette)]
                    self._draw_candidate(vis, cand, color)
                cv2.putText(vis, f"{len(self.lane_candidates)} lanes detected | Click to lock",
                            (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv2.putText(vis, f"{len(lines)} white lines found",
                            (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (200, 200, 200), 2)
            else:
                cv2.putText(vis, f"{len(lines)} white lines | No lanes detected | Adjust threshold (+/-)",
                            (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
        cv2.putText(vis, f"White Thresh: {self.white_thresh}", (10, h - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
        return vis, state

    def on_click(self, x, y, frame):
        if self.locked:
            return
        for cand in self.lane_candidates:
            cx, cy = cand['center']
            left_x = cand['left_line']['center'][0]
            right_x = cand['right_line']['center'][0]
            if left_x <= x <= right_x:
                left_bbox = cand['left_line']['bbox']
                right_bbox = cand['right_line']['bbox']
                y_min = min(left_bbox[1], right_bbox[1])
                y_max = max(left_bbox[1] + left_bbox[3], right_bbox[1] + right_bbox[3])
                if y_min <= y <= y_max:
                    print(f"\n尝试锁定 Lane #{cand['id']}...")
                    print(f"  白线位置: 左={left_x}, 右={right_x}, 宽度={right_x - left_x}")
                    runway_mask, runway_bbox, lane_mask = self._extract_runway_region(frame, cand)
                    if runway_mask is None:
                        print("✗ 无法在选定区域检测到红色跑道")
                        print("  提示：确保跑道是红色的，且在两条白线之间\n")
                        return
                    self.locked = True
                    self.lock_left_line = cand['left_line']
                    self.lock_right_line = cand['right_line']
                    self.lock_center = cand['center']
                    self.lock_runway_mask = runway_mask
                    self.lock_runway_bbox = runway_bbox
                    self.lock_lane_mask = lane_mask
                    self.loss_count = 0
                    print(f"✓ 成功锁定 Lane #{cand['id']} - 已切换到红色跑道跟踪模式")
                    print(f"  跟踪将严格限制在初始选定区域内\n")
                    return
        print("✗ Click inside a lane to lock")

def main():
    parser = argparse.ArgumentParser(description='白线分割跑道跟踪系统')
    parser.add_argument('--video', type=str, default='runway.mp4', help='视频文件路径')
    parser.add_argument('--camera', type=int, help='摄像头索引')
    parser.add_argument('--track-width', type=float, default=2.44, help='跑道宽度(米)')
    parser.add_argument('--thresh', type=int, default=180, help='白线亮度阈值(0-255)')
    parser.add_argument('--resize', type=int, default=960, help='处理宽度')
    parser.add_argument('--write', type=str, help='输出文件路径')
    parser.add_argument('--debug', action='store_true', help='调试模式（显示搜索区域）')
    args = parser.parse_args()

    if args.camera is not None:
        cap = cv2.VideoCapture(args.camera)
    else:
        cap = cv2.VideoCapture(args.video)

    if not cap.isOpened():
        print('✗ 无法打开视频/摄像头')
        return

    tracker = LaneTracker(track_width_m=args.track_width, white_thresh=args.thresh, debug=args.debug)
    fps_video = cap.get(cv2.CAP_PROP_FPS)
    delay = int(1000 / fps_video) if fps_video > 0 else 33
    fps_deque = deque(maxlen=30)
    current_frame = [None]

    def mouse_callback(event, x, y, flags, param):
        if event == cv2.EVENT_LBUTTONDOWN and current_frame[0] is not None:
            tracker.on_click(x, y, current_frame[0])

    cv2.namedWindow('Lane Tracker', cv2.WINDOW_NORMAL)
    cv2.setMouseCallback('Lane Tracker', mouse_callback)

    output_file = None
    if args.write:
        output_file = open(args.write, 'w')
        output_file.write("timestamp,lateral_offset_m,heading_error_deg,valid\n")

    print("\n=== 白线分割跑道跟踪系统 ===")
    print("操作说明:")
    print("  鼠标左键: 点击跑道区域锁定")
    print("  u键: 解除锁定")
    print("  +/-键: 增加/减少白线检测阈值")
    print("  [/]键: 增加/减少红色饱和度阈值")
    print("  d键: 切换调试模式（显示红色掩膜）")
    print("  w键: 切换白线掩膜显示（未锁定时）")
    print("  q键: 退出")
    print("\n跟踪策略:")
    print("  未锁定: 使用白线检测识别跑道")
    print("  已锁定: 切换到红色跑道区域跟踪（抗白线干扰）")
    print("\n抗干扰优化:")
    print("  ✓ 自动排除白色区域（白线并道时不影响红色检测）")
    print("  ✓ 智能区域选择（优先选择符合跑道形状的区域）")
    print("  ✓ 时序平滑（结合历史5帧的中心线，减少跳变）")
    print("  ✓ 多层次平滑（中心线+输出双重平滑）")
    print("\n提示:")
    print("  - 如果白线检测不准，用+/-键调整阈值")
    print("  - 如果红色检测不准，用[/]键调整饱和度")
    print("  - 按w键查看白线检测结果（白色区域）")
    print("  - 按d键查看红色检测结果（蓝色=白线干扰）")
    print("===========================\n")

    show_debug = args.debug
    debug_window_created = False

    while True:
        ret, frame = cap.read()
        if not ret:
            break
        if args.resize > 0:
            h, w = frame.shape[:2]
            scale = args.resize / w
            frame = cv2.resize(frame, (args.resize, int(h * scale)))
        current_frame[0] = frame.copy()
        t0 = time.time()
        vis, state = tracker.process(frame)
        fps = 1.0 / (time.time() - t0 + 1e-6)
        fps_deque.append(fps)
        avg_fps = sum(fps_deque) / len(fps_deque)
        cv2.putText(vis, f"FPS: {avg_fps:.1f}", (10, vis.shape[0] - 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
        if show_debug and tracker.locked and tracker.lock_runway_mask is not None:
            if not debug_window_created:
                cv2.namedWindow('Debug: Red Mask', cv2.WINDOW_NORMAL)
                debug_window_created = True
            debug_vis = np.zeros_like(frame)
            hsv_debug = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h_ch, s_ch, v_ch = cv2.split(hsv_debug)
            white_mask_debug = ((v_ch > 180) & (s_ch < 60)).astype(np.uint8) * 255
            kernel_white = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))
            white_mask_dilated = cv2.dilate(white_mask_debug, kernel_white, iterations=2)
            if tracker.lock_lane_mask is not None:
                debug_vis[tracker.lock_lane_mask > 0] = (0, 255, 0)
            if tracker.lock_runway_mask is not None:
                debug_vis[tracker.lock_runway_mask > 0] = (0, 0, 255)
            if tracker.lock_lane_mask is not None:
                white_in_lane = cv2.bitwise_and(white_mask_dilated, tracker.lock_lane_mask)
                debug_vis[white_in_lane > 0] = (255, 0, 0)
            if tracker.lock_runway_bbox is not None:
                x, y, bw, bh = tracker.lock_runway_bbox
                cv2.rectangle(debug_vis, (x, y), (x + bw, y + bh), (255, 255, 0), 2)
                cv2.putText(debug_vis, f"Red Region: {bw}x{bh}", (x, y - 10),
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 0), 2)
            legend_y = 30
            cv2.putText(debug_vis, "Green: Lane Constraint", (10, legend_y),
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            legend_y += 25
            cv2.putText(debug_vis, "Red: Detected Runway", (10, legend_y),
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
            legend_y += 25
            cv2.putText(debug_vis, "Blue: White Line Interference", (10, legend_y),
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
            legend_y += 25
            if len(tracker.center_line_history) > 0:
                cv2.putText(debug_vis, f"History Frames: {len(tracker.center_line_history)}", (10, legend_y),
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
            cv2.imshow('Debug: Red Mask', debug_vis)
        elif debug_window_created and not show_debug:
            cv2.destroyWindow('Debug: Red Mask')
            debug_window_created = False
        if output_file and state.valid:
            output_file.write(f"{state.timestamp:.3f},{state.lateral_offset_m:.3f},"
                              f"{state.heading_error_deg:.3f},{int(state.valid)}\n")
            output_file.flush()
        cv2.imshow('Lane Tracker', vis)
        key = cv2.waitKey(delay) & 0xFF
        if key == ord('q'):
            break
        elif key == ord('u'):
            tracker.unlock()
        elif key == ord('+') or key == ord('='):
            tracker.set_threshold(tracker.white_thresh + 5)
        elif key == ord('-') or key == ord('_'):
            tracker.set_threshold(tracker.white_thresh - 5)
        elif key == ord('['):
            tracker.set_red_threshold(tracker.red_sat_thresh - 10)
        elif key == ord(']'):
            tracker.set_red_threshold(tracker.red_sat_thresh + 10)
        elif key == ord('d'):
            show_debug = not show_debug
            print(f"调试模式: {'开启' if show_debug else '关闭'}")
        elif key == ord('w'):
            tracker.debug = not tracker.debug
            print(f"白线掩膜显示: {'开启' if tracker.debug else '关闭'}")
    cap.release()
    if output_file:
        output_file.close()
    cv2.destroyAllWindows()
    print("\n✓ 跟踪结束")

if __name__ == '__main__':
    main()