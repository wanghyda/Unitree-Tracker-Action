#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_AUTOAIM_COMMUNICATION_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_AUTOAIM_COMMUNICATION_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/autoaim_communication.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/float32.hpp"

namespace rm_autonomy
{
class SubAutoaimCommunicationActionBTNode : public BT::RosTopicSubNode<rm_autonomy_interfaces::msg::AutoaimCommunication>
{
public:
  SubAutoaimCommunicationActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
      BT::InputPort<std_msgs::msg::Float32>("gimbal1_yaw"),
      BT::OutputPort<geometry_msgs::msg::Point>("enemy_autoaim_position"),
      BT::OutputPort<uint8_t>("enemy_autoaim_id"),
      BT::OutputPort<rm_autonomy_interfaces::msg::AutoaimCommunication>("autoaim_communication")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication> & last_msg) override;
private:
  rclcpp::Time last_timestamp_;
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  //  RM_AUTONOMY__PLUGINS__ACTION__SUB_AUTOAIM_COMMUNICATION_ACTION_BT_NODE_HPP_
