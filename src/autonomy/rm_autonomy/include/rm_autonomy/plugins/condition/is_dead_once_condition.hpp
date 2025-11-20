#ifndef RM_AUTONOMY__PLUGINS__CONDITION__IS_DEAD_ONCE_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__CONDITION__IS_DEAD_ONCE_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
namespace rm_autonomy
{

class IsDeadOnceCondition : public BT::SimpleConditionNode
{
public:
  IsDeadOnceCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkDeadOnce();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<bool>("dead_once"),};
  }
private:
  bool dead_once_;
};
}  // namespace rm_autonomy

#endif  //RM_AUTONOMY__PLUGINS__CONDITION__IS_DEAD_ONCE_CONDITION_HPP_