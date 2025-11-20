#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_RELOCATION_POSE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_RELOCATION_POSE_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>

namespace rm_autonomy
{
class SubRelocationPoseActionBTNode : public BT::RosTopicSubNode<geometry_msgs::msg::PoseWithCovarianceStamped>
{
public:
  SubRelocationPoseActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<geometry_msgs::msg::PoseWithCovarianceStamped>("relocation_pose")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<geometry_msgs::msg::PoseWithCovarianceStamped> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  
