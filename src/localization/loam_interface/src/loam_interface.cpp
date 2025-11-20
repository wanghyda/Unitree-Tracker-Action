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

#include "loam_interface/loam_interface.hpp"

#include "pcl_ros/transforms.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

namespace loam_interface
{
sensor_msgs::msg::PointCloud2 ConvertLivoxToPointCloud2(const livox_ros_driver2::msg::CustomMsg& livox_msg);
LoamInterfaceNode::LoamInterfaceNode(const rclcpp::NodeOptions & options)
: Node("loam_interface", options)
{
  this->declare_parameter<std::string>("state_estimation_topic", "");
  this->declare_parameter<std::string>("registered_scan_topic", "");
  // this->declare_parameter<std::string>("scan_topic_left", "");
  // this->declare_parameter<std::string>("scan_topic_right", "");
  this->declare_parameter<std::string>("odom_frame", "odom");
  this->declare_parameter<std::string>("base_frame", "");
  this->declare_parameter<std::string>("lidar_frame", "");
  // this->declare_parameter<std::string>("lidar_2_frame", "");

  this->get_parameter("state_estimation_topic", state_estimation_topic_);
  this->get_parameter("registered_scan_topic", registered_scan_topic_);
  // this->get_parameter("scan_topic_left", scan_topic_left);
  // this->get_parameter("scan_topic_right", scan_topic_right);
  this->get_parameter("odom_frame", odom_frame_);
  this->get_parameter("base_frame", base_frame_);
  this->get_parameter("lidar_frame", lidar_frame_);
  // this->get_parameter("lidar_2_frame", lidar_2_frame_);


  publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/base_link_full_pose", 10);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&LoamInterfaceNode::on_timer, this));
      
  base_frame_to_lidar_initialized_ = false;
  br_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

  tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
  tf_listener_ = std::make_unique<tf2_ros::TransformListener>(*tf_buffer_);

  pcd_pub_left_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("registered_scan", 10);
  odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("lidar_odometry", 5);
  // all_pcd_pub_=this->create_publisher<sensor_msgs::msg::PointCloud2>("base_scan_raw",10);

  // pcd_sub_left_ = this->create_subscription<livox_ros_driver2::msg::CustomMsg>(
  //   scan_topic_left, 5,
  //   std::bind(&LoamInterfaceNode::LeftpointCloudCallback, this, std::placeholders::_1));

  // pcd_sub_right_ = this->create_subscription<livox_ros_driver2::msg::CustomMsg>(
  // scan_topic_right, 5,
  // std::bind(&LoamInterfaceNode::RightpointCloudCallback, this, std::placeholders::_1));


  pcd_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
    registered_scan_topic_, 5,
    std::bind(&LoamInterfaceNode::pointCloudCallback, this, std::placeholders::_1));
  odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
    state_estimation_topic_, 5,
    std::bind(&LoamInterfaceNode::odometryCallback, this, std::placeholders::_1));
}

// void LoamInterfaceNode::LeftpointCloudCallback(const livox_ros_driver2::msg::CustomMsg::ConstSharedPtr msg)
// {
//   cloud1_ = std::make_shared<sensor_msgs::msg::PointCloud2>(ConvertLivoxToPointCloud2(*msg));
//   PublishAllpointCloud();
// }

// void LoamInterfaceNode::RightpointCloudCallback(const livox_ros_driver2::msg::CustomMsg::ConstSharedPtr msg)
// {
//   cloud2_ = std::make_shared<sensor_msgs::msg::PointCloud2>(ConvertLivoxToPointCloud2(*msg));
//   PublishAllpointCloud();
// }

// void LoamInterfaceNode::PublishAllpointCloud()
// {
//   if (!cloud1_ || !cloud2_)
//   {
//     // RCLCPP_WARN(this->get_logger(), "no cloud1_ or cloud2_");
//       return;
//   }
      

//   // 保证两个点云时间差不大
//   if (std::abs((rclcpp::Time(cloud1_->header.stamp) - rclcpp::Time(cloud2_->header.stamp)).seconds()) > 0.1)
//   {
//     RCLCPP_WARN(this->get_logger(), "two clouds' timestamp differs significantly:cloud1:%f,cloud2:%f", rclcpp::Time(cloud1_->header.stamp).seconds(),rclcpp::Time(cloud2_->header.stamp).seconds());
//       return;
//   }
    
//   sensor_msgs::msg::PointCloud2 cloud1_base, cloud2_base;

//   try {
//       auto tf1 = tf_buffer_->lookupTransform("base_link", lidar_1_frame_, cloud1_->header.stamp);
//       pcl_ros::transformPointCloud("base_link", tf1, *cloud1_, cloud1_base);

//       auto tf2 = tf_buffer_->lookupTransform("base_link", lidar_2_frame_, cloud2_->header.stamp);
//       pcl_ros::transformPointCloud("base_link", tf2, *cloud2_, cloud2_base);
//   } catch (tf2::TransformException &ex) {
//       RCLCPP_WARN(this->get_logger(), "TF transform failed: %s", ex.what());
//       return;
//   }

//   // 拼接点云（转换为 pcl::PointCloud，拼接后再转回 sensor_msgs）
//   pcl::PointCloud<pcl::PointXYZ> pcl1, pcl2, pcl_combined;
//   pcl::fromROSMsg(cloud1_base, pcl1);
//   pcl::fromROSMsg(cloud2_base, pcl2);

//   pcl_combined = pcl1 + pcl2;

