#ifndef RM_AUTONOMY__PLUGINS__ACTION__SEND_GOAL_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SEND_GOAL_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/contrib/json.hpp"
#include "rm_autonomy/bt_topic_pub_node.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

// Allows PoseStamped to be visualized in Groot2
void PoseStampedToJson(nlohmann::json & j, const geometry_msgs::msg::PoseStamped & p)
{
  j["position_x"] = p.pose.position.x;
  j["position_y"] = p.pose.position.y;
  j["position_z"] = p.pose.position.z;
  j["orientation_x"] = p.pose.orientation.x;
  j["orientation_y"] = p.pose.orientation.y;
  j["orientation_z"] = p.pose.orientation.z;
  j["orientation_w"] = p.pose.orientation.w;
}

namespace rm_autonomy
{

class SendGoalActionBTNode : public BT::TopicPubNode<geometry_msgs::msg::PoseStamped>
{
public:
  SendGoalActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, rclcpp::Node::SharedPtr node);

  BT::  NodeStatus tick() override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose")};
  }
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__SEND_GOAL_ACTION_BT_NODE_HPP_
