#include "rm_autonomy/plugins/action/get_safe_direction_bt_node.hpp"
#include "rm_autonomy/occupancy_grid_wrapper.hpp"
#include <behaviortree_cpp/basic_types.h>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <nav_msgs/msg/detail/occupancy_grid__struct.hpp>
#include <rclcpp/logging.hpp>

namespace rm_autonomy
{

GetSafeDirectionBTNode::GetSafeDirectionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<nav_msgs::msg::OccupancyGrid>(name, conf, params)
{
}

BT::NodeStatus GetSafeDirectionBTNode::onTick(
  const std::shared_ptr<nav_msgs::msg::OccupancyGrid> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
      OccupancyGridWrapper wrapper(last_msg);
      geometry_msgs::msg::TransformStamped current_location;
      getInput("current_location",current_location);
      float theta = findFreeDirection(current_location.transform.translation.x, current_location.transform.translation.y,0.5, wrapper) *2 * M_PI / 360;
      if(theta==0){
        return BT::NodeStatus::FAILURE;
      }
      setOutput("safe_direction",theta);
  }
  return BT::NodeStatus::SUCCESS;
}
 double GetSafeDirectionBTNode::findFreeDirection(double robot_x, double robot_y, double radius,OccupancyGridWrapper& wrapper)
  {
    const int num_rays = 360;  // 每1度扫描一条线
    const double delta_theta = 2 * M_PI / num_rays;

    std::vector<bool> is_free(num_rays, false);
    unsigned int mx_robot, my_robot;

    // 扫描每个方向是否可通行
    for (int i = 0; i < num_rays; ++i) {
      double theta = i * delta_theta;
      double check_x = robot_x + radius * std::cos(theta);
      double check_y = robot_y + radius * std::sin(theta);

      int mx, my;
      if (wrapper.worldToMap(check_x, check_y, mx, my)) {
        auto cost = wrapper.getCost(mx, my);
        if (cost < 254) {
          is_free[i] = true;
        }
      }
    }

    // 寻找连续的 free 区域（gap）
    std::vector<std::pair<double, double>> gaps;
    int gap_start = -1;
    for (int i = 0; i < num_rays; ++i) {
      if (is_free[i]) {
        if (gap_start == -1) gap_start = i;
      } else {
        if (gap_start != -1) {
          gaps.push_back({gap_start * delta_theta, (i - 1) * delta_theta});
          gap_start = -1;
        }
      }
    }
    if (gap_start != -1) {
      gaps.push_back({gap_start * delta_theta, (num_rays - 1) * delta_theta});
    }

    if (gaps.empty()) {
      RCLCPP_ERROR(logger_, "No free gap!");
      return 0;
    }

    // 选择最大 gap
    auto max_gap = std::max_element(gaps.begin(), gaps.end(),
      [](const std::pair<double, double> &a, const std::pair<double, double> &b) {
        return (a.second - a.first) < (b.second - b.first);
      });

    return (max_gap->first + max_gap->second) / 2.0;
  }
}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::GetSafeDirectionBTNode, "GetSafeDirectionBTNode");