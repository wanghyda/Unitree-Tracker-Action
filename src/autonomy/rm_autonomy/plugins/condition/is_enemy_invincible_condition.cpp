#include "rm_autonomy/plugins/condition/is_enemy_invincible.hpp"
#include <unordered_map>

namespace rm_autonomy {
    IsEnemyInvincible::IsEnemyInvincible(const std::string& name, const BT::NodeConfig& config)
        : BT::SimpleConditionNode(name, std::bind(&IsEnemyInvincible::checkEnemyInvincible, this), config) {
        is_enemy_invincible_ = false;
    }

    BT::NodeStatus IsEnemyInvincible::checkEnemyInvincible() {
        auto all_robot_hp_msg = getInput<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp");
        auto self_state_msg = getInput<rm_autonomy_interfaces::msg::SelfState>("self_state");
        auto enemy_revival_status_msg = getInput<std_msgs::msg::Int16MultiArray>("enemy_revival_status");
        auto auto_aim_communication_msg = getInput<rm_autonomy_interfaces::msg::AutoAimCommunication>("auto_aim_communication");
        if(!all_robot_hp_msg) {
            RCLCPP_ERROR(node->get_logger(), "all_robot_hp_msg is null");
            return BT::NodeStatus::FAILURE;
        }
        if(!self_state_msg) {
            RCLCPP_ERROR(node->get_logger(), "self_state_msg is null");
            return BT::NodeStatus::FAILURE;
        }

        if(!enemy_revival_status_msg) {
            RCLCPP_ERROR(node->get_logger(), "enemy_revival_status_msg is null");
            return BT::NodeStatus::FAILURE;
        }
        
        if(!auto_aim_communication_msg) {
            RCLCPP_ERROR(node->get_logger(), "auto_aim_communication_msg is null");
            return BT::NodeStatus::FAILURE;
        }

        // TODO: adjust constants
        bool checkHealingArea = [](const geometry_msgs::msg::Point& point) {
            return point.x > 5 && point.x < 10 && point.y > 5 && point.y < 10;
        };

        bool checkExchangeArea = [](const geometry_msgs::msg::Point& point) {
            return point.x > 15 && point.x < 10 && point.y > 5 && point.y < 10;
        };

        // conditions
        bool is_self_blue = self_state_msg->robot_id > 100;
        bool is_enemy_outpost_dead =
            (all_robot_hp_msg->red_outpost_hp == 0 && is_self_blue) || (all_robot_hp_msg->blue_outpost_hp == 0 && !is_self_blue);
        bool is_sentry = auto_aim_communication_msg->target_id == 7;
        bool is_enemy_in_special_area = checkHealingArea(auto_aim_communication_msg->target_point) ||
            checkExchangeArea(auto_aim_communication_msg->target_point);
        bool is_invincible_sentry = is_sentry && is_enemy_outpost_dead;
        bool is_enemy_reviving = enemy_revival_status_msg->data[auto_aim_communication_msg->target_id] == 1;
        
        is_enemy_invincible_ = is_invincible_sentry || is_enemy_in_special_area || is_enemy_reviving;

        return is_enemy_invincible_ ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
    }
}  // namespace rm_autonomy