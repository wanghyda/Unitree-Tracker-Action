#include "rm_autonomy/plugins/condition/is_enemy_outpost_dead_condition.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rm_autonomy
{

IsEnemyOutpostDeadCondition::IsEnemyOutpostDeadCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsEnemyOutpostDeadCondition::checkEnemyOutpostDead, this), config)
{
  
}

BT::NodeStatus IsEnemyOutpostDeadCondition::checkEnemyOutpostDead()
{
  auto all_robot_hp_msg = getInput<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp");
  auto self_state_msg = getInput<rm_autonomy_interfaces::msg::SelfState>("self_state");

  if (!all_robot_hp_msg || !self_state_msg) {
    return BT::NodeStatus::FAILURE;
  }
  // 大于100是蓝
  if ((all_robot_hp_msg->red_outpost_hp < 10 && self_state_msg->robot_id > 100) ||
       (all_robot_hp_msg->blue_outpost_hp < 10 && self_state_msg->robot_id < 100)) {
    RCLCPP_INFO(rclcpp::get_logger("IsEnemyOutpostDeadCondition"), "Enemy Outpost Dead");
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsEnemyOutpostDeadCondition>("IsEnemyOutpostDeadCondition");
}
