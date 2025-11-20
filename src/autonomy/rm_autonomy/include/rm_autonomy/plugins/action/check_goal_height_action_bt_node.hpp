#ifndef RM_AUTONOMY__PLUGINS__ACTION__GET_CURRENT_HEIGHT_BT_NODE
#define RM_AUTONOMY__PLUGINS__ACTION__GET_CURRENT_HEIGHT_BT_NODE

#include "behaviortree_cpp/action_node.h"
#include"rm_autonomy/polygon.hpp"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <behaviortree_cpp/basic_types.h>
#include <geometry_msgs/msg/detail/pose_stamped__struct.hpp>
namespace rm_autonomy
{
  class CheckGoalHeightActionBTNode: public BT::SyncActionNode
  {
public:
    CheckGoalHeightActionBTNode(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus tick() override;
    static BT::PortsList providedPorts()
    {
    return {
            BT::InputPort<std::shared_ptr<Polygon>>("chasing_area"),
        BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
        BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose"),
        BT::OutputPort<geometry_msgs::msg::PoseStamped>("current_position"),
            BT::OutputPort<int>("height_mode"),
            };
    }

    private:
    rclcpp::Logger logger_{rclcpp::get_logger("check_goal_height")};
  };
} // namespace rm_autonomy

#endif