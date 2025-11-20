#include "rm_autonomy/plugins/action/check_goal_height_action_bt_node.hpp"
#include "rm_autonomy/polygon.hpp"
#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/basic_types.h>
#include <geometry_msgs/msg/detail/pose_stamped__struct.hpp>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <memory>
#include <rclcpp/logging.hpp>

namespace rm_autonomy 
{
CheckGoalHeightActionBTNode::CheckGoalHeightActionBTNode(
  const std::string & name, const BT::NodeConfig & config)
:BT::SyncActionNode(name,config)
{    
}

BT::NodeStatus CheckGoalHeightActionBTNode::tick(){
    geometry_msgs::msg::TransformStamped current_location;
    getInput<geometry_msgs::msg::TransformStamped>("current_location",current_location);
    geometry_msgs::msg::PoseStamped current_pose;
    current_pose.pose.position.x=current_location.transform.translation.x;
    current_pose.pose.position.y=current_location.transform.translation.y;
    setOutput<geometry_msgs::msg::PoseStamped>("current_position",current_pose);
    geometry_msgs::msg::PoseStamped goal_pose;
    getInput<geometry_msgs::msg::PoseStamped>("goal_pose",goal_pose);
    std::shared_ptr<Polygon> chasing_area;
    getInput<std::shared_ptr<Polygon>>("chasing_area",chasing_area);
    if(!chasing_area)
    {
      RCLCPP_ERROR(logger_,"No chasing area");
      return BT::NodeStatus::FAILURE;
    }
    bool is_in_region,is_goal_in_region;
    is_in_region=chasing_area->contains(current_pose);
    is_goal_in_region=chasing_area->contains(goal_pose);
    if(is_goal_in_region==is_in_region)
    {
        setOutput("height_mode", 0);
        RCLCPP_INFO(logger_, "height no change");
    }else if(is_goal_in_region>is_in_region)
    {
        setOutput("height_mode",1);
        RCLCPP_INFO(logger_, "go up");
    }else {
        setOutput("height_mode", 2);
        RCLCPP_INFO(logger_,"go down");
    }
    return BT::NodeStatus::SUCCESS;
}

}

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::CheckGoalHeightActionBTNode>("CheckGoalHeightActionBTNode");
}