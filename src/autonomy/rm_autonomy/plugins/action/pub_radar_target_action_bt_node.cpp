#include "rm_autonomy/plugins/action/pub_radar_target_action_bt_node.hpp"

namespace rm_autonomy
{

PubRadarTargetActionBTNode::PubRadarTargetActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: RosTopicPubNode<rm_autonomy_interfaces::msg::RadarTarget>(name, conf, params)
{
}

bool PubRadarTargetActionBTNode::setMessage(rm_autonomy_interfaces::msg::RadarTarget & msg)
{
  auto enemy_autoaim_position_msg = getInput<geometry_msgs::msg::Point>("enemy_autoaim_position");
  auto enemy_autoaim_id_msg = getInput<uint8_t>("enemy_autoaim_id");
  if (!enemy_autoaim_position_msg || !enemy_autoaim_id_msg) {
    msg.target_id = 0;
    msg.target_map_x = 0;
    msg.target_map_y = 0;
    return true;
    // throw BT::RuntimeError("error reading port [RadarTarget]:", enemy_autoaim_id_msg.error());
  }
  msg.target_id = enemy_autoaim_id_msg.value();
  msg.target_map_x = enemy_autoaim_position_msg.value().x;
  msg.target_map_y = enemy_autoaim_position_msg.value().y;
  RCLCPP_INFO_STREAM(logger_,std::fixed << std::setprecision(1)
    << "[pub_radar_target_action_bt_node] "
    << msg.target_id << ", "
    << msg.target_map_x << ", "
    << msg.target_map_y );
  return true;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::PubRadarTargetActionBTNode, "PubRadarTargetActionBTNode");