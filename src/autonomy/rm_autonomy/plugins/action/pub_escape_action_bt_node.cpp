// Copyright (c) 2019 Intel Corporation
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

#include <behaviortree_cpp/basic_types.h>
#include <behaviortree_ros2/bt_topic_pub_node.hpp>
#include <cmath>
#include <cstdlib>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include <rclcpp/logging.hpp>
#include <string>
#include <memory>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "nav2_util/robot_utils.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_util/node_utils.hpp"
#include "rm_autonomy/plugins/action/pub_escape_action_bt_node.hpp"
#include "geometry_msgs/msg/twist.hpp"


namespace rm_autonomy
{
PubEscapeAction::PubEscapeAction(const std::string & name, const BT::NodeConfig & config,const BT::RosNodeParams & params)
:RosTopicPubNode<geometry_msgs::msg::Twist>(name, config,params)
{
}

bool PubEscapeAction::setMessage(geometry_msgs::msg::Twist& msg)
{
  sensor_msgs::msg::LaserScan::SharedPtr scan_msg;
  getInput("scan_msg",scan_msg);
  setOutput("escape_stage", true);
  if (!scan_msg) {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Received empty LaserScan message.");
    return false;
  }
  if (scan_msg->ranges.empty()) {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "LaserScan message ranges is empty!");
    return false;  
  }
  float min_distance = 100;
    int min_index = -1;
    
    for (int i = 0; i < scan_msg->ranges.size(); i++) {
        if (scan_msg->ranges[i] < min_distance) {
            min_distance = scan_msg->ranges[i];
            min_index = i;
        }
    }

    // 计算障碍物相对于机器人的方向
    float angle_lidar_obstacle = scan_msg->angle_min + min_index * scan_msg->angle_increment;
    RCLCPP_INFO(logger_, "min distance=%f",min_distance);
    if(min_distance<=1.1)
    {
      msg.angular.z=-angle_lidar_obstacle/3;
      RCLCPP_INFO(logger_, "start_spining,angle=%f",angle_lidar_obstacle);
      if(std::abs(angle_lidar_obstacle)<=0.5)
      {
        msg.angular.z=0;
        msg.linear.x=-0.2;
        RCLCPP_INFO(logger_, "start_backup");
      }
      return true;
    }
    RCLCPP_INFO(logger_, "escape_end");
    msg.angular.z=0;
    setOutput("escape_stage", false);

    return true;
}

}
  // namespace nav2_behavior_tree

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubEscapeAction, "PubEscapeAction");

