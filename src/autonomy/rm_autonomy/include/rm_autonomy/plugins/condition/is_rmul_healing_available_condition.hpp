#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_RMUL_HEALING_AVAILABLE_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_RMUL_HEALING_AVAILABLE_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/arena_status.hpp"

namespace rm_autonomy
{
class IsRmulHealingAvailableCondition : public BT::SimpleConditionNode
{
public:
  IsRmulHealingAvailableCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkRmulHealingAvailable();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::ArenaStatus>("message")};
  }
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_RMUL_HEALING_AVAILABLE_CONDITION_HPP_