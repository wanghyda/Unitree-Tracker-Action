#ifndef RM_AUTONOY__PLUGINS__ACTION__UPDATE_ARMOR_DEAD_HISTORY_ACTION_BT_NODE_HPP_
#define RM_AUTONOY__PLUGINS__ACTION__UPDATE_ARMOR_DEAD_HISTORY_ACTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "rm_autonomy_interfaces/msg/all_robot_hp.hpp"
#include "rm_autonomy_interfaces/msg/game_status.hpp"
#include "std_msgs/msg/int16_multi_array.hpp"

namespace rm_autonomy {
    class UpdateArmorDeadHistoryActionBTNode : public BT::SyncActionNode {
    public:
        explicit UpdateArmorDeadHistoryActionBTNode(const std::string& name, const BT::NodeConfig& conf);

        static BT::PortsList providedPorts() {
            return { BT::InputPort<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp"),
                     BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("self_state"),
                     BT::InputPort<rm_autonomy_interfaces::msg::GameStatus>("game_status"),
                     BT::InputPort<rm_autonomy_interfaces::msg::AutoAimCommunication>("auto_aim_communication") };
            BT::OutputPort<std_msgs::msg::Int16MultiArray>("dead_enemy_robot_ids");
        }

        BT::NodeStatus tick() override;

        std::unordered_map<int, int> enemy_hp_;

        std::vector<int> dead_robot_ids_;

        // revival_status_: 1 for reviving, 0 for not reviving
        std::vector<int> revival_status_{ 0, 0, 0, 0, 0, 0 };

        std::unordered_map<int, int> last_revive_time_ {
            { 1, 420 }, { 2, 420 }, { 3, 420 }, { 4, 420 }, { 5, 420 }, { 7, 420 };
        };
    };
}  // namespace rm_autonomy

#endif  // RM_AUTONOY__PLUGINS__ACTION__UPDATE_ARMOR_DEAD_HISTORY_ACTION_BT_NODE_HPP_