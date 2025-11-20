#ifndef RM_AUTONOMY__PLUGINS__ACTION__ENEMY_AUTOAIM_DETECTED_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__ENEMY_AUTOAIM_DETECTED_HPP_

#include "rm_autonomy_interfaces/msg/autoaim_communication.hpp"
#include "rm_autonomy_interfaces/msg/game_status.hpp"
#include "rm_autonomy_interfaces/msg/all_robot_hp.hpp"
#include "rm_autonomy_interfaces/msg/self_state.hpp"
#include "rm_autonomy_interfaces/msg/invincible_target.hpp"
#include "rm_autonomy_interfaces/msg/chase_control.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "behaviortree_cpp/condition_node.h"
#include "geometry_msgs/msg/point.hpp"
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>

namespace rm_autonomy
{

/**
 * @brief condition that judge if 
 * @param[in] message communication from upper to lower
 */
class EnemyAutoaimDetectedCondition : public BT::SimpleConditionNode
{
public:
  EnemyAutoaimDetectedCondition(const std::string & name, const BT::NodeConfig & config);
  BT::NodeStatus detectEnemyStatus();
  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::Point>("enemy_autoaim_position"),
            BT::InputPort<rm_autonomy_interfaces::msg::GameStatus>("game_status"),
            BT::InputPort<rm_autonomy_interfaces::msg::AutoaimCommunication>("autoaim_communication"),
            BT::InputPort<rm_autonomy_interfaces::msg::AllRobotHP>("all_robot_hp"),
            BT::InputPort<rm_autonomy_interfaces::msg::SelfState>("message"),
            //BT::InputPort<std::string>("is_chasing"),
            //BT::InputPort<rm_autonomy_interfaces::msg::InvincibleTarget>("invincible_target"),
            //BT::InputPort<rm_autonomy_interfaces::msg::ChaseControl>("chase_control"),
            BT::OutputPort<std::string>("enemy_area_id"),};
  }
private:
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
  rclcpp::Time last_chase_begin_time_;
  //uint8_t is_chasing_;
  //std::string last_chase_enemy_area_id_;
};  // namespace rm_autonomy
}
#endif  // RM_AUTONOMY__PLUGINS__ACTION__ENEMY_AUTOAIM_DETECTED_HPP_