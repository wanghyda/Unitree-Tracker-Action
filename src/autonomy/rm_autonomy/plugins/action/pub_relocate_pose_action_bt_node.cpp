#include "rm_autonomy/plugins/action/pub_relocate_pose_action_bt_node.hpp"
#include <cmath>
#include <geometry_msgs/msg/detail/pose_with_covariance_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>

namespace rm_autonomy
{

PubRelocatePoseActionBTNode::PubRelocatePoseActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<geometry_msgs::msg::PoseWithCovarianceStamped>(name, conf, params)
{
}

bool PubRelocatePoseActionBTNode::setMessage(geometry_msgs::msg::PoseWithCovarianceStamped & msg)
{
  geometry_msgs::msg::TransformStamped current_location;
    getInput<geometry_msgs::msg::TransformStamped>("current_location",current_location);
   geometry_msgs::msg::PoseWithCovarianceStamped relocation_pose;
   getInput("relocation_pose",relocation_pose);
  //  RCLCPP_INFO(logger_,  "pub_frame_id:%s",msg.header.frame_id.data());
   if (relocation_pose.header.frame_id!="map") {
        RCLCPP_INFO(logger_, "pub_relocation_pose_frame_id: %s", relocation_pose.header.frame_id.c_str());
      return false;
   }
    msg=relocation_pose;
    // RCLCPP_INFO(logger_,  "pub_msg_frame_id:%s",msg.header.frame_id.c_str());  
  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubRelocatePoseActionBTNode, "PubRelocatePoseActionBTNode");