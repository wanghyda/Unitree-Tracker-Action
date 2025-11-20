#include "rm_autonomy/plugins/condition/is_aggressive_condition.hpp"

namespace rm_autonomy
{

IsAggressiveCondition::IsAggressiveCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsAggressiveCondition::checkHumanIntervention, this), config)
{
}

BT::NodeStatus IsAggressiveCondition::checkHumanIntervention()
{
  auto msg = getInput<rm_autonomy_interfaces::msg::HumanIntervention>("message");
  if (!msg) {
    return BT::NodeStatus::FAILURE;
  }

  if (msg.value().command_header  == 2) {
    
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsAggressiveCondition>("IsAggressiveCondition");
}
