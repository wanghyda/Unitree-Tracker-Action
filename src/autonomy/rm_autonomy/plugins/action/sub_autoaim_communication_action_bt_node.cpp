#include "rm_autonomy/plugins/action/sub_autoaim_communication_action_bt_node.hpp"
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
namespace rm_autonomy
{

SubAutoaimCommunicationActionBTNode::SubAutoaimCommunicationActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::AutoaimCommunication>(name, conf, params)
{
}

BT::NodeStatus SubAutoaimCommunicationActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication> & last_msg)
{
  auto current_location_msg = getInput<geometry_msgs::msg::TransformStamped>("current_location");
  auto gimbal1_yaw_msg = getInput<std_msgs::msg::Float32>("gimbal1_yaw");
  if (!current_location_msg) {
    RCLCPP_ERROR(logger_, "No Current location msg in blackboard!");
    return BT::NodeStatus::SUCCESS;
  }
  if (!gimbal1_yaw_msg) {
    RCLCPP_ERROR(logger_, "No Gimbal1 msg in blackboard!");
    return BT::NodeStatus::SUCCESS;
  }
  
  if (last_msg)  // empty if no new message received, since the last tick
  {
    auto autoaim_communication_msg = *last_msg;
    if(autoaim_communication_msg.has_target == 0 && 
      (this->node_->get_clock()->now().seconds() - last_timestamp_.seconds() > 3.0))
    {
      // RCLCPP_INFO(logger_, "Autoaim lost target!");
      geometry_msgs::msg::Point enemy_autoaim_position;
      enemy_autoaim_position.x = 0;
      enemy_autoaim_position.y = 0;
      enemy_autoaim_position.z = 0;
      setOutput("enemy_autoaim_position", enemy_autoaim_position);
      uint8_t target_id = 0;
      setOutput("enemy_autoaim_id", target_id);

      return BT::NodeStatus::SUCCESS; // clear blackboard's position and id
    } else if (autoaim_communication_msg.has_target == 0) {
      RCLCPP_INFO_STREAM(logger_, "Autoaim no target, stay up for 3 seconds!");
      return BT::NodeStatus::SUCCESS; // keep unchanged
    }
    // update timestamp
    last_timestamp_ = this->node_->get_clock()->now();

    // Calculate the transformation matrix from the current location
    tf2::Transform current_transform;
    tf2::fromMsg(current_location_msg.value().transform, current_transform);
  
    // Calculate the inverse of the transformation matrix
    tf2::Matrix3x3 m(current_transform.getRotation());
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    // Calculate the point in the current location frame
    double distance = autoaim_communication_msg.distance;
    double gimbal1_yaw = gimbal1_yaw_msg.value().data;

    tf2::Vector3 point_in_map_frame(distance * cos(gimbal1_yaw + yaw) + current_transform.getOrigin().x(), distance * sin(gimbal1_yaw + yaw) + current_transform.getOrigin().y(), 0.0);
  
    // Convert tf2::Vector3 to geometry_msgs::msg::Point
    geometry_msgs::msg::Point enemy_autoaim_position;
    enemy_autoaim_position.x = point_in_map_frame.x();
    enemy_autoaim_position.y = point_in_map_frame.y();
    enemy_autoaim_position.z = point_in_map_frame.z();

    RCLCPP_INFO_STREAM(logger_, "Autoaim has target!" << enemy_autoaim_position.x << " " << enemy_autoaim_position.y);
    setOutput("enemy_autoaim_position", enemy_autoaim_position);
    setOutput("enemy_autoaim_id", autoaim_communication_msg.target_id);
    setOutput("autoaim_communication", autoaim_communication_msg);
    return BT::NodeStatus::SUCCESS;
  }
  RCLCPP_INFO_STREAM(logger_, "Autoaim no target!");
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubAutoaimCommunicationActionBTNode, "SubAutoaimCommunicationActionBTNode");