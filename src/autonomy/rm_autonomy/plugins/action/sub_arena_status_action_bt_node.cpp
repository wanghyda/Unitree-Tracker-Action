#include "rm_autonomy/plugins/action/sub_arena_status_action_bt_node.hpp"

namespace rm_autonomy
{

SubArenaStatusActionBTNode::SubArenaStatusActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::ArenaStatus>(name, conf, params)
{
}

BT::NodeStatus SubArenaStatusActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::ArenaStatus> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("arena_status", *last_msg);

  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubArenaStatusActionBTNode, "SubArenaStatusActionBTNode");