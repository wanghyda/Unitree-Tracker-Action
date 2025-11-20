#ifndef RM_AUTONOMY__PLUGINS__ACTION__CHASE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__CHASE_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/contrib/json.hpp"
#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/point.hpp"

namespace rm_autonomy
{

class ChaseActionBTNode : public BT::RosTopicPubNode<geometry_msgs::msg::PoseStamped>
{
public:
  ChaseActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  bool setMessage(geometry_msgs::msg::PoseStamped & msg) override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::Point>("enemy_autoaim_position"),
            BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location")};
  }
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__CHASE_ACTION_BT_NODE_HPP_