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

#include <string>
#include <memory>

#include "nav2_util/robot_utils.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_util/node_utils.hpp"
#include "rm_autonomy/plugins/action/goal_reached_action.hpp"

namespace rm_autonomy
{
GoalReachedAction::GoalReachedAction(
  const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
  auto node = std::make_shared<rclcpp::Node>("get_current_location_action_action_bt_node");
  if (!node) {
    throw std::runtime_error("Failed to create node 'get_current_location_action_bt_node'");
  }

  auto clock = node->get_clock();
  tf2::Duration buffer_duration(tf2::durationFromSec(10.0));
  tf_buffer_ = std::make_shared<tf2_ros::Buffer>(clock, buffer_duration, node);
  if (!tf_buffer_) {
    throw std::runtime_error("Failed to create tf2_ros::Buffer");
  }

  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
  if (!tf_listener_) {
    throw std::runtime_error("Failed to create tf2_ros::TransformListener");
  }

}

BT::NodeStatus GoalReachedAction::tick()
{
  geometry_msgs::msg::TransformStamped current_pose;
   
  current_pose= tf_buffer_->lookupTransform("map", "base_link", tf2::TimePointZero);
  

  geometry_msgs::msg::PoseStamped goal;
  getInput("goal_pose",goal);
  



  double dx = goal.pose.position.x - current_pose.transform.translation.x;
  double dy = goal.pose.position.y - current_pose.transform.translation.y;

   
  while ((dx * dx + dy * dy) >= (0.1 * 0.1)) {
    RCLCPP_INFO(logger_, "distance^2:%f",dx * dx + dy * dy);
    current_pose= tf_buffer_->lookupTransform("map", "base_link", tf2::TimePointZero);
    dx = goal.pose.position.x - current_pose.transform.translation.x;
    dy = goal.pose.position.y - current_pose.transform.translation.y;
    
  }
  RCLCPP_INFO(logger_, "goal is reached");
  return BT::NodeStatus::SUCCESS;
}


}  // namespace nav2_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::GoalReachedAction>("GoalReachedAction");
}

