#include "rm_autonomy/plugins/condition/enemy_autoaim_detected_condition.hpp"
#include "rclcpp/rclcpp.hpp"
namespace rm_autonomy
{
EnemyAutoaimDetectedCondition::EnemyAutoaimDetectedCondition(const std::string & name, const BT::NodeConfig & config)
: BT::SimpleConditionNode(name, std::bind(&EnemyAutoaimDetectedCondition::detectEnemyStatus, this), config)
{
  logger_ = rclcpp::get_logger("EnemyAutoaimDetectedCondition");
}

BT::NodeStatus EnemyAutoaimDetectedCondition::detectEnemyStatus()
{
  auto autoaim_position = getInput<geometry_msgs::msg::Point>("enemy_autoaim_position");
  auto autoaim_info = getInput<rm_autonomy_interfaces::msg::AutoaimCommunication>("autoaim_communication");
  auto game_status = getInput<rm_autonomy_interfaces::msg::GameStatus>("game_status");
  auto all_robot_hp = getInput<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp");
  auto self_state = getInput<rm_autonomy_interfaces::msg::SelfState>("message");
  //auto invincible_target = getInput<rm_autonomy_interfaces::msg::InvincibleTarget>("invincible_target");
  // auto chase_control_msg = getInput<rm_autonomy_interfaces::msg::ChaseControl>("chase_control");
  // auto is_chasing_msg = getInput<std::string>("is_chasing");

  if(!autoaim_position) {
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "missing autoaim position");         
    return BT::NodeStatus::FAILURE;
  }

  if(!autoaim_info){
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "Autoaim Communication not received");
    return BT::NodeStatus::FAILURE;
  }

  if(!game_status){
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "Game Status not received");
    return BT::NodeStatus::FAILURE;
  }

  if(!all_robot_hp){
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "All Robot HP not received");
    return BT::NodeStatus::FAILURE;
  }

  if(!self_state){
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "Self State not received");
    return BT::NodeStatus::FAILURE;
  }

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

  bool is_self_blue = self_state.value().robot_id > 100;
  // int outpost_hp = is_self_blue ? all_robot_hp.value().blue_outpost_hp : all_robot_hp.value().red_outpost_hp;
  int enemy_outpost_hp = is_self_blue ? all_robot_hp.value().red_outpost_hp : all_robot_hp.value().blue_outpost_hp;
  bool enemy_outpost_dead = enemy_outpost_hp == 0;
  bool game_end_in_3 = game_status.value().stage_remain_time < 180;//TODO: check every time before competition
  bool is_enemy_hero = autoaim_info.value().target_id == 1;
  bool is_enemy_sentry = autoaim_info.value().target_id == 7;
  // bool can_chase = chase_control_msg.value().into_chase == 1;
  // bool force_chase = chase_control_msg.value().force_chase == 1;
  //bool is_chasing = is_chasing_msg == "1";

  // if(!can_chase && is_chasing){
  //   last_chase_enemy_area_id_ = "";
  //   RCLCPP_INFO(logger_, "Chase mode is not allowed");
  //   return BT::NodeStatus::FAILURE;
  // }
  
  if(autoaim_position.value().x == 0){
    // if(!force_chase){
    //   RCLCPP_INFO(logger_, "Enemy Autoaim Detection false");
    //   return BT::NodeStatus::FAILURE;
    // }
    // if(last_chase_enemy_area_id_ == ""){
    //   RCLCPP_INFO(logger_, "Force Chase Enemy, but last chase enemy area id is null");
    //   return BT::NodeStatus::FAILURE;
    // }
    // RCLCPP_INFO(logger_, "Force Chase Enemy");
    // setOutput("enemy_area_id", last_chase_enemy_area_id_);
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "Enemy Autoaim Detection false");
    return BT::NodeStatus::FAILURE;
  }

  if(autoaim_position.value().x > 15) {
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "Enemy too far!!");
    return BT::NodeStatus::FAILURE;
  }

  // if(autoaim_position.value().x < 11//TODO: adjust parameters
  //   && autoaim_position.value().x > 10
  //   && autoaim_position.value().y < 4
  //   && autoaim_position.value().y > 3){
  //   last_chase_begin_time_ = rclcpp::Clock().now();
  //   RCLCPP_INFO(logger_, "Enemy is in healing area");
  //   return BT::NodeStatus::FAILURE;
  // }

  if((!is_enemy_sentry)&&(!is_enemy_hero)){
    last_chase_begin_time_ = rclcpp::Clock().now();
    RCLCPP_INFO(logger_, "Autoaim Detected Enemy, but NOT hero or sentry!!!");
    return BT::NodeStatus::FAILURE;
  }

  //invincible check
  if(is_enemy_sentry){
    if(!enemy_outpost_dead){
      last_chase_begin_time_ = rclcpp::Clock().now();
      RCLCPP_INFO(logger_, "Enemy Sentry is invincible");
      return BT::NodeStatus::FAILURE;
    }
  }

  auto now = rclcpp::Clock().now();
  auto elapsed_time = now - last_chase_begin_time_;

  if(elapsed_time > rclcpp::Duration::from_seconds(15)){
    RCLCPP_INFO(logger_, "Stop chasing enemy due to 15s timeout");
    if(elapsed_time <= rclcpp::Duration::from_seconds(25)){
      return BT::NodeStatus::FAILURE;
    }
    last_chase_begin_time_ = now;
  }

  //determine enemy area id
  std::string enemy_area_id;
  //TODO:modify the area settings
  /*     y=7.44
  *   1    |    3
  * ---------------- x=14
  *   2    |    4
  */
  if(autoaim_position.value().y > 7.44){
    if(autoaim_position.value().x > 14){
      enemy_area_id = "1";//upper left
    } else {
      enemy_area_id = "2";//back left
    }
  } else {
    if(autoaim_position.value().x > 14){
      enemy_area_id = "3";//upper right
    } else {
      enemy_area_id  = "4";//back right
    }
  }
  
  std::cout << "enemy_area_id: " << enemy_area_id << std::endl;
  setOutput("enemy_area_id", enemy_area_id);
  // RCLCPP_INFO(logger_, "Enemy Autoaim Detection true");
  return BT::NodeStatus::SUCCESS;
}
}  // namespace rm_autonomy
#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::EnemyAutoaimDetectedCondition>("EnemyAutoaimDetectedCondition");
}