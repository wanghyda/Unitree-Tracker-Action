#include "rm_autonomy/plugins/action/pub_navigate_command_action_bt_node.hpp"

namespace rm_autonomy
{

PubNavigateCommandActionBTNode::PubNavigateCommandActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<rm_autonomy_interfaces::msg::NavigateCommand>(name, conf, params)
{
}

bool PubNavigateCommandActionBTNode::setMessage(rm_autonomy_interfaces::msg::NavigateCommand & msg)
{
  auto spin_speed = getInput<float>("spin_speed");
  auto scap_state = getInput<bool>("scap_state");
  auto align_chassis_big_yaw = getInput<bool>("align_chassis_big_yaw");
  if (!spin_speed || !scap_state || !align_chassis_big_yaw) {
    throw BT::RuntimeError("error reading port [navigate_command]:", spin_speed.error());
  }
  msg.spin_speed = spin_speed.value();
  msg.scap_state = scap_state.value();
  msg.align_chassis_big_yaw = align_chassis_big_yaw.value();
  RCLCPP_INFO(logger_, "Publishing: spin_speed: %f, scap_state: %d,align: %d", msg.spin_speed, msg.scap_state,msg.align_chassis_big_yaw);
  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubNavigateCommandActionBTNode, "PubNavigateCommandActionBTNode");