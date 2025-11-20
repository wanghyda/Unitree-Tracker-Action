#include "rm_autonomy/plugins/action/send_goal_action_bt_node.hpp"
#include "rm_autonomy/bt_conversions.hpp"
#include <rclcpp/logging.hpp>

namespace rm_autonomy
{

SendGoalActionBTNode::SendGoalActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, rclcpp::Node::SharedPtr node)
: TopicPubNode<geometry_msgs::msg::PoseStamped>(name, conf, node,"goal_pose")
{
}

BT::  NodeStatus  SendGoalActionBTNode::tick() 
{
  auto goal_pose = getInput<geometry_msgs::msg::PoseStamped>("goal_pose");
  if (!goal_pose) {
    RCLCPP_ERROR(logger_,"error reading port [goal_pose]:");
    return BT::NodeStatus::FAILURE;
  }
  geometry_msgs::msg::PoseStamped msg;
  geometry_msgs::msg::PoseStamped goal = goal_pose.value();
  msg.header.stamp = rclcpp::Clock().now();
  msg.header.frame_id = "map";
  msg.pose.position.x = goal.pose.position.x;
  msg.pose.position.y = goal.pose.position.y;
  msg.pose.position.z = goal.pose.position.z;
  msg.pose.orientation.x = goal.pose.orientation.x;
  msg.pose.orientation.y = goal.pose.orientation.y;
  msg.pose.orientation.z = goal.pose.orientation.z;
  msg.pose.orientation.w = goal.pose.orientation.w;
  // clang-format off
  RCLCPP_INFO(logger_,"sending location(%f,%f)",msg.pose.position.x,msg.pose.position.y);
  //   << "[send_goal_action_bt_node]" << ", "
  //   << msg.pose.position.x << ", "
  //   << msg.pose.position.y << ", "
  //   << msg.pose.position.z << ", "
  //   << msg.pose.orientation.x << ", "
  //   << msg.pose.orientation.y << ", "
  //   << msg.pose.orientation.z << ", "
  //   << msg.pose.orientation.w );
  // clang-format on
    publish(msg);

    return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "rm_autonomy/plugins.hpp"
CREATE_BT_ROS_NODE_PLUGIN(rm_autonomy::SendGoalActionBTNode, SendGoalActionBTNode)