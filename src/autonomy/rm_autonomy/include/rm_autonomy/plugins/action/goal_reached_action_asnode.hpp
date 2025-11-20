#ifndef RM_AUTONOMY__PLUGINS__ACTION__GOAL_REACHED_ACTION_ASNODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__GOAL_REACHED_ACTION_ASNODE_HPP_

#include "behaviortree_cpp/action_node.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <behaviortree_cpp/basic_types.h>
namespace rm_autonomy
{
  class GoalReachedActionAs: public BT::StatefulActionNode
  {
public:
    GoalReachedActionAs(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;
    static BT::PortsList providedPorts()
    {
    return {
            BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose"),
            BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location")};
    }

    private:
    geometry_msgs::msg::TransformStamped last_pose;
    geometry_msgs::msg::PoseStamped goal;
    int tick_times;
    rclcpp::Logger logger_{rclcpp::get_logger("goal_reached_action")};
  };
} // namespace rm_autonomy

#endif