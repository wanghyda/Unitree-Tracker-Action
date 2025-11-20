// Copyright 2025 Lihan Chen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LOAM_INTERFACE__LOAM_INTERFACE_HPP_
#define LOAM_INTERFACE__LOAM_INTERFACE_HPP_

#include <memory>
#include <string>


#include <geometry_msgs/msg/pose_stamped.hpp>
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "livox_ros_driver2/msg/custom_msg.hpp"
#include "tf2_ros/buffer.h"
#include <pcl_conversions/pcl_conversions.h>
#include <tf2_ros/transform_broadcaster.h>
#include "tf2_ros/transform_listener.h"
#include <std_msgs/msg/string.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

namespace loam_interface
{

class LoamInterfaceNode : public rclcpp::Node
{
public:
  explicit LoamInterfaceNode(const rclcpp::NodeOptions & options);

private:
  // void LeftpointCloudCallback(const livox_ros_driver2::msg::CustomMsg::ConstSharedPtr msg);
  // void RightpointCloudCallback(const livox_ros_driver2::msg::CustomMsg::ConstSharedPtr msg);
  // void PublishAllpointCloud();
  void pointCloudCallback(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msg);
  void on_timer();
  void odometryCallback(const nav_msgs::msg::Odometry::ConstSharedPtr msg);

  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pcd_sub_;
  // rclcpp::Subscription<livox_ros_driver2::msg::CustomMsg>::SharedPtr pcd_sub_left_;
  // rclcpp::Subscription<livox_ros_driver2::msg::CustomMsg>::SharedPtr pcd_sub_right_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;

  rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pcd_pub_left_;
  // rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pcd_pub_all_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
  // rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr all_pcd_pub_;

  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  std::unique_ptr<tf2_ros::TransformListener> tf_listener_;

  std::unique_ptr<tf2_ros::TransformBroadcaster> br_;
  
  std::string state_estimation_topic_;
  std::string registered_scan_topic_;
  std::string odom_frame_;
  std::string lidar_frame_;
  // std::string lidar_2_frame_;
  std::string base_frame_;
  // std::string scan_topic_left;
  // std::string scan_topic_right;
  geometry_msgs::msg::PoseStamped current_pose;
  bool base_frame_to_lidar_initialized_;
  tf2::Transform tf_odom_to_lidar_odom_;

  // sensor_msgs::msg::PointCloud2::SharedPtr cloud1_, cloud2_;
};

}  // namespace loam_interface

#endif  // LOAM_INTERFACE__LOAM_INTERFACE_HPP_
