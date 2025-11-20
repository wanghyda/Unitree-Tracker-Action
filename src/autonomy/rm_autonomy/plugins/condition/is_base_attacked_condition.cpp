#include "rm_autonomy/plugins/condition/is_base_attacked_condition.hpp"

namespace rm_autonomy
{

IsBaseAttackedCondition::IsBaseAttackedCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsBaseAttackedCondition::checkBaseAttacked, this), config)
{
  is_base_invincible = true;
}

BT::NodeStatus IsBaseAttackedCondition::checkBaseAttacked()
{
  auto arena_status_msg = getInput<rm_autonomy_interfaces::msg::ArenaStatus>("message");
  int base_shield_percentage = arena_status_msg->base_shield_percentage;
  if (!arena_status_msg) {
    std::cout << "Check Base Attacked: missing required input" << '\n';
    return BT::NodeStatus::FAILURE;
  }
  // std::cout << "Check Base Attacked: "<< base_shield_percentage << '\n';
  if (base_shield_percentage  == 100) {
    is_base_invincible = false;
  }
  return (base_shield_percentage < 50 && !is_base_invincible) ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}  // namespace rm_autonomy
}
#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsBaseAttackedCondition>("IsBaseAttackedCondition");
}
