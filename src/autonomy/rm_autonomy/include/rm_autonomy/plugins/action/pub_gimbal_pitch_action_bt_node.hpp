#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_GIMBAL_PITCH_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_GIMBAL_PITCH_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "std_msgs/msg/u_int8.hpp"

namespace rm_autonomy
{

class PubGimbalPitchActionBTNode : public BT::RosTopicPubNode<std_msgs::msg::UInt8>
{
public:
  PubGimbalPitchActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<int>("message"),
    };
  }

  bool setMessage(std_msgs::msg::UInt8 & msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};

}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__PUB_GIMBAL_PITCH_ACTION_BT_NODE_HPP_