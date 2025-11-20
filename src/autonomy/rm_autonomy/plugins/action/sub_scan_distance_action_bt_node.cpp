#include "rm_autonomy/plugins/action/sub_scan_distance_action_bt_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <behaviortree_cpp/basic_types.h>
#include <behaviortree_cpp/decorators/retry_node.h>
#include <behaviortree_ros2/bt_topic_sub_node_Qos.hpp>
#include <geometry_msgs/msg/detail/pose_stamped__struct.hpp>
#include "geometry_msgs/msg/twist.hpp"
#include <memory>
#include <rclcpp/create_publisher.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>
namespace rm_autonomy
{
SubScanDistanceActionBTNode::SubScanDistanceActionBTNode(const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode_Qos<sensor_msgs::msg::LaserScan>(name, conf, params)
{

}
BT::NodeStatus SubScanDistanceActionBTNode::onTick(const std::shared_ptr<sensor_msgs::msg::LaserScan> & last_msg)
{
    setOutput("scan_msg", last_msg);
    if(last_msg){
        RCLCPP_INFO(logger_, "send scan");
          return BT::NodeStatus::SUCCESS;
    }
    return BT::NodeStatus::FAILURE;
}
}

 // namespace rm_autonomy
#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubScanDistanceActionBTNode, "SubScanDistanceActionBTNode");