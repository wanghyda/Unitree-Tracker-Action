#include "rm_autonomy/plugins/condition/is_outpost_hp_low_condition.hpp"
#include "rclcpp/rclcpp.hpp"
namespace rm_autonomy
{

IsOutpostHPLowCondition::IsOutpostHPLowCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsOutpostHPLowCondition::checkOutpostHPLow, this), config)
{
  
}

BT::NodeStatus IsOutpostHPLowCondition::checkOutpostHPLow()
{
  int hp_threshold;
  auto hp_msg = getInput<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp");
  auto self_state_msg = getInput<rm_autonomy_interfaces::msg::SelfState>("self_state");
  getInput("hp_threshold", hp_threshold);

  if (!hp_msg ) {
    std::cout << "missing required input [hp]" << '\n';
    return BT::NodeStatus::SUCCESS;
  }
  if (!self_state_msg ) {
    std::cout << "missing required input [self state]" << '\n';
    return BT::NodeStatus::SUCCESS;
  }
  // 大于100是蓝
  if ((hp_msg->blue_outpost_hp < hp_threshold && self_state_msg->robot_id > 100) ||
       (hp_msg->red_outpost_hp < hp_threshold && self_state_msg->robot_id < 100)) {
    RCLCPP_INFO(rclcpp::get_logger("IsOutpostHPLowCondition"), "Outpost HP Low");
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsOutpostHPLowCondition>("IsOutpostHPLowCondition");
}
