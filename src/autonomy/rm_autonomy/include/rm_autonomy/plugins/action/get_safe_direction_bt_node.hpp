#ifndef RM_AUTONOMY__PLUGINS__ACTION__GET_SAFE_DIRECTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__GET_SAFE_DIRECTION_BT_NODE_HPP_

#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include "geometry_msgs/msg/twist.hpp"
#include"geometry_msgs/msg/transform_stamped.hpp"
#include "rm_autonomy/occupancy_grid_wrapper.hpp"

namespace rm_autonomy
{
class GetSafeDirectionBTNode : public BT::RosTopicSubNode<nav_msgs::msg::OccupancyGrid>
{
public:
GetSafeDirectionBTNode(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("topic_name"),
       BT::OutputPort<float>("safe_direction"),
       BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location")
    };
  }
   double findFreeDirection(double robot_x, double robot_y, double radius,OccupancyGridWrapper& wrapper);
  BT::NodeStatus onTick(const std::shared_ptr<nav_msgs::msg::OccupancyGrid> & last_msg) override;
private:
  std::shared_ptr<nav_msgs::msg::OccupancyGrid> costmap_sub_;
  rclcpp::Logger logger_{rclcpp::get_logger("rm_autonomy")};
};
}  // namespace rm_autonomy

#endif  
