#include "rm_autonomy/plugins/action/sub_gimbal_yaw_action_bt_node.hpp"

namespace rm_autonomy
{

SubGimbalYawActionBTNode::SubGimbalYawActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<std_msgs::msg::Float32>(name, conf, params)
{
}

BT::NodeStatus SubGimbalYawActionBTNode::onTick(
  const std::shared_ptr<std_msgs::msg::Float32> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("gimbal1_yaw", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubGimbalYawActionBTNode, "SubGimbalYawActionBTNode");