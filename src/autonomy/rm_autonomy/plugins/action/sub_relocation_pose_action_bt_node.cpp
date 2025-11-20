#include "rm_autonomy/plugins/action/sub_relocation_pose_action_bt_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <behaviortree_ros2/bt_topic_sub_node.hpp>
#include <geometry_msgs/msg/detail/pose_stamped__struct.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <memory>
#include <rclcpp/logging.hpp>
namespace rm_autonomy
{
SubRelocationPoseActionBTNode::SubRelocationPoseActionBTNode(const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<geometry_msgs::msg::PoseWithCovarianceStamped>(name, conf, params)
{
}

BT::NodeStatus SubRelocationPoseActionBTNode::onTick(const std::shared_ptr<geometry_msgs::msg::PoseWithCovarianceStamped> & last_msg)
{
    geometry_msgs::msg::PoseWithCovarianceStamped msg;
    if(last_msg)
    {
      msg.header.stamp = rclcpp::Clock().now();
      msg.header.frame_id = "map";
      msg.pose.pose.position.x = last_msg->pose.pose.position.x;
      msg.pose.pose.position.y = last_msg->pose.pose.position.y;
      msg.pose.pose.position.z = last_msg->pose.pose.position.z;
      msg.pose.pose.orientation.x = last_msg->pose.pose.orientation.x;
      msg.pose.pose.orientation.y = last_msg->pose.pose.orientation.y;
      msg.pose.pose.orientation.z = last_msg->pose.pose.orientation.z;
      msg.pose.pose.orientation.w = last_msg->pose.pose.orientation.w;
      
      // RCLCPP_INFO(logger_,  "sub_frame_id:%s",msg.header.frame_id.data());
    setOutput("relocation_pose", msg);
    return BT::NodeStatus::SUCCESS;
    }
    return BT::NodeStatus::FAILURE;

    
}
}  // namespace rm_autonomy
#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubRelocationPoseActionBTNode, "SubRelocationPoseActionBTNode");