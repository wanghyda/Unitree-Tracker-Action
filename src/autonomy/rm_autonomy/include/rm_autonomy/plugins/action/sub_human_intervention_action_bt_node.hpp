#ifndef RM_AUTONOMY__PLUGINS__ACTION__SUB_HUMAN_INTERVENTION_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__SUB_HUMAN_INTERVENTION_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/human_intervention.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/int8.hpp"

namespace rm_autonomy
{
class SubHumanInterventionActionBTNode : public BT::RosTopicSubNode<rm_autonomy_interfaces::msg::HumanIntervention>
{
public:
  SubHumanInterventionActionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
      BT::OutputPort<float>("dart_value"),
      BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
      BT::OutputPort<geometry_msgs::msg::PoseStamped>("human_intervention_pose")
    };
  }

  BT::NodeStatus onTick(const std::shared_ptr<rm_autonomy_interfaces::msg::HumanIntervention> & last_msg) override;
private:
  geometry_msgs::msg::PoseStamped last_goal;
  int tick_times=0;
  float last_dart =0;
  rclcpp::Logger logger_{rclcpp::get_logger("SUB_HUMAN_INTERVENTION_ACTION")};
};
}  // namespace rm_autonomy

#endif  //  RM_AUTONOMY__PLUGINS__ACTION__SUB_HUMAN_INTERVENTION_ACTION_BT_NODE_HPP_
