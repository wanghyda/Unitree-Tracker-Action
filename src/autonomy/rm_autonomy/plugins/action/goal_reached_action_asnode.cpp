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

#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/basic_types.h>
#include <rclcpp/logging.hpp>
#include <string>
#include <memory>

#include "nav2_util/robot_utils.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_util/node_utils.hpp"
#include "rm_autonomy/plugins/action/goal_reached_action_asnode.hpp"

namespace rm_autonomy
{
GoalReachedActionAs::GoalReachedActionAs(const std::string & name, const BT::NodeConfig & config)
: BT::StatefulActionNode(name, config)
{
  tick_times=0;
}

BT::NodeStatus GoalReachedActionAs::onStart()
{
    return BT::NodeStatus::RUNNING;
}
void GoalReachedActionAs::onHalted()
{
  RCLCPP_INFO(logger_, "Navigation Failed");
}

BT::NodeStatus GoalReachedActionAs::onRunning()
{
  geometry_msgs::msg::TransformStamped current_pose;
  getInput("current_location",current_pose);

  tick_times+=1;
  getInput("goal_pose",goal);



  double dx = goal.pose.position.x - current_pose.transform.translation.x;
  double dy = goal.pose.position.y - current_pose.transform.translation.y;

  double dx_last = last_pose.transform.translation.x - current_pose.transform.translation.x;
  double dy_last = last_pose.transform.translation.y - current_pose.transform.translation.y;
RCLCPP_INFO(logger_, "distance=%f",dx*dx+dy*dy);

  if(dx*dx+dy*dy<0.0025)
  {
    tick_times=0;
   RCLCPP_INFO(logger_, "Navigation Finished,");
  return BT::NodeStatus::SUCCESS;
  }

   if(tick_times>=10)
   {
      if(dx_last * dx_last + dy_last * dy_last <= 0.09 )
      {
          last_pose=current_pose;
          tick_times=0;
            RCLCPP_INFO(logger_, "start to backup");
          return BT::NodeStatus::FAILURE;
      }else {
          last_pose=current_pose;
          tick_times=0;
          return BT::NodeStatus::RUNNING;
      }
      
      
    }else{
      return BT::NodeStatus::RUNNING;
    }
   
}

}  // namespace nav2_behavior_tree

#include "behaviortree_cpp/bt_factory.h"

BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::GoalReachedActionAs>("GoalReachedActionAs");
}

