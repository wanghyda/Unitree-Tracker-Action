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
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "rm_autonomy/plugins/action/pub_vel_bt_node.hpp"



namespace rm_autonomy
{
PubVelBTNode::PubVelBTNode(const std::string & name, const BT::NodeConfig & config,const BT::RosNodeParams & params)
:RosTopicPubNode<geometry_msgs::msg::Twist>(name, config,params)
{
}

bool PubVelBTNode::setMessage(geometry_msgs::msg::Twist& msg)
{
    float theta;
    float vel = 0.04;
    getInput("safe_direction",theta);
      msg.linear.x=-vel*cos(theta);
      msg.linear.y=-vel*sin(theta);
      msg.angular.z=0;
      RCLCPP_INFO(logger_, "Published");
      // RCLCPP_INFO(logger_, "start_spining,angle=%f",w);
      return true;

}

}
  // namespace nav2_behavior_tree

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubVelBTNode, "PubVelBTNode");

