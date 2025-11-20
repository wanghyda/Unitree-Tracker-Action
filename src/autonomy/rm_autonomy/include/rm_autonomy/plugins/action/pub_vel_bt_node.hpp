#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_VEL_W_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_VEL_W_ACTION_BT_NODE_HPP_


#include <behaviortree_cpp/basic_types.h>
#include <behaviortree_ros2/bt_topic_pub_node.hpp>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include "geometry_msgs/msg/twist.hpp"

namespace rm_autonomy
{
  class PubVelBTNode: public BT::RosTopicPubNode<geometry_msgs::msg::Twist>
  {
    public:
    PubVelBTNode(const std::string & name, const BT::NodeConfig & config,const BT::RosNodeParams & params);
    bool setMessage(geometry_msgs::msg::Twist& msg) override;
    static BT::PortsList providedPorts()
    {
      return {
            BT::InputPort<float>("safe_direction")};
    };

    private:
    geometry_msgs::msg::Twist last_vel;
    rclcpp::Logger logger_{rclcpp::get_logger("PubVelBTNode")};
  };
} // namespace rm_autonomy

#endif