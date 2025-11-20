#include "rm_autonomy/plugins/action/adjust_gimbal_yaw_action_bt_node.hpp"
#include <cmath>
#include "rm_autonomy/bt_conversions.hpp"
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

namespace rm_autonomy {
    AdjustGimbalYawActionBTNode::AdjustGimbalYawActionBTNode(const std::string& name, const BT::NodeConfig& conf,
                                                             const BT::RosNodeParams& params)
        : BT::RosTopicPubNode<auto_aim_interfaces::msg::GimbalControl>(name, conf, params) {}

    bool AdjustGimbalYawActionBTNode::setMessage(auto_aim_interfaces::msg::GimbalControl& msg) {
        auto current_location_msg = getInput<geometry_msgs::msg::TransformStamped>("current_location");
        auto gimbal2_yaw_msg = getInput<std_msgs::msg::Float32>("gimbal2_yaw");
        auto target_pose_msg = getInput<geometry_msgs::msg::PoseStamped>("target_location");
        if(!current_location_msg) {
            throw BT::RuntimeError("error reading port [current_location_msg]:", current_location_msg.error());
        }
        if(!gimbal2_yaw_msg) {
            throw BT::RuntimeError("error reading port [gimbal2_yaw_msg]:", gimbal2_yaw_msg.error());
        }
        if(!target_pose_msg) {
            throw BT::RuntimeError("error reading port [target_pose_msg]:", target_pose_msg.error());
        }

        auto current_position = current_location_msg.value().transform.translation;
        double gimbal2_yaw = gimbal2_yaw_msg.value().data;
        auto target_pose = target_pose_msg.value().pose.position;

        double dx = target_pose.x - current_position.x;
        double dy = target_pose.y - current_position.y;

        tf2::Transform current_transform;
        tf2::fromMsg(current_location_msg.value().transform, current_transform);
    
        // Calculate the inverse of the transformation matrix
        tf2::Matrix3x3 m(current_transform.getRotation());
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw); 

        //TODO: check orientation
        double final_yaw = atan2(dy, dx) - (gimbal2_yaw+yaw);
        std::cout<< "next_yaw: "<<(final_yaw*180.0/3.14)<<std::endl;
        std::cout<<"current_gimbal_yaw: "<<gimbal2_yaw<<std::endl;

        msg.is_hero = false;
        msg.yaw = yaw;
        msg.pitch = 5.0f;  // pitch value as a trigger
        return true;
    }
}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::AdjustGimbalYawActionBTNode, "AdjustGimbalYawActionBTNode");
