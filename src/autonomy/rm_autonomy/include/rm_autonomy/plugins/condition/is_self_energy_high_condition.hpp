#ifndef RM_AUTONOMY__PLUGINS__CONDITION__IS_SELF_ENERGY_HIGH_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__CONDITION__IS_SELF_ENERGY_HIGH_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/self_state.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rm_autonomy
{

class IsSelfEnergyHighCondition : public BT::SimpleConditionNode
{
public:
IsSelfEnergyHighCondition(const std::string & name, const BT::NodeConfig & config);

  // BT::NodeStatus checkGameStart(BT::TreeNode & self_node)
  BT::NodeStatus checkRobotStatus();

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("message"),
      BT::InputPort<int>("energy_threshold")};
  }
private:
  int last_energy;
};
}  // namespace rm_autonomy

#endif  //RM_AUTONOMY__PLUGINS__CONDITION__IS_SELF_ENERGY_HIGH_CONDITION_HPP_

