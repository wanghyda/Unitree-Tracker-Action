#include "rm_autonomy/plugins/condition/remain_game_time_condition.hpp"

namespace rm_autonomy
{

RemainGameTimeCondition::RemainGameTimeCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&RemainGameTimeCondition::checkGameStatus, this), config)
{
}

BT::NodeStatus RemainGameTimeCondition::checkGameStatus()
{
  int time_threshold;
  auto msg = getInput<rm_autonomy_interfaces::msg::GameStatus>("message");
  getInput("time_threshold", time_threshold);

  if (!msg) {
    std::cout << "missing required input [time_thredshold]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (msg->stage_remain_time < time_threshold) {
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::RemainGameTimeCondition>("RemainGameTimeCondition");
}
