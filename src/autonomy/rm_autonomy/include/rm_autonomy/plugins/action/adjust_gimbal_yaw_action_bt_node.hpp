#ifndef RM_AUTONOMY__PLUGINS__ACTION__ADJUST_GIMBAL_YAW_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__ADJUST_GIMBAL_YAW_ACTION_BT_NODE_HPP_
#include "auto_aim_interfaces/msg/gimbal_control.hpp"
#include "behaviortree_cpp/contrib/json.hpp"
#include "behaviortree_ros2/bt_topic_pub_node.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include <std_msgs/msg/float32.hpp>

namespace rm_autonomy {

    class AdjustGimbalYawActionBTNode : public BT::RosTopicPubNode<auto_aim_interfaces::msg::GimbalControl> {
    public:
        AdjustGimbalYawActionBTNode(const std::string& name, const BT::NodeConfig& conf, const BT::RosNodeParams& params);

        static BT::PortsList providedPorts() {
            return { BT::InputPort<geometry_msgs::msg::PoseStamped>("target_location"),
                     BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
                     BT::InputPort<std_msgs::msg::Float32>("gimbal2_yaw") };
        }

        bool setMessage(auto_aim_interfaces::msg::GimbalControl& msg) override;
    };
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__ADJUST_GIMBAL_YAW_ACTION_BT_NODE_HPP_
