#include "rm_autonomy/plugins/action/sub_game_status_action_bt_node.hpp"

namespace rm_autonomy
{

SubGameStatusActionBTNode::SubGameStatusActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::GameStatus>(name, conf, params)
{
}

BT::NodeStatus SubGameStatusActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::GameStatus> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("game_status", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubGameStatusActionBTNode, "SubGameStatusActionBTNode");