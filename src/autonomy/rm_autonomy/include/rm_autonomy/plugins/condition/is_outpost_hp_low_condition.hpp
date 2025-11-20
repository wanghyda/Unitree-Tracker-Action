#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_OUTPOST_HP_LOW_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_OUTPOST_HP_LOW_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/all_robot_hp.hpp"
#include "rm_autonomy_interfaces/msg/self_state.hpp"
namespace rm_autonomy
{
class IsOutpostHPLowCondition : public BT::SimpleConditionNode
{
public:
  IsOutpostHPLowCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkOutpostHPLow();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp"),
            BT::InputPort<int>("hp_threshold"),
            BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("self_state")};
  }

  bool is_base_invincible;
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_OUTPOST_HP_LOW_CONDITION_HPP_