#include "rm_autonomy/plugins/action/chase_action_bt_node.hpp"
namespace rm_autonomy
{

ChaseActionBTNode::ChaseActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<geometry_msgs::msg::PoseStamped>(name, conf, params)
{
}

bool ChaseActionBTNode::setMessage(geometry_msgs::msg::PoseStamped & msg)
{
  auto current_location_msg = getInput<geometry_msgs::msg::TransformStamped>("current_location");
  auto enemy_autoaim_position = getInput<geometry_msgs::msg::Point>("enemy_autoaim_position");

  if (!current_location_msg || !enemy_autoaim_position) {
    RCLCPP_ERROR(this->node_->get_logger(), "Failed to get inputs");
    return false;
  }

  // 获取当前位置和敌人的位置
  auto current_position = current_location_msg.value().transform.translation;
  auto enemy_position = enemy_autoaim_position.value();

  // 计算当前位置到敌人位置的向量
  double dx = enemy_position.x - current_position.x;
  double dy = enemy_position.y - current_position.y;

  // 计算当前位置到敌人位置的距离
  double distance = std::sqrt(dx * dx + dy * dy);

  // 目标保持距离为3米，不论当前距离是大是小
  double target_distance = 3.5;

  // 计算新的目标点坐标，总是保持3米距离
  double factor = target_distance / distance;
  double target_x = current_position.x + dx * factor;
  double target_y = current_position.y + dy * factor;

  msg.header.stamp = this->node_->get_clock()->now();
  msg.header.frame_id = "map";
  msg.pose.position.x = target_x;
  msg.pose.position.y = target_y;
  msg.pose.position.z = 0;
  msg.pose.orientation = current_location_msg.value().transform.rotation;

  RCLCPP_INFO_STREAM(logger_,std::fixed << std::setprecision(1)
    << "[chase_action_bt_node] " 
    << msg.pose.position.x << ", "
    << msg.pose.position.y << ", "
    << msg.pose.position.z << ", "
    << msg.pose.orientation.x << ", "
    << msg.pose.orientation.y << ", "
    << msg.pose.orientation.z << ", "
    << msg.pose.orientation.w << " " << "\n");
  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::ChaseActionBTNode, "ChaseActionBTNode");