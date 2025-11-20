#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_VEL_W_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_VEL_W_ACTION_BT_NODE_HPP_


#include <behaviortree_cpp/basic_types.h>
#include <behaviortree_ros2/bt_topic_pub_node.hpp>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
namespace rm_autonomy
{
  class PubVelWBTNode: public BT::RosTopicPubNode<geometry_msgs::msg::Twist>
  {
    public:
    PubVelWBTNode(const std::string & name, const BT::NodeConfig & config,const BT::RosNodeParams & params);
    bool setMessage(geometry_msgs::msg::Twist& msg) override;
    static BT::PortsList providedPorts()
    {
      return {
            BT::InputPort<float>("vel_w")};
    };

    private:
    rclcpp::Logger logger_{rclcpp::get_logger("PubVelWBTNode")};
  };
} // namespace rm_autonomy

#endif