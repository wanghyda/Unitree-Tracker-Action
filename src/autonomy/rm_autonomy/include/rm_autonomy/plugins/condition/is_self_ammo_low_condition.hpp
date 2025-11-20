#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_SELF_AMMO_LOW_AVAILABLE_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_SELF_AMMO_LOW_AVAILABLE_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/self_state.hpp"
#include "std_msgs/msg/int32.hpp"

namespace rm_autonomy {
    class IsSelfAmmoLowCondition : public BT::SimpleConditionNode {
    public:
        IsSelfAmmoLowCondition(const std::string& name, const BT::NodeConfig& config);

        BT::NodeStatus checkSelfAmmoLow();

        static BT::PortsList providedPorts() {
            return { BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("self_state_msg"),
                     BT::InputPort<int>("threshold") };
        }
    };
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_SELF_AMMO_LOW_AVAILABLE_CONDITION_HPP_