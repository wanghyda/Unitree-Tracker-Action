// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/HumanIntervention.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/human_intervention__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_HumanIntervention_goal_pose_y
{
public:
  explicit Init_HumanIntervention_goal_pose_y(::rm_autonomy_interfaces::msg::HumanIntervention & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::HumanIntervention goal_pose_y(::rm_autonomy_interfaces::msg::HumanIntervention::_goal_pose_y_type arg)
  {
    msg_.goal_pose_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::HumanIntervention msg_;
};

class Init_HumanIntervention_goal_pose_x
{
public:
  explicit Init_HumanIntervention_goal_pose_x(::rm_autonomy_interfaces::msg::HumanIntervention & msg)
  : msg_(msg)
  {}
  Init_HumanIntervention_goal_pose_y goal_pose_x(::rm_autonomy_interfaces::msg::HumanIntervention::_goal_pose_x_type arg)
  {
    msg_.goal_pose_x = std::move(arg);
    return Init_HumanIntervention_goal_pose_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::HumanIntervention msg_;
};

class Init_HumanIntervention_command_header
{
public:
  Init_HumanIntervention_command_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HumanIntervention_goal_pose_x command_header(::rm_autonomy_interfaces::msg::HumanIntervention::_command_header_type arg)
  {
    msg_.command_header = std::move(arg);
    return Init_HumanIntervention_goal_pose_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::HumanIntervention msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::HumanIntervention>()
{
  return rm_autonomy_interfaces::msg::builder::Init_HumanIntervention_command_header();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__BUILDER_HPP_
