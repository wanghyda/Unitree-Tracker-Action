#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_HUMAN_INTERVENTED_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_HUMAN_INTERVENTED_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/human_intervention.hpp"
#include "std_msgs/msg/int8.hpp"
#include <chrono>
#include <rclcpp/duration.hpp>
#include <rclcpp/rclcpp.hpp>

namespace rm_autonomy
{
class IsHumanInterventedCondition : public BT::SimpleConditionNode
{
public:
  IsHumanInterventedCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkHumanIntervention();

  inline static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::HumanIntervention>("human_intervention"),
            BT::OutputPort<std_msgs::msg::Int8>("dart_command")};
  }
private:
  bool intervented_flag_; // permanent flag
  bool timed_intervented_flag_; // wait for 30s flag
  rclcpp::Time last_intervention_time_;
  std::shared_ptr<rclcpp::Node> node_;
};

}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_HUMAN_INTERVENTED_CONDITION_HPP_