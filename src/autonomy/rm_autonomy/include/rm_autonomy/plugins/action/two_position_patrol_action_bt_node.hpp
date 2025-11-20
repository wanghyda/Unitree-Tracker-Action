#ifndef RM_AUTONOMY__PLUGINS__ACTION__TWO_POSITION_PATROL_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__TWO_POSITION_PATROL_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rm_autonomy/bt_conversions.hpp"

namespace rm_autonomy
{

class TwoPositionPatrolActionBTNode : public BT::RosTopicPubNode<geometry_msgs::msg::PoseStamped>
{
public:
  TwoPositionPatrolActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  bool setMessage(geometry_msgs::msg::PoseStamped & msg) override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose_1"),
            BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose_2")};
  }
private:
  rclcpp::Time last_switch_time_;
  bool use_first_pose_;
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__SEND_GOAL_ACTION_BT_NODE_HPP_