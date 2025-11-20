#ifndef RM_AUTONOMY__PLUGINS__ACTION__LOCALIZATION_CONFIRM_BT_NODE
#define RM_AUTONOMY__PLUGINS__ACTION__LOCALIZATION_CONFIRM_BT_NODE

#include "behaviortree_cpp/action_node.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>

#include <behaviortree_cpp/basic_types.h>
namespace rm_autonomy

{
  class LocalizationConfirmAs: public BT::StatefulActionNode
  {
public:
    LocalizationConfirmAs(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;
    static BT::PortsList providedPorts()
  {
    return {BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location")};
  }

    private:
    int tick_times=0;
    int finished_time=0;
    geometry_msgs::msg::TransformStamped last_position;
    rclcpp::Logger logger_{rclcpp::get_logger("localization_confirm")};
  };
} // namespace rm_autonomy

#endif