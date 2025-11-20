#include"rm_autonomy/plugins/action/sub_chase_control_action_bt_node.hpp"

namespace rm_autonomy
{

SubChaseControlActionBTNode::SubChaseControlActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicSubNode<rm_autonomy_interfaces::msg::ChaseControl>(name, conf, params)
{
}

BT::NodeStatus SubChaseControlActionBTNode::onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::ChaseControl> & last_msg)
{
  if (!last_msg) {
    RCLCPP_ERROR(logger_, "[subchase] No message received");
    return BT::NodeStatus::FAILURE;
  }
  setOutput("chase_control", *last_msg);
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubChaseControlActionBTNode, "SubChaseControlActionBTNode");