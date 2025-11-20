#ifndef RM_AUTONOMY__PLUGINS__ACTION__SITUATION_JUDGEMENT_ACTION_BTNODE
#define RM_AUTONOMY__PLUGINS__ACTION__SITUATION_JUDGEMENT_ACTION_BTNODE

#include "behaviortree_cpp/action_node.h"
#include "rm_autonomy_interfaces/msg/all_robot_hp.hpp"
#include "rm_autonomy_interfaces/msg/game_status.hpp"
#include "rm_autonomy_interfaces/msg/self_state.hpp"
#include "rm_autonomy_interfaces/msg/ally_robot_position.hpp"


namespace rm_autonomy
{
  class SituationJudgementActionBTNode: public BT::SyncActionNode
  {
    public:
    SituationJudgementActionBTNode(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus tick() override;
    static BT::PortsList providedPorts()
    {
    return {
            BT::InputPort<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp"),
            BT::InputPort<rm_autonomy_interfaces::msg::GameStatus>("game_status"),
            BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("self_state"),
            BT::InputPort<rm_autonomy_interfaces::msg::AllyRobotPosition>("ally_robot_position"),
            BT::OutputPort<float>("hero_y"),
            BT::OutputPort<int>("blue_outpost_hp"),
            BT::OutputPort<int>("blue_base_hp"),
            BT::OutputPort<int>("red_outpost_hp"),
            BT::OutputPort<int>("red_base_hp"),
            BT::OutputPort<int>("remain_time"),
            BT::OutputPort<int>("energy_left"),
            BT::OutputPort<int>("self_hp"),
};
    }

    private:
    rclcpp::Logger logger_{rclcpp::get_logger("SituationJudgementActionBTNode")};
  };
} // namespace rm_autonomy

#endif