#ifndef RM_BEHAVIOR_TREE__BT_CONVERSIONS_HPP_
#define RM_BEHAVIOR_TREE__BT_CONVERSIONS_HPP_

#include "behaviortree_cpp/behavior_tree.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rm_autonomy_interfaces/msg/navigate_command.hpp"

namespace BT
{

template <>
inline geometry_msgs::msg::PoseStamped convertFromString(const StringView key)
{
  // three real numbers separated by semicolons
  auto parts = splitString(key, ';');
  if (parts.size() != 7) {
    throw RuntimeError("invalid input)");
  } else {
    geometry_msgs::msg::PoseStamped msg;
    msg.pose.position.x = convertFromString<double>(parts[0]);
    msg.pose.position.y = convertFromString<double>(parts[1]);
    msg.pose.position.z = convertFromString<double>(parts[2]);
    msg.pose.orientation.x = convertFromString<double>(parts[3]);
    msg.pose.orientation.y = convertFromString<double>(parts[4]);
    msg.pose.orientation.z = convertFromString<double>(parts[5]);
    msg.pose.orientation.w = convertFromString<double>(parts[6]);
    return msg;
  }
}

template <>
inline rm_autonomy_interfaces::msg::NavigateCommand convertFromString(const StringView key)
{
  // three real numbers separated by semicolons
  auto parts = splitString(key, ';');
  if (parts.size() != 2) {
    throw RuntimeError("invalid input)");
  } else {
    rm_autonomy_interfaces::msg::NavigateCommand msg;
    msg.spin_speed = convertFromString<int>(parts[0]);
    msg.scap_state = convertFromString<int>(parts[1]);
    return msg;
  }
}

}  // namespace BT

#endif  // RM_BEHAVIOR_TREE__BT_CONVERSIONS_HPP_
