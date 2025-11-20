#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_BASE_ATTACKED_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_BASE_ATTACKED_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/arena_status.hpp"

namespace rm_autonomy
{
class IsBaseAttackedCondition : public BT::SimpleConditionNode
{
public:
  IsBaseAttackedCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkBaseAttacked();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::ArenaStatus>("message")};
  }

  bool is_base_invincible;
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_BASE_ATTACKED_CONDITION_HPP_