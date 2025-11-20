#include "rm_autonomy/plugins/condition/is_self_hp_high_condition.hpp"

namespace rm_autonomy
{

IsSelfHPHighCondition::IsSelfHPHighCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsSelfHPHighCondition::checkRobotStatus, this), config)
{
  
}

BT::NodeStatus IsSelfHPHighCondition::checkRobotStatus()
{
  int hp_threshold;
  auto msg = getInput<rm_autonomy_interfaces::msg::SelfState>("message");
  getInput("hp_threshold", hp_threshold);

  if (!msg) {
    std::cout << "missing required input [SelfState]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (msg->current_hp >= hp_threshold ) {
    last_hp = msg->current_hp;
    RCLCPP_INFO(rclcpp::get_logger("IsSelfHPHighCondition"), "Self HP high,%d,%d",hp_threshold,last_hp);

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
  factory.registerNodeType<rm_autonomy::IsSelfHPHighCondition>("IsSelfHPHighCondition");
}