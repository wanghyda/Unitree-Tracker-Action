#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_ARENA_STATUS_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_ARENA_STATUS_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/arena_status.hpp"

namespace rm_autonomy
{
class SubArenaStatusActionBTNode : public BT::RosTopicSubNode<rm_autonomy_interfaces::msg::ArenaStatus>
{
public:
  SubArenaStatusActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<rm_autonomy_interfaces::msg::ArenaStatus>("arena_status")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::ArenaStatus> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_ARENA_STATUS_HPP_