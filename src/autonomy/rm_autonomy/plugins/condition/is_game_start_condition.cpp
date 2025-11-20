#include "rm_autonomy/plugins/condition/is_game_start_condition.hpp"

namespace rm_autonomy
{

IsGameStartCondition::IsGameStartCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsGameStartCondition::checkGameStart, this), config)
{
}

BT::NodeStatus IsGameStartCondition::checkGameStart()
{
  auto msg = getInput<rm_autonomy_interfaces::msg::GameStatus>("message");
  if (!msg) {
    std::cout << "missing required input [game_status]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  std::unordered_map<int, std::string> game_status_map = {
    {0, "Not Begginning"}, {1, "Preparing"},    {2, "15s Checking"},
    {3, "5 seconds counting"}, {4, "Competition Begin!"}, {5, "Competition End!"},
  };

  if (game_status_map.find(msg->stage_progress) != game_status_map.end()) {
    return (msg->stage_progress == 4) ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
  } else {
    std::cout << "Unknown Status" << '\n';
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsGameStartCondition>("IsGameStartCondition");
}
