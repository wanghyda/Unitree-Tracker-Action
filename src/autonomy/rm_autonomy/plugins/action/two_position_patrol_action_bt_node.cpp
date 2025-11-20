#include "rm_autonomy/plugins/action/two_position_patrol_action_bt_node.hpp"

namespace rm_autonomy
{

TwoPositionPatrolActionBTNode::TwoPositionPatrolActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<geometry_msgs::msg::PoseStamped>(name, conf, params)
{
  last_switch_time_ = this->node_->get_clock()->now();
  use_first_pose_ = true;
}

bool TwoPositionPatrolActionBTNode::setMessage(geometry_msgs::msg::PoseStamped & msg)
{
  auto goal_pose_1_msg = getInput<geometry_msgs::msg::PoseStamped>("goal_pose_1");
  auto goal_pose_2_msg = getInput<geometry_msgs::msg::PoseStamped>("goal_pose_2");
  if (!goal_pose_1_msg) {
    throw BT::RuntimeError("error reading port [goal_pose_1]:", goal_pose_1_msg.error());
  }
  if (!goal_pose_2_msg) {
    throw BT::RuntimeError("error reading port [goal_pose_2]:", goal_pose_2_msg.error());
  }
  auto now = this->node_->get_clock()->now();
  if (now - last_switch_time_ >= rclcpp::Duration::from_seconds(5)) {
    use_first_pose_ = !use_first_pose_;
    last_switch_time_ = now;
  }
  geometry_msgs::msg::PoseStamped goal_pose;
  goal_pose = use_first_pose_ ? goal_pose_1_msg.value() : goal_pose_2_msg.value();

  msg.header.stamp = this->node_->get_clock()->now();
  msg.header.frame_id = "map";
  msg.pose.position.x = goal_pose.pose.position.x;
  msg.pose.position.y = goal_pose.pose.position.y;
  msg.pose.position.z = goal_pose.pose.position.z;
  msg.pose.orientation = goal_pose.pose.orientation;

  // clang-format off
  // RCLCPP_INFO_STREAM(logger_,std::fixed << std::setprecision(1)
  //   << "[two_position_patrol_action_bt_node]" << ":"
  //   << msg.pose.position.x << ", "
  //   << msg.pose.position.y << ", "
  //   << msg.pose.position.z << ", "
  //   << msg.pose.orientation.x << ", "
  //   << msg.pose.orientation.y << ", "
  //   << msg.pose.orientation.z << ", "
  //   << msg.pose.orientation.w );
  // clang-format on

  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::TwoPositionPatrolActionBTNode, "TwoPositionPatrolActionBTNode");