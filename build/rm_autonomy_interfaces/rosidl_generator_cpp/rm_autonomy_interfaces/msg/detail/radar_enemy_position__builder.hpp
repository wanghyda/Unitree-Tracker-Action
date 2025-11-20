// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_RadarEnemyPosition_enemy_7_position_y
{
public:
  explicit Init_RadarEnemyPosition_enemy_7_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition enemy_7_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_7_position_y_type arg)
  {
    msg_.enemy_7_position_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_7_position_x
{
public:
  explicit Init_RadarEnemyPosition_enemy_7_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_7_position_y enemy_7_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_7_position_x_type arg)
  {
    msg_.enemy_7_position_x = std::move(arg);
    return Init_RadarEnemyPosition_enemy_7_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_5_position_y
{
public:
  explicit Init_RadarEnemyPosition_enemy_5_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_7_position_x enemy_5_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_5_position_y_type arg)
  {
    msg_.enemy_5_position_y = std::move(arg);
    return Init_RadarEnemyPosition_enemy_7_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_5_position_x
{
public:
  explicit Init_RadarEnemyPosition_enemy_5_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_5_position_y enemy_5_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_5_position_x_type arg)
  {
    msg_.enemy_5_position_x = std::move(arg);
    return Init_RadarEnemyPosition_enemy_5_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_4_position_y
{
public:
  explicit Init_RadarEnemyPosition_enemy_4_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_5_position_x enemy_4_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_4_position_y_type arg)
  {
    msg_.enemy_4_position_y = std::move(arg);
    return Init_RadarEnemyPosition_enemy_5_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_4_position_x
{
public:
  explicit Init_RadarEnemyPosition_enemy_4_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_4_position_y enemy_4_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_4_position_x_type arg)
  {
    msg_.enemy_4_position_x = std::move(arg);
    return Init_RadarEnemyPosition_enemy_4_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_3_position_y
{
public:
  explicit Init_RadarEnemyPosition_enemy_3_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_4_position_x enemy_3_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_3_position_y_type arg)
  {
    msg_.enemy_3_position_y = std::move(arg);
    return Init_RadarEnemyPosition_enemy_4_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_3_position_x
{
public:
  explicit Init_RadarEnemyPosition_enemy_3_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_3_position_y enemy_3_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_3_position_x_type arg)
  {
    msg_.enemy_3_position_x = std::move(arg);
    return Init_RadarEnemyPosition_enemy_3_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_2_position_y
{
public:
  explicit Init_RadarEnemyPosition_enemy_2_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_3_position_x enemy_2_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_2_position_y_type arg)
  {
    msg_.enemy_2_position_y = std::move(arg);
    return Init_RadarEnemyPosition_enemy_3_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_2_position_x
{
public:
  explicit Init_RadarEnemyPosition_enemy_2_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_2_position_y enemy_2_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_2_position_x_type arg)
  {
    msg_.enemy_2_position_x = std::move(arg);
    return Init_RadarEnemyPosition_enemy_2_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_1_position_y
{
public:
  explicit Init_RadarEnemyPosition_enemy_1_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition & msg)
  : msg_(msg)
  {}
  Init_RadarEnemyPosition_enemy_2_position_x enemy_1_position_y(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_1_position_y_type arg)
  {
    msg_.enemy_1_position_y = std::move(arg);
    return Init_RadarEnemyPosition_enemy_2_position_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

class Init_RadarEnemyPosition_enemy_1_position_x
{
public:
  Init_RadarEnemyPosition_enemy_1_position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarEnemyPosition_enemy_1_position_y enemy_1_position_x(::rm_autonomy_interfaces::msg::RadarEnemyPosition::_enemy_1_position_x_type arg)
  {
    msg_.enemy_1_position_x = std::move(arg);
    return Init_RadarEnemyPosition_enemy_1_position_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarEnemyPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::RadarEnemyPosition>()
{
  return rm_autonomy_interfaces::msg::builder::Init_RadarEnemyPosition_enemy_1_position_x();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__BUILDER_HPP_
