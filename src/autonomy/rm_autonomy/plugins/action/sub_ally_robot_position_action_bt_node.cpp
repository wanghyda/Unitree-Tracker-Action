#include "rm_autonomy/plugins/action/sub_ally_robot_position_action_bt_node.hpp"

namespace rm_autonomy
{

SubAllyRobotPositionActionBTNode::SubAllyRobotPositionActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::AllyRobotPosition>(name, conf, params)
{
}

BT::NodeStatus SubAllyRobotPositionActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("ally_robot_position", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubAllyRobotPositionActionBTNode, "SubAllyRobotPositionActionBTNode");