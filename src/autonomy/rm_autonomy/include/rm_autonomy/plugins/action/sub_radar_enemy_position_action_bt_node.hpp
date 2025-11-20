#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_RADAR_ENEMY_POSITION_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_RADAR_ENEMY_POSITION_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/radar_enemy_position.hpp"

namespace rm_autonomy
{
class SubRadarEnemyPositionActionBTNode : public BT::RosTopicSubNode<rm_autonomy_interfaces::msg::RadarEnemyPosition>
{
public:
  SubRadarEnemyPositionActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<rm_autonomy_interfaces::msg::RadarEnemyPosition>("radar_enemy_position")};
  }

  BT::NodeStatus onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition> & last_msg) override;
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  //  RM_AUTONOMY__PLUGINS__ACTION__SUB_RADAR_ENEMY_POSITION_ACTION_BT_NODE_HPP_
