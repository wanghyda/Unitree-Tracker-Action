#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_ESCAPE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_ESCAPE_ACTION_BT_NODE_HPP_


#include <behaviortree_cpp/basic_types.h>
#include "sensor_msgs/msg/laser_scan.hpp"
#include <behaviortree_ros2/bt_topic_pub_node.hpp>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
namespace rm_autonomy
{
  class PubEscapeAction: public BT::RosTopicPubNode<geometry_msgs::msg::Twist>
  {
    public:
    PubEscapeAction(const std::string & name, const BT::NodeConfig & config,const BT::RosNodeParams & params);
    bool setMessage(geometry_msgs::msg::Twist& msg) override;
    static BT::PortsList providedPorts()
    {
      return {
            BT::InputPort<sensor_msgs::msg::LaserScan::SharedPtr>("scan_msg"),
            BT::OutputPort<bool>("escape_stage")};
    };

    private:
    rclcpp::Logger logger_{rclcpp::get_logger("PubEscapeAction")};
  };
} // namespace rm_autonomy

#endif