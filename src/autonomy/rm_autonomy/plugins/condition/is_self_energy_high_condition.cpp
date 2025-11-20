#include "rm_autonomy/plugins/condition/is_self_energy_high_condition.hpp"

namespace rm_autonomy
{

IsSelfEnergyHighCondition::IsSelfEnergyHighCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsSelfEnergyHighCondition::checkRobotStatus, this), config)
{
  
}

BT::NodeStatus IsSelfEnergyHighCondition::checkRobotStatus()
{
  int energy_threshold;
  auto msg = getInput<rm_autonomy_interfaces::msg::SelfState>("message");
  getInput("energy_threshold", energy_threshold);

  if (!msg) {
    std::cout << "missing required input [SelfState]" << '\n';
    return BT::NodeStatus::FAILURE;
  }

  if (msg->energy_left <= energy_threshold ) {
    last_energy = msg->energy_left;
    RCLCPP_INFO(rclcpp::get_logger("IsSelfEnergyHighCondition"), "Self Energy high,%d,%d",energy_threshold,last_energy);

    return BT::NodeStatus::SUCCESS;
  } else {
    last_energy = msg->energy_left;
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsSelfEnergyHighCondition>("IsSelfEnergyHighCondition");
}