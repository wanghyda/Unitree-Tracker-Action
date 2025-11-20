#include"rm_autonomy/plugins/action/pub_gimbal_pitch_action_bt_node.hpp"

namespace rm_autonomy
{

PubGimbalPitchActionBTNode::PubGimbalPitchActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<std_msgs::msg::UInt8>(name, conf, params)
{
}

bool PubGimbalPitchActionBTNode::setMessage(std_msgs::msg::UInt8 & msg)
{
  auto message = getInput<int>("message");
  if (!message) {
    throw BT::RuntimeError("error reading port [message]:");
  }
  msg = std_msgs::msg::UInt8();
  uint8_t data = *message;
  msg.data = data;
  RCLCPP_INFO(logger_, "[gimbal_pitch]Publishing: message: %d", msg.data);
  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubGimbalPitchActionBTNode, "PubGimbalPitchActionBTNode");