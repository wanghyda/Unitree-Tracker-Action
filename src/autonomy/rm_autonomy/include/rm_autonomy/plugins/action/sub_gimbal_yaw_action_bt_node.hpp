#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_GIMBAL_YAW_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_GIMBAL_YAW_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "std_msgs/msg/float32.hpp"

namespace rm_autonomy
{
class SubGimbalYawActionBTNode : public BT::RosTopicSubNode<std_msgs::msg::Float32>
{
public:
  SubGimbalYawActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<std_msgs::msg::Float32>("gimbal1_yaw")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<std_msgs::msg::Float32> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  //  RM_AUTONOMY__PLUGINS__ACTION__SUB_GIMBAL_YAW_ACTION_BT_NODE_HPP_