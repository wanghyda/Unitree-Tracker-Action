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
#include <rclcpp/future_return_code.hpp>
#include <rclcpp/logging.hpp>
#include <string>
#include <memory>

#include "nav2_util/robot_utils.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_util/node_utils.hpp"
#include "rm_autonomy/plugins/action/localization_confirm_bt_node.hpp"

namespace rm_autonomy
{
LocalizationConfirmAs::LocalizationConfirmAs(const std::string & name, const BT::NodeConfig & config)
: BT::StatefulActionNode(name, config)
{
}

BT::NodeStatus LocalizationConfirmAs::onStart()
{
    return BT::NodeStatus::RUNNING;
}
void LocalizationConfirmAs::onHalted()
{
}

BT::NodeStatus LocalizationConfirmAs::onRunning()
{
    geometry_msgs::msg::TransformStamped current_location;
    getInput<geometry_msgs::msg::TransformStamped>("current_location",current_location);
   if(tick_times==0){
        last_position=current_location;
   }
    tick_times+=1;
    
    double dx_last = last_position.transform.translation.x - current_location.transform.translation.x;
    double dy_last = last_position.transform.translation.y - current_location.transform.translation.y;
   if(tick_times==100)
   {
      if(dx_last * dx_last + dy_last * dy_last <= 0.0025 )
      {
          tick_times=0;
          finished_time+=1;
          if(finished_time==5){
            finished_time=0;
            return BT::NodeStatus::SUCCESS;
          }
          RCLCPP_INFO(logger_, "Localization finished,distance=%f",dx_last * dx_last + dy_last * dy_last);
          return BT::NodeStatus::RUNNING;
      }else {
          tick_times=0;
          RCLCPP_INFO(logger_, "Localization running,distance=%f",dx_last * dx_last + dy_last * dy_last);
          return BT::NodeStatus::RUNNING;
      }
      
      
    }else{
                // RCLCPP_INFO(logger_, "Localization running,tick_times=%d",tick_times);
      return BT::NodeStatus::RUNNING;
    }
}

}  // namespace nav2_behavior_tree

#include "behaviortree_cpp/bt_factory.h"

BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::LocalizationConfirmAs>("LocalizationConfirmAs");
}

