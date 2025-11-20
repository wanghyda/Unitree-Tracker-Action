#include "rm_autonomy/plugins/action/sub_invincible_target_action_bt_node.hpp"

namespace rm_autonomy
{

SubInvincibleTargetActionBTNode::SubInvincibleTargetActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::InvincibleTarget>(name, conf, params)
{
}

BT::NodeStatus SubInvincibleTargetActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::InvincibleTarget> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("invincible_target", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubInvincibleTargetActionBTNode, "SubInvincibleTargetActionBTNode");