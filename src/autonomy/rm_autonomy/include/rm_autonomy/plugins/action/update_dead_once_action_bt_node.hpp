#ifndef RM_AUTONOMY__PLUGINS__ACTION__UPDATE_DEAD_ONCE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__UPDATE_DEAD_ONCE_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/action_node.h"
#include "rm_autonomy_interfaces/msg/self_state.hpp"
#include "rm_autonomy_interfaces/msg/game_status.hpp"

namespace rm_autonomy
{

class UpdateDeadOnceActionBTNode : public BT::SimpleActionNode
{
public:
  UpdateDeadOnceActionBTNode(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("self_state"),
      BT::InputPort<rm_autonomy_interfaces::msg::GameStatus>("game_status"),
      BT::OutputPort<bool>("dead_once")};
  }

  BT::NodeStatus UpdateDeadOnce();
  
  bool dead_once_;
};

}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__UPDATE_DEAD_ONCE_ACTION_BT_NODE_HPP_