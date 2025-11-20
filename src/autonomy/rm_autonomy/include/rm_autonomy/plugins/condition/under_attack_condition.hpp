#ifndef RM_AUTONOMY__PLUGINS__ACTION__UNDER_ATTACK_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__UNDER_ATTACK_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/self_state.hpp"

namespace rm_autonomy
{

/**
 * @brief condition node,
 * @param[in] message 
 */
class UnderAttackCondition : public BT::SimpleConditionNode
{
public:
  UnderAttackCondition(const std::string & name, const BT::NodeConfig & config);
  BT::NodeStatus checkRobotAttacked();
  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("message")};
  }
};
}  // namespace rm_autonomy

#endif   // RM_AUTONOMY__PLUGINS__ACTION__UNDER_ATTACK_CONDITION_HPP_