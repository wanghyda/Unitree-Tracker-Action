#include "rm_autonomy/plugins/condition/is_in_defence_area_condition.hpp"

namespace rm_autonomy {
    IsInDefenceAreaCondition::IsInDefenceAreaCondition(const std::string& name, const BT::NodeConfig& config)
        : BT::SimpleConditionNode(name, std::bind(&IsInDefenceAreaCondition::checkInDefenceArea, this), config) {}

    BT::NodeStatus IsInDefenceAreaCondition::checkInDefenceArea() {
        auto current_location_msg = getInput<geometry_msgs::msg::TransformStamped>("current_location");
        if(!current_location_msg) {
            throw BT::RuntimeError("error reading port [current_location_msg]:", current_location_msg.error());
        }
        auto current_position = current_location_msg.value().transform.translation;

        // Check if the current position is in the defence area
        // TODO: set area
        bool x_in_defence_area = current_position.x > 10 && current_position.x < 3.5;
        bool y_in_defence_area = current_position.y > 10 && current_position.y < 3.5;
        if(x_in_defence_area && y_in_defence_area) {
            return BT::NodeStatus::SUCCESS;
        } else {
            return BT::NodeStatus::FAILURE;
        }
    }
}  // namespace rm_autonomy

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory) {
    factory.registerNodeType<rm_autonomy::IsInDefenceAreaCondition>("IsInDefenceAreaCondition");
}