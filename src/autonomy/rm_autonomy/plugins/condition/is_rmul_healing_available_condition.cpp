#include "rm_autonomy/plugins/condition/is_rmul_healing_available_condition.hpp"

namespace rm_autonomy
{

IsRmulHealingAvailableCondition::IsRmulHealingAvailableCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsRmulHealingAvailableCondition::checkRmulHealingAvailable, this), config)
{
}

BT::NodeStatus IsRmulHealingAvailableCondition::checkRmulHealingAvailable()
{
  auto msg = getInput<rm_autonomy_interfaces::msg::ArenaStatus>("message");

  if (!msg) {
    std::cout << "missing required input [Arena Status]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (msg->rmul_healing == 1) {
    std::cout << "RMUL Healing Available!" << '\n';
    return BT::NodeStatus::SUCCESS;
  } else {
    std::cout << "RMUL Healing NOT Available" << '\n';
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsRmulHealingAvailableCondition>("IsRmulHealingAvailableCondition");
}
