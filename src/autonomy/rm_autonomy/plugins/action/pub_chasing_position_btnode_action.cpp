#include "rm_autonomy/plugins/action/pub_chasing_position_btnode_action.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <behaviortree_cpp/basic_types.h>
#include <rcutils/types/rcutils_ret.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <stdexcept>
#include <vector>
#include <optional> 
namespace rm_autonomy
{
PubChasingPositionAction::PubChasingPositionAction(const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config),
logger_(rclcpp::get_logger("PubChasingPositionAction"))
{
   node_ = std::make_shared<rclcpp::Node>("pub_chasing_position_action");

  subscription_ = node_->create_subscription<geometry_msgs::msg::PointStamped>(
    "/pedestrian_point", 10,
    std::bind(&PubChasingPositionAction::poseCallback, this, std::placeholders::_1));

    executor_thread_ = std::thread([this]() {
  rclcpp::spin(node_);
});

}

void PubChasingPositionAction::poseCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg)
{
  last_pose_ = *msg;
  RCLCPP_DEBUG(logger_, "Received point (x=%.2f, y=%.2f)", msg->point.x, msg->point.y);
}

BT::NodeStatus PubChasingPositionAction::tick()
{
  geometry_msgs::msg::Point autoaim_position;

  
        geometry_msgs::msg::TransformStamped current_pose;
        getInput<geometry_msgs::msg::TransformStamped>("current_location",current_pose);
        if(last_pose_->point.x!=0)
        {
          
          autoaim_position.x = -last_pose_->point.x+current_pose.transform.translation.x;
          autoaim_position.y = -last_pose_->point.y*std::sqrt(0.5)+current_pose.transform.translation.y;
        }else{
          RCLCPP_INFO(logger_, "字段是None: " );
          return BT::NodeStatus::FAILURE;
        }

        










 

  //auto invincible_target = getInput<rm_autonomy_interfaces::msg::InvincibleTarget>("invincible_target");
  // auto chase_control_msg = getInput<rm_autonomy_interfaces::msg::ChaseControl>("chase_control");
  // auto is_chasing_msg = getInput<std::string>("is_chasing");



  



  // if(!invincible_target){
  //   RCLCPP_INFO(logger_, "Invincible Target not received");
  //   return BT::NodeStatus::FAILURE;
  // }

  // if(!chase_control_msg){
  //   last_chase_begin_time_ = rclcpp::Clock().now();
  //   RCLCPP_INFO(logger_, "Chase Control not received");
  //   return BT::NodeStatus::FAILURE;
  // }

  // if(!is_chasing_msg){
  //   last_chase_begin_time_ = rclcpp::Clock().now();
  //   RCLCPP_INFO(logger_, "Is Chasing not received");
  //   return BT::NodeStatus::FAILURE;
  // }

  // bool can_chase = chase_control_msg.value().into_chase == 1;
  // bool force_chase = chase_control_msg.value().force_chase == 1;
  //bool is_chasing = is_chasing_msg == "1";

  // if(!can_chase && is_chasing){
  //   last_chase_enemy_area_id_ = "";
  //   RCLCPP_INFO(logger_, "Chase mode is not allowed");
  //   return BT::NodeStatus::FAILURE;
  // }
  



  // if(autoaim_position.value().x < 11//TODO: adjust parameters
  //   && autoaim_position.value().x > 10
  //   && autoaim_position.value().y < 4
  //   && autoaim_position.value().y > 3){
  //   last_chase_begin_time_ = rclcpp::Clock().now();
  //   RCLCPP_INFO(logger_, "Enemy is in healing area");
  //   return BT::NodeStatus::FAILURE;
  // }



  // auto now = rclcpp::Clock().now();
  // auto elapsed_time = now - last_chase_begin_time_;

  // if(elapsed_time > rclcpp::Duration::from_seconds(15)){
  //   RCLCPP_INFO(logger_, "Stop chasing enemy due to 15s timeout");
  //   if(elapsed_time <= rclcpp::Duration::from_seconds(25)){
  //     return BT::NodeStatus::FAILURE;
  //   }
  //   last_chase_begin_time_ = now;
  // }

  geometry_msgs::msg::PoseStamped goal;
  float goal_distance = 0.5;
  float dx = autoaim_position.x - current_pose.transform.translation.x;
  float dy = autoaim_position.y - current_pose.transform.translation.y;
  float current_distance = std::sqrt(dx * dx + dy * dy);

  // 计算目标位置
  if (current_distance > 1e-6) {
    goal.pose.position.x = autoaim_position.x - goal_distance * (dx / current_distance);
    goal.pose.position.y = autoaim_position.y - goal_distance * (dy / current_distance);
  } else {
    goal.pose.position.x = autoaim_position.x;
    goal.pose.position.y = autoaim_position.y;
  }

  double yaw = std::atan2(dy, dx);
  geometry_msgs::msg::Quaternion q;
  q.x = 0.0;
  q.y = 0.0;
  q.z = std::sin(yaw / 2.0);
  q.w = std::cos(yaw / 2.0);
  goal.pose.orientation = q;


  

setOutput("chasing_goal", goal);
  return BT::NodeStatus::SUCCESS;
}
}  // namespace rm_autonomy
#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::PubChasingPositionAction>("PubChasingPositionAction");
}