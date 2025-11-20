#include "rm_autonomy/plugins/condition/is_rmuc_healing_available_condition.hpp"

namespace rm_autonomy
{

IsRmucHealingAvailableCondition::IsRmucHealingAvailableCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsRmucHealingAvailableCondition::checkRmucHealingAvailable, this), config)
{
}

BT::NodeStatus IsRmucHealingAvailableCondition::checkRmucHealingAvailable()
{
  auto arena_status_msg = getInput<rm_autonomy_interfaces::msg::ArenaStatus>("message");

  if (!arena_status_msg) {
    std::cout << "missing required input [Arena Status]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (arena_status_msg.value().healing_inner == 1 && arena_status_msg.value().healing_out == 1) {
    std::cout << "RMUC Healing Available!" << '\n';
    return BT::NodeStatus::SUCCESS;
  } else {
    std::cout << "RMUC Healing NOT Available" << '\n';
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsRmucHealingAvailableCondition>("IsRmucHealingAvailableCondition");
}
