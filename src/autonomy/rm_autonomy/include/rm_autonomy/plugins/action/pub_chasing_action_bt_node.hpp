#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_CHASING_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_CHASING_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/contrib/json.hpp"
#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "std_msgs/msg/u_int8.hpp"

namespace rm_autonomy
{

class PubChasingActionBTNode : public BT::RosTopicPubNode<std_msgs::msg::UInt8>
{
public:
  PubChasingActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  bool setMessage(std_msgs::msg::UInt8 & msg) override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<std::string>("message"),
            BT::OutputPort<std::string>("is_chasing")};
  }
private:
    rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
    };
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__PUB_CHASING_ACTION_BT_NODE_HPP_