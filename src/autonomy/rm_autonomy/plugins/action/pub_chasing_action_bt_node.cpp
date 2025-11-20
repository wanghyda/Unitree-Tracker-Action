#include "rm_autonomy/plugins/action/pub_chasing_action_bt_node.hpp"

namespace rm_autonomy
{

PubChasingActionBTNode::PubChasingActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<std_msgs::msg::UInt8>(name, conf, params)
{
}

bool PubChasingActionBTNode::setMessage(std_msgs::msg::UInt8 & msg)
{
  auto message = getInput<std::string>("message");
  if (!message) {
    throw BT::RuntimeError("error reading port [message]:", message.error());
  }
  msg = std_msgs::msg::UInt8();
  msg.data = std::stoi(message.value());
  RCLCPP_INFO(logger_, "[chasing]Publishing: message: %d", msg.data);
  std::string output = msg.data == 1 ? "1" : "0";
  setOutput("is_chasing", output);
  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubChasingActionBTNode, "PubChasingActionBTNode");