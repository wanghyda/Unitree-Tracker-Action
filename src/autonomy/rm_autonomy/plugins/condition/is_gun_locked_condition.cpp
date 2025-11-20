#include "rm_autonomy/plugins/condition/is_gun_locked_condition.hpp"
#include "rclcpp/rclcpp.hpp"

namespace rm_autonomy {
    IsGunLockedCondition::IsGunLockedCondition(const std::string &name, const BT::NodeConfig &config)
        : BT::SimpleConditionNode(name, std::bind(&IsGunLockedCondition::checkGunLocked, this), config) {
            gun_locked_ = false;
        }

    BT::NodeStatus IsGunLockedCondition::checkGunLocked() {
        auto msg = getInput<rm_autonomy_interfaces::msg::FireTrigger>("fire_trigger_value");
        if (!msg) {
            std::cout << "missing required input [fire_trigger_value]" << '\n';
            return BT::NodeStatus::FAILURE;
        }
        //TODO: add game status
        // std::unordered_map<int, std::string> game_status_map = {
        //     { 0, "Not Begginning" },     { 1, "Preparing" },          { 2, "15s Checking" },
        //     { 3, "5 seconds counting" }, { 4, "Competition Begin!" }, { 5, "Competition End!" },
        // };
        int gun_locked_value = msg->fire_trigger;
        gun_locked_ = gun_locked_value == 1;
        return gun_locked_ ? BT::NodeStatus::FAILURE : BT::NodeStatus::SUCCESS;
    }

}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory) {
    factory.registerNodeType<rm_autonomy::IsGunLockedCondition>("IsGunLockedCondition");
}