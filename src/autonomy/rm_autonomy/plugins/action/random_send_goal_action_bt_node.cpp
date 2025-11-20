#include "rm_autonomy/plugins/action/random_send_goal_action_bt_node.hpp"
#include <random>
#include <cmath>
namespace rm_autonomy
{

RandomSendGoalActionBTNode::RandomSendGoalActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<geometry_msgs::msg::PoseStamped>(name, conf, params)
{
  last_switch_time_ = this->node_->get_clock()->now();
  use_first_part_ = true;
  angle = 0.0;
}

bool RandomSendGoalActionBTNode::setMessage(geometry_msgs::msg::PoseStamped & msg)
{
  auto goal_pose_center_msg = getInput<geometry_msgs::msg::PoseStamped>("goal_pose_center");
  auto radius_msg = getInput<float>("radius");
  if (!goal_pose_center_msg) {
    throw BT::RuntimeError("error reading port [goal_pose_center]:", goal_pose_center_msg.error());
  }
  if (!radius_msg) {
    throw BT::RuntimeError("error reading port [radius]:", radius_msg.error());
  }
  geometry_msgs::msg::PoseStamped goal = goal_pose_center_msg.value();
  auto now = this->node_->get_clock()->now();
  float radius = radius_msg.value();
  if (now - last_switch_time_ >= rclcpp::Duration::from_seconds(5.0)) {
    use_first_part_ = !use_first_part_;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis1(M_PI / 4, 3 * M_PI / 4);
    std::uniform_real_distribution<> dis2(-3 * M_PI / 4, -M_PI / 4);
    angle = use_first_part_ ? dis1(gen) : dis2(gen);
    last_switch_time_ = now;
  }

  msg.header.stamp = this->node_->get_clock()->now();
  msg.header.frame_id = "map";
  msg.pose.position.x = goal_pose_center_msg.value().pose.position.x + radius * cos(angle);
  msg.pose.position.y = goal_pose_center_msg.value().pose.position.y + radius * sin(angle);
  msg.pose.position.z = goal_pose_center_msg.value().pose.position.z;
  msg.pose.orientation = goal_pose_center_msg.value().pose.orientation;

  // clang-format off
  // RCLCPP_INFO_STREAM(logger_,std::fixed << std::setprecision(1)
  //   << "[random_send_goal_action_bt_node]" << ", "
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
CreateRosNodePlugin(rm_autonomy::RandomSendGoalActionBTNode, "RandomSendGoalActionBTNode");