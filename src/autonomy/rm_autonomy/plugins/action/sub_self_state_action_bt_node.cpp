#include "rm_autonomy/plugins/action/sub_self_state_action_bt_node.hpp"
#include <rclcpp/logging.hpp>

namespace rm_autonomy
{

SubSelfStateActionBTNode::SubSelfStateActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::SelfState>(name, conf, params)
{
}

BT::NodeStatus SubSelfStateActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::SelfState> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("self_state", *last_msg);
    setOutput("decision_set", last_msg->decision_set);
    // RCLCPP_INFO(logger_,"self_state has been sent");
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubSelfStateActionBTNode, "SubSelfStateActionBTNode");