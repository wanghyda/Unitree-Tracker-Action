#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_RELOCATE_POSE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_RELOCATE_POSE_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/contrib/json.hpp"
#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "rm_autonomy_interfaces/msg/radar_target.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
namespace rm_autonomy
{
// Allows PoseStamped to be visualized in Groot2

class PubRelocatePoseActionBTNode : public BT::RosTopicPubNode<geometry_msgs::msg::PoseWithCovarianceStamped>
{
public:
  PubRelocatePoseActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  bool setMessage(geometry_msgs::msg::PoseWithCovarianceStamped & msg) override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
      BT::InputPort<geometry_msgs::msg::PoseWithCovarianceStamped>("relocation_pose")};
  }
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__PUB_RELOCATE_POSE_ACTION_BT_NODE_HPP_