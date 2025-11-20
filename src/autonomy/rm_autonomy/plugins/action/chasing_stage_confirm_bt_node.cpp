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
#include "rm_autonomy/plugins/action/chasing_stage_confirm_bt_node.hpp"

namespace rm_autonomy
{
ChasingStageConfirmAs::ChasingStageConfirmAs(const std::string & name, const BT::NodeConfig & config)
: BT::StatefulActionNode(name, config)
{
}

BT::NodeStatus ChasingStageConfirmAs::onStart()
{
    return BT::NodeStatus::RUNNING;
}
void ChasingStageConfirmAs::onHalted()
{
  RCLCPP_INFO(logger_, "Chasing Failed");
}

BT::NodeStatus ChasingStageConfirmAs::onRunning()
{
    bool chasing_confirm;
    getInput("chasing_stage",chasing_confirm);
    if(chasing_confirm)
    {
      RCLCPP_INFO(logger_, "Is Chasing");
        return BT::NodeStatus::SUCCESS;
    }else {
      RCLCPP_INFO(logger_, "Chasing Failed");
      return BT::NodeStatus::FAILURE;
    }
}

}  // namespace nav2_behavior_tree

#include "behaviortree_cpp/bt_factory.h"

BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::ChasingStageConfirmAs>("ChasingStageConfirmAs");
}

