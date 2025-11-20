// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_AllyRobotPosition_ally_7_position_y
{
public:
  explicit Init_AllyRobotPosition_ally_7_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::AllyRobotPosition ally_7_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_7_position_y_type arg)
  {
    msg_.ally_7_position_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_7_position_x
{
public:
  explicit Init_AllyRobotPosition_ally_7_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_7_position_y ally_7_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_7_position_x_type arg)
  {
    msg_.ally_7_position_x = std::move(arg);
    return Init_AllyRobotPosition_ally_7_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_5_position_y
{
public:
  explicit Init_AllyRobotPosition_ally_5_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_7_position_x ally_5_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_5_position_y_type arg)
  {
    msg_.ally_5_position_y = std::move(arg);
    return Init_AllyRobotPosition_ally_7_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_5_position_x
{
public:
  explicit Init_AllyRobotPosition_ally_5_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_5_position_y ally_5_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_5_position_x_type arg)
  {
    msg_.ally_5_position_x = std::move(arg);
    return Init_AllyRobotPosition_ally_5_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_4_position_y
{
public:
  explicit Init_AllyRobotPosition_ally_4_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_5_position_x ally_4_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_4_position_y_type arg)
  {
    msg_.ally_4_position_y = std::move(arg);
    return Init_AllyRobotPosition_ally_5_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_4_position_x
{
public:
  explicit Init_AllyRobotPosition_ally_4_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_4_position_y ally_4_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_4_position_x_type arg)
  {
    msg_.ally_4_position_x = std::move(arg);
    return Init_AllyRobotPosition_ally_4_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_3_position_y
{
public:
  explicit Init_AllyRobotPosition_ally_3_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_4_position_x ally_3_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_3_position_y_type arg)
  {
    msg_.ally_3_position_y = std::move(arg);
    return Init_AllyRobotPosition_ally_4_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_3_position_x
{
public:
  explicit Init_AllyRobotPosition_ally_3_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_3_position_y ally_3_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_3_position_x_type arg)
  {
    msg_.ally_3_position_x = std::move(arg);
    return Init_AllyRobotPosition_ally_3_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_2_position_y
{
public:
  explicit Init_AllyRobotPosition_ally_2_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_3_position_x ally_2_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_2_position_y_type arg)
  {
    msg_.ally_2_position_y = std::move(arg);
    return Init_AllyRobotPosition_ally_3_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_2_position_x
{
public:
  explicit Init_AllyRobotPosition_ally_2_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_2_position_y ally_2_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_2_position_x_type arg)
  {
    msg_.ally_2_position_x = std::move(arg);
    return Init_AllyRobotPosition_ally_2_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_1_position_y
{
public:
  explicit Init_AllyRobotPosition_ally_1_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition & msg)
  : msg_(msg)
  {}
  Init_AllyRobotPosition_ally_2_position_x ally_1_position_y(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_1_position_y_type arg)
  {
    msg_.ally_1_position_y = std::move(arg);
    return Init_AllyRobotPosition_ally_2_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

class Init_AllyRobotPosition_ally_1_position_x
{
public:
  Init_AllyRobotPosition_ally_1_position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AllyRobotPosition_ally_1_position_y ally_1_position_x(::rm_autonomy_interfaces::msg::AllyRobotPosition::_ally_1_position_x_type arg)
  {
    msg_.ally_1_position_x = std::move(arg);
    return Init_AllyRobotPosition_ally_1_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllyRobotPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::AllyRobotPosition>()
{
  return rm_autonomy_interfaces::msg::builder::Init_AllyRobotPosition_ally_1_position_x();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__BUILDER_HPP_
