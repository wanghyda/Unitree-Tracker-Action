#include "rm_autonomy/plugins/condition/under_attack_condition.hpp"
#include <rclcpp/rclcpp.hpp>

namespace rm_autonomy
{

UnderAttackCondition::UnderAttackCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&UnderAttackCondition::checkRobotAttacked, this), config)
{
}

BT::NodeStatus UnderAttackCondition::checkRobotAttacked()
{
  auto msg = getInput<rm_autonomy_interfaces::msg::SelfState>("message");

  if (!msg) {
    std::cout << "missing required input [self state]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (msg->under_attack) {
    RCLCPP_INFO(rclcpp::get_logger("UnderAttackCondition"), "Robot is under attack");
    return BT::NodeStatus::SUCCESS;
  }
  //RCLCPP_INFO(rclcpp::get_logger("UnderAttackCondition"), "Robot is not under attack");
  return BT::NodeStatus::FAILURE;
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::UnderAttackCondition>("UnderAttackCondition");
}