//   sensor_msgs::msg::PointCloud2 fused_msg;
//   pcl::toROSMsg(pcl_combined, fused_msg);
//   fused_msg.header.frame_id = "base_link";
//   fused_msg.header.stamp = this->now();

//   all_pcd_pub_->publish(fused_msg);
//   // RCLCPP_INFO(this->get_logger(),"published base_link frame cloud");
//   // 清空缓存（避免重复发送）
//   cloud1_.reset();
//   cloud2_.reset();
// };
void LoamInterfaceNode::on_timer() {
  try {
    auto transformStamped = tf_buffer_->lookupTransform("map", "base_link", tf2::TimePointZero);
    
    // 平移
    current_pose.pose.position.x = transformStamped.transform.translation.x;
    current_pose.pose.position.y  = transformStamped.transform.translation.y;
    current_pose.pose.position.z  = transformStamped.transform.translation.z;

    // 四元数
    current_pose.pose.orientation.w  = transformStamped.transform.rotation.w;
    current_pose.pose.orientation.x = transformStamped.transform.rotation.x;
    current_pose.pose.orientation.y = transformStamped.transform.rotation.y;
    current_pose.pose.orientation.z= transformStamped.transform.rotation.z;

    // 欧拉角（从四元数转换）
    // tf2::Quaternion quat(qx, qy, qz, qw);
    // tf2::Matrix3x3 mat(quat);
    // double roll, pitch, yaw;
    // mat.getRPY(roll, pitch, yaw);

    
    // 构造字符串
    
    publisher_->publish(current_pose);
  } catch (const tf2::TransformException & ex) {
    RCLCPP_WARN(this->get_logger(), "Could not transform: %s", ex.what());
  }
}



void LoamInterfaceNode::pointCloudCallback(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msg)
{
  // NOTE: Input point cloud message is based on the `lidar_odom`
  // Here we transform it to the REAL `odom` frame
  auto out = std::make_shared<sensor_msgs::msg::PointCloud2>();
  pcl_ros::transformPointCloud(odom_frame_, tf_odom_to_lidar_odom_, *msg, *out);
  pcd_pub_left_->publish(*out);
}

void LoamInterfaceNode::odometryCallback(const nav_msgs::msg::Odometry::ConstSharedPtr msg)
{
  // NOTE: Input odometry message is based on the `lidar_odom`
  // Here we transform it to the `odom` frame
  if (!base_frame_to_lidar_initialized_) {
    try {
      auto tf_stamped_1 = tf_buffer_->lookupTransform(
        base_frame_, lidar_frame_, msg->header.stamp, rclcpp::Duration::from_seconds(0.5));
        tf2::Transform tf_base_frame_to_lidar;
        tf2::fromMsg(tf_stamped_1.transform, tf_base_frame_to_lidar);
      tf_odom_to_lidar_odom_ = tf_base_frame_to_lidar;
  
      base_frame_to_lidar_initialized_ = true;
    } catch (tf2::TransformException & ex) {
      RCLCPP_WARN(this->get_logger(), "TF lookup failed: %s Retrying...", ex.what());
      return;
    }
  }

  // Transform the odometry_msg (based lidar_odom) to the odom frame
  tf2::Transform tf_lidar_odom_to_lidar;
  tf2::fromMsg(msg->pose.pose, tf_lidar_odom_to_lidar);
  tf2::Transform tf_odom_to_lidar = tf_odom_to_lidar_odom_ * tf_lidar_odom_to_lidar;
 
  geometry_msgs::msg::TransformStamped transform_msg;
  transform_msg.header.stamp = msg->header.stamp;
  transform_msg.header.frame_id = odom_frame_;
  transform_msg.child_frame_id = lidar_frame_;
  transform_msg.transform = tf2::toMsg(tf_odom_to_lidar);
  br_->sendTransform(transform_msg);
}

// sensor_msgs::msg::PointCloud2 ConvertLivoxToPointCloud2(const livox_ros_driver2::msg::CustomMsg& livox_msg) {
//   sensor_msgs::msg::PointCloud2 cloud;
//   cloud.header = livox_msg.header;
//   cloud.height = 1;
//   cloud.width = livox_msg.point_num;
//   cloud.is_dense = false;
//   cloud.is_bigendian = false;

//   sensor_msgs::msg::PointField field;
//   field.count = 1;
//   field.datatype = sensor_msgs::msg::PointField::FLOAT32;

//   field.name = "x"; field.offset = 0;
//   cloud.fields.push_back(field);

//   field.name = "y"; field.offset = 4;
//   cloud.fields.push_back(field);

//   field.name = "z"; field.offset = 8;
//   cloud.fields.push_back(field);

//   field.name = "intensity"; field.offset = 12;
//   field.datatype = sensor_msgs::msg::PointField::UINT8;
//   cloud.fields.push_back(field);

//   cloud.point_step = 13;
//   cloud.row_step = cloud.point_step * cloud.width;
//   cloud.data.resize(cloud.row_step);

//   for (size_t i = 0; i < livox_msg.point_num; ++i) {
//     const auto& pt = livox_msg.points[i];
//     size_t offset = i * cloud.point_step;
//     memcpy(&cloud.data[offset + 0], &pt.x, sizeof(float));
//     memcpy(&cloud.data[offset + 4], &pt.y, sizeof(float));
//     memcpy(&cloud.data[offset + 8], &pt.z, sizeof(float));
//     memcpy(&cloud.data[offset + 12], &pt.reflectivity, sizeof(uint8_t));
//   }

//   return cloud;
// }

}  // namespace loam_interface

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(loam_interface::LoamInterfaceNode)
