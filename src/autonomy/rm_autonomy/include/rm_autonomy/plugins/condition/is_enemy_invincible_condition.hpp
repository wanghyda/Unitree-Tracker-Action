#ifndef RM_AUTONOMY__PLUGINS__CONDITION__IS_ENEMY_INVINCIBLE_HPP_
#define RM_AUTONOMY__PLUGINS__CONDITION__IS_ENEMY_INVINCIBLE_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/all_robot_hp.hpp"
#include "rm_autonomy_interfaces/msg/auto_aim_communication.hpp"
#include "rm_autonomy_interfaces/msg/game_status.hpp"
#include "rm_autonomy_interfaces/msg/self_state.hpp"

namespace rm_autonomy {
    class IsEnemyInvincible : public BT::SimpleConditionNode {
    public:
        IsEnemyInvincible(const std::string& name, const BT::NodeConfig& config);

        BT::NodeStatus checkEnemyInvincible();

        static BT::PortsList providedPorts() {
            return { BT::InputPort<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp"),
                     BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("self_state"),
                     BT::InputPort<std_msgs::msg::Int16MultiArray>("enemy_revival_status"),
                     BT::InputPort<rm_autonomy_interfaces::msg::AutoAimCommunication>("auto_aim_communication") };
        }

        bool is_enemy_invincible_;
    };
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__CONDITION__IS_ENEMY_INVINCIBLE_HPP_