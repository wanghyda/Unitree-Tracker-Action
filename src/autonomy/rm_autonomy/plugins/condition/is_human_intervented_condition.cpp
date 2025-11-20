#include "rm_autonomy/plugins/condition/is_human_intervented_condition.hpp"

namespace rm_autonomy
{

IsHumanInterventedCondition::IsHumanInterventedCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&IsHumanInterventedCondition::checkHumanIntervention, this), config)
{
}

BT::NodeStatus IsHumanInterventedCondition::checkHumanIntervention()
{
  auto human_intervention_msg = getInput<rm_autonomy_interfaces::msg::HumanIntervention>("human_intervention");
  if (!human_intervention_msg) {
    std::cout << "missing required input [Human Intervention]" << '\n';
    return BT::NodeStatus::FAILURE;
  }
  // switch(human_intervention_msg->command_header)
  // {
  //   case 128:
  //     intervented_flag_ = true;
  //     break;
  //   case 192:
  //     timed_intervented_flag_ = true;
  //     break;
  // }
  if(human_intervention_msg->command_header == 0){
    setOutput("dart_command", 0);
  }else if(human_intervention_msg->command_header == 1){
    setOutput("dart_command", 1);
  }

  if(human_intervention_msg->goal_pose_x != 0) {
    intervented_flag_ = true;
  }
  
  if(intervented_flag_) {
    return BT::NodeStatus::SUCCESS;
  } else if (timed_intervented_flag_){
    last_intervention_time_ = this->node_->get_clock()->now();
    return BT::NodeStatus::SUCCESS;
  } else if (this->node_->get_clock()->now() - last_intervention_time_ < rclcpp::Duration::from_seconds(30)) {
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::IsHumanInterventedCondition>("IsHumanInterventedCondition");
}
