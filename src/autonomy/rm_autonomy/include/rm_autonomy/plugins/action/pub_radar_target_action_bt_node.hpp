#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_RADAR_TARGET_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_RADAR_TARGET_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/contrib/json.hpp"
#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "rm_autonomy_interfaces/msg/radar_target.hpp"
#include "geometry_msgs/msg/point.hpp"
namespace rm_autonomy
{
// Allows PoseStamped to be visualized in Groot2

class PubRadarTargetActionBTNode : public BT::RosTopicPubNode<rm_autonomy_interfaces::msg::RadarTarget>
{
public:
  PubRadarTargetActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  bool setMessage(rm_autonomy_interfaces::msg::RadarTarget & msg) override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::Point>("enemy_autoaim_position"),
      BT::InputPort<uint8_t>("enemy_autoaim_id")};
  }
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__PUB_RADAR_TARGET_ACTION_BT_NODE_HPP_