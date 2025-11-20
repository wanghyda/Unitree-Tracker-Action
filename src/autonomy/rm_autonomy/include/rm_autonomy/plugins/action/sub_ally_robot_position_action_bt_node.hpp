#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_ALLY_ROBOT_HP_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_ALLY_ROBOT_POSITION_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/ally_robot_position.hpp"

namespace rm_autonomy
{
class SubAllyRobotPositionActionBTNode : public BT::RosTopicSubNode<rm_autonomy_interfaces::msg::AllyRobotPosition>
{
public:
  SubAllyRobotPositionActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<rm_autonomy_interfaces::msg::AllyRobotPosition>("ally_robot_position")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  // RM_BEHAVIOR_TREE__PLUGINS__ACTION__SUB_ALL_ROBOT_HP_HPP_