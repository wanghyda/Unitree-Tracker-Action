#include "rm_autonomy/plugins/condition/is_self_hp_low_condition.hpp"

namespace rm_autonomy
{

IsSelfHPLowCondition::IsSelfHPLowCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsSelfHPLowCondition::checkRobotStatus, this), config)
{
  
}

BT::NodeStatus IsSelfHPLowCondition::checkRobotStatus()
{
  int hp_threshold;
  auto msg = getInput<rm_autonomy_interfaces::msg::SelfState>("message");
  getInput("hp_threshold", hp_threshold);

  if (!msg) {
    std::cout << "missing required input [SelfState]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (msg->current_hp < hp_threshold ) {
    last_hp = msg->current_hp;
    RCLCPP_INFO(rclcpp::get_logger("IsSelfHPLowCondition"), "Self HP Low");
    return BT::NodeStatus::SUCCESS;
  } else {
    last_hp = msg->current_hp;
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsSelfHPLowCondition>("IsSelfHPLowCondition");
}