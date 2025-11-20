#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_IN_DEFENCE_AREA_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_IN_DEFENCE_AREA_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

namespace rm_autonomy {
    class IsInDefenceAreaCondition : public BT::SimpleConditionNode {
    public:
        IsInDefenceAreaCondition(const std::string& name, const BT::NodeConfiguration& config);

        static BT::PortsList providedPorts() {
            return { BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location") };
        }

        BT::NodeStatus checkInDefenceArea();
    };

}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_IN_DEFENCE_AREA_CONDITION_HPP_