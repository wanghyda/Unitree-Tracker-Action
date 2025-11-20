#include "rm_autonomy/plugins/action/update_armor_dead_history_action_bt_node.hpp"
#include <unordered_map>

namespace rm_autonomy {
    UpdateArmorDeadHistoryActionBTNode::UpdateArmorDeadHistoryActionBTNode(const std::string& name, const BT::NodeConfig& conf)
        : BT::SimpleActionNode(name, conf) {}

    BT::NodeStatus UpdateArmorDeadHistoryActionBTNode::tick() {
        auto all_robot_hp_msg = getInput<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp");
        auto self_state_msg = getInput<rm_autonomy_interfaces::msg::SelfState>("self_state");
        auto game_status_msg = getInput<rm_autonomy_interfaces::msg::GameStatus>("game_status");
        auto auto_aim_communication_msg = getInput<rm_autonomy_interfaces::msg::AutoAimCommunication>("auto_aim_communication");
        if(!all_robot_hp_msg) {
            throw BT::RuntimeError("error reading port [all_robot_hp]:", all_robot_hp_msg.error());
        }
        if(!self_state_msg) {
            throw BT::RuntimeError("error reading port [self_state]:", self_state_msg.error());
        }
        if(!game_status_msg) {
            throw BT::RuntimeError("error reading port [game_status]:", game_status_msg.error());
        }
        if(!auto_aim_communication_msg) {
            throw BT::RuntimeError("error reading port [auto_aim_communication]:", auto_aim_communication_msg.error());
        }

        bool is_self_blue = self_state_msg->robot_id > 100;

        if is_self_blue {
            enemy_hp_ = {
                { 1, all_robot_hp_msg->red_1_hp }, { 2, all_robot_hp_msg->red_2_hp }, { 3, all_robot_hp_msg->red_3_hp },
                { 4, all_robot_hp_msg->red_4_hp }, { 5, all_robot_hp_msg->red_5_hp }, { 7, all_robot_hp_msg->red_7_hp }
            };
        } else {
            enemy_hp_ = { { 1, all_robot_hp_msg->blue_1_hp }, { 2, all_robot_hp_msg->blue_2_hp },
                          { 3, all_robot_hp_msg->blue_3_hp }, { 4, all_robot_hp_msg->blue_4_hp },
                          { 5, all_robot_hp_msg->blue_5_hp }, { 7, all_robot_hp_msg->blue_7_hp } };
        }

        for(auto& [robot_id, hp] : enemy_hp_) {
            if(hp == 0) {
                dead_robot_ids_.push_back(robot_id);
            }
        }

        int current_time = game_status_msg->game_time;
        if(!dead_robot_ids_.empty()) {
            for(int robot_id : dead_robot_ids_) {
                if(enemy_hp_[robot_id] > 0) {  // 该机器人复活
                    if(robot_id == 7) {        // 敌方哨兵复活
                        revival_status_[robot_id] = 1;
                        last_revive_time_[robot_id] = current_time;
                    } else {                             // 其他机器人复活
                        if(enemy_hp_[robot_id] > 100) {  // 金币买活无敌7秒
                            revival_status_[robot_id] = 1;
                            last_revive_time_[robot_id] = current_time;
                        } else {  // 正常复活无敌10秒
                            revival_status_[robot_id] = 1;
                            last_revive_time_[robot_id] = current_time;
                        }
                    }
                    dead_robot_ids_.erase(std::remove(dead_robot_ids_.begin(), dead_robot_ids_.end(), robot_id),
                                          dead_robot_ids_.end());
                }
            }
        }

        // 更新复活状态
        for(auto& [robot_id, status] : revival_status_) {
            if(status == 1) {
                int revive_duration = (robot_id == 7) ? 7 : 10;
                if(current_time - last_revive_time_[robot_id] >= revive_duration) {
                    revival_status_[robot_id] = 0;
                }
            }
        }

        auto revival_robot_ids_msg = std::make_shared<std_msgs::msg::Int16MultiArray>();
        revival_robot_ids_msg->data.resize(8);  // 确保数组大小足够
        for(const auto& [robot_id, status] : revival_status_) {
            revival_robot_ids_msg->data[robot_id] = status;
        }
        setOutput("revival_enemy_robot_ids", revival_robot_ids_msg);
        return BT::NodeStatus::SUCCESS;
    }
}  // namespace rm_autonomy
#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::UpdateArmorDeadHistoryActionBTNode, "UpdateArmorDeadHistoryActionBTNode");
