#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_NAVIGATE_COMMAND_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_NAVIGATE_COMMAND_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/contrib/json.hpp"
#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "rm_autonomy_interfaces/msg/navigate_command.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"
namespace rm_autonomy
{
// Allows PoseStamped to be visualized in Groot2

class PubNavigateCommandActionBTNode : public BT::RosTopicPubNode<rm_autonomy_interfaces::msg::NavigateCommand>
{
public:
  PubNavigateCommandActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  bool setMessage(rm_autonomy_interfaces::msg::NavigateCommand & msg) override;

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<float>("spin_speed"),
            BT::InputPort<bool>("scap_state"),
            BT::InputPort<bool>("align_chassis_big_yaw")};
  }
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__PUB_NAVIGATE_COMMAND_ACTION_BT_NODE_HPP_