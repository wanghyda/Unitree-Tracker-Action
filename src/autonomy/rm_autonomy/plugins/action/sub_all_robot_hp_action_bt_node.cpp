#include "rm_autonomy/plugins/action/sub_all_robot_hp_action_bt_node.hpp"

namespace rm_autonomy
{

SubAllRobotHPActionBTNode::SubAllRobotHPActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::AllRobotHP>(name, conf, params)
{
}

BT::NodeStatus SubAllRobotHPActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::AllRobotHP> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    RCLCPP_DEBUG(
      logger(), "[%s] new message, red_1_hp: %s", name().c_str(),
      std::to_string(last_msg->red_1_hp).c_str());
    setOutput("all_robot_hp", *last_msg);
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubAllRobotHPActionBTNode, "SubAllRobotHPActionBTNode");