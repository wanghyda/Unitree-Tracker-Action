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
#include "rm_autonomy/plugins/action/situation_judgement_action_bt_node.hpp"

namespace rm_autonomy
{
SituationJudgementActionBTNode::SituationJudgementActionBTNode(
  const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
}

BT::NodeStatus SituationJudgementActionBTNode::tick()
{
  rm_autonomy_interfaces::msg::AllRobotHP all_robot_hp;
  getInput("all_robot_hp",all_robot_hp);
  rm_autonomy_interfaces::msg::SelfState self_state;
  getInput("self_state",self_state);
  rm_autonomy_interfaces::msg::GameStatus game_status;
  getInput("game_status",game_status);
  rm_autonomy_interfaces::msg::AllyRobotPosition ally_robot_position;
  getInput("ally_robot_position",ally_robot_position);
  setOutput("hero_y",ally_robot_position.ally_1_position_y);
  setOutput("blue_outpost_hp",all_robot_hp.blue_outpost_hp);
  setOutput("blue_base_hp",all_robot_hp.blue_base_hp);
  setOutput("red_outpost_hp",all_robot_hp.red_outpost_hp);
  setOutput("red_base_hp",all_robot_hp.red_base_hp);
  setOutput("remain_time",game_status.stage_remain_time);
  setOutput("energy_left",self_state.energy_left);
  setOutput("self_hp",self_state.current_hp);




  return BT::NodeStatus::SUCCESS;
}


}  // namespace nav2_behavior_tree

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::SituationJudgementActionBTNode>("SituationJudgementActionBTNode");
}

