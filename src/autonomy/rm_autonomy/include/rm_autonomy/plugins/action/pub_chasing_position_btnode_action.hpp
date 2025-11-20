// rm_autonomy/plugins/action/pub_chasing_position_btnode_action.hpp

#ifndef RM_AUTONOMY__PLUGINS__ACTION__PUB_CHASING_POSITION_BTNODE_ACTION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__PUB_CHASING_POSITION_BTNODE_ACTION_HPP_

#include <string>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include <thread>

namespace rm_autonomy
{

class PubChasingPositionAction : public BT::SyncActionNode
{
public:
  PubChasingPositionAction(const std::string & name, const BT::NodeConfig & config);
  ~PubChasingPositionAction()
  {
    if (rclcpp::ok())
    rclcpp::shutdown(); // 或 executor_.cancel()
    if (executor_thread_.joinable()) executor_thread_.join();
  }

  static BT::PortsList providedPorts()
  {
    return {
        BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
            //BT::InputPort<rm_autonomy_interfaces::msg::InvincibleTarget>("invincible_target"),
            //BT::InputPort<rm_autonomy_interfaces::msg::ChaseControl>("chase_control"),
            BT::OutputPort<geometry_msgs::msg::PoseStamped>("chasing_goal") };
  }

  BT::NodeStatus tick() override;

private:
  void poseCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg);

  rclcpp::Logger logger_;
  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr subscription_;
  std::optional<geometry_msgs::msg::PointStamped> last_pose_;
  std::thread executor_thread_;
};

}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__PUB_CHASING_POSITION_BTNODE_ACTION_HPP_