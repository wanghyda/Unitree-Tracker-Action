#include "rm_autonomy/plugins/condition/is_self_ammo_low_condition.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rm_autonomy
{

IsSelfAmmoLowCondition::IsSelfAmmoLowCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsSelfAmmoLowCondition::checkSelfAmmoLow, this), config)
{
}

BT::NodeStatus IsSelfAmmoLowCondition::checkSelfAmmoLow()
{
  auto self_state_msg = getInput<rm_autonomy_interfaces::msg::SelfState>("self_state_msg");
  int threshold;
  getInput("threshold", threshold);

  if (!self_state_msg) {
    std::cout << "missing required input [self state]" << '\n';
    return BT::NodeStatus::FAILURE;
  }
  if (!threshold) {
    std::cout << "missing required input [threshold]" << '\n';
    return BT::NodeStatus::FAILURE;
  }
  int self_ammo = self_state_msg.value().current_ammo;
  bool supply_availible =false;//TODO
  if(self_ammo >= threshold) {
    return BT::NodeStatus::SUCCESS;
  } else {
        RCLCPP_INFO(rclcpp::get_logger("IsSelfAmmoLowCondition"), "Self Ammo Low");

    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsSelfAmmoLowCondition>("IsSelfAmmoLowCondition");
}
