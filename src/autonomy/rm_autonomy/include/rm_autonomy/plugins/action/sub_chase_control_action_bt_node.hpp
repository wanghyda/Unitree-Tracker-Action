#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_CHASE_CONTROL_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_CHASE_CONTROL_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/chase_control.hpp"

namespace rm_autonomy
{

class SubChaseControlActionBTNode : public BT::RosTopicSubNode<rm_autonomy_interfaces::msg::ChaseControl>
{
public:
  SubChaseControlActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<rm_autonomy_interfaces::msg::ChaseControl>("chase_control")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::ChaseControl> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};

}  // namespace rm_autonomy

#endif  // RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_CHASE_CONTROL_ACTION_BT_NODE_HPP_