#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_AGGRESSIVE_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_AGGRESSIVE_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/human_intervention.hpp"

namespace rm_autonomy
{
class IsAggressiveCondition : public BT::SimpleConditionNode
{
public:
  IsAggressiveCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkHumanIntervention();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::HumanIntervention>("message")};
  }
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_BASE_ATTACKED_CONDITION_HPP_