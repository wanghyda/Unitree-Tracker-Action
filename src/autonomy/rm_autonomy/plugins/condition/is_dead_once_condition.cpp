#include "rm_autonomy/plugins/condition/is_dead_once_condition.hpp"
#include "rclcpp/rclcpp.hpp"
namespace rm_autonomy
{

IsDeadOnceCondition::IsDeadOnceCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsDeadOnceCondition::checkDeadOnce, this), config)
{
  dead_once_ = false;
}

BT::NodeStatus IsDeadOnceCondition::checkDeadOnce()
{
  auto msg = getInput<bool>("dead_once");
  if (!msg) {
    std::cout << "missing required input [dead_once]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  dead_once_ = msg.value();
  //if(dead_once_) RCLCPP_INFO(rclcpp::get_logger("IsDeadOnceCondition"), "Dead Once!!!");
  return dead_once_ ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsDeadOnceCondition>("IsDeadOnceCondition");
}
