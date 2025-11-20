#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_SCAN_DISTANCE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_SCAN_DISTANCE_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node_Qos.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <geometry_msgs/msg/detail/pose_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include "geometry_msgs/msg/twist.hpp"

namespace rm_autonomy
{
class SubScanDistanceActionBTNode : public BT::RosTopicSubNode_Qos<sensor_msgs::msg::LaserScan>
{
public:
  SubScanDistanceActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<sensor_msgs::msg::LaserScan::SharedPtr>("scan_msg")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<sensor_msgs::msg::LaserScan> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  
