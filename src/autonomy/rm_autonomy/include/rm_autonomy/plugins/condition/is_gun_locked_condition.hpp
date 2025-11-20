#ifndef RM_AUTONOMY__PLUGINS__CONDITION__IS_GUN_LOCKED_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__CONDITION__IS_GUN_LOCKED_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/fire_trigger.hpp"

namespace rm_autonomy
{
class IsGunLockedCondition : public BT::SimpleConditionNode
{
public:
  IsGunLockedCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkGunLocked();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::FireTrigger>("fire_trigger_value"),};
  }
  
  bool gun_locked_;
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__CONDITION__IS_GUN_LOCKED_CONDITION_HPP_