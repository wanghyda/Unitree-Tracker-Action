#ifndef RM_AUTONOMY__PLUGINS__ACTION__GOAL_REACHED_ACTION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__GOAL_REACHED_ACTION_HPP_

#include "behaviortree_cpp/action_node.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/msg/pose_stamped.hpp"

namespace rm_autonomy
{
  class GoalReachedAction: public BT::SyncActionNode
  {
    public:
    GoalReachedAction(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus tick() override;
    static BT::PortsList providedPorts()
    {
    return {
            BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose")};
    }

    private:
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_{nullptr};
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    rclcpp::Logger logger_{rclcpp::get_logger("goal_reached_action")};
  };
} // namespace rm_autonomy

#endif