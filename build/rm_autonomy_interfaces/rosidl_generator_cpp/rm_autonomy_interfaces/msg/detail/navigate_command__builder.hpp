// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/NavigateCommand.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/navigate_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavigateCommand_align_chassis_big_yaw
{
public:
  explicit Init_NavigateCommand_align_chassis_big_yaw(::rm_autonomy_interfaces::msg::NavigateCommand & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::NavigateCommand align_chassis_big_yaw(::rm_autonomy_interfaces::msg::NavigateCommand::_align_chassis_big_yaw_type arg)
  {
    msg_.align_chassis_big_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::NavigateCommand msg_;
};

class Init_NavigateCommand_scap_state
{
public:
  explicit Init_NavigateCommand_scap_state(::rm_autonomy_interfaces::msg::NavigateCommand & msg)
  : msg_(msg)
  {}
  Init_NavigateCommand_align_chassis_big_yaw scap_state(::rm_autonomy_interfaces::msg::NavigateCommand::_scap_state_type arg)
  {
    msg_.scap_state = std::move(arg);
    return Init_NavigateCommand_align_chassis_big_yaw(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::NavigateCommand msg_;
};

class Init_NavigateCommand_spin_speed
{
public:
  Init_NavigateCommand_spin_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCommand_scap_state spin_speed(::rm_autonomy_interfaces::msg::NavigateCommand::_spin_speed_type arg)
  {
    msg_.spin_speed = std::move(arg);
    return Init_NavigateCommand_scap_state(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::NavigateCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::NavigateCommand>()
{
  return rm_autonomy_interfaces::msg::builder::Init_NavigateCommand_spin_speed();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__BUILDER_HPP_
