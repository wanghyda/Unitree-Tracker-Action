// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_EnemyRobotMark_enemy_7_mark
{
public:
  explicit Init_EnemyRobotMark_enemy_7_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::EnemyRobotMark enemy_7_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark::_enemy_7_mark_type arg)
  {
    msg_.enemy_7_mark = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::EnemyRobotMark msg_;
};

class Init_EnemyRobotMark_enemy_5_mark
{
public:
  explicit Init_EnemyRobotMark_enemy_5_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark & msg)
  : msg_(msg)
  {}
  Init_EnemyRobotMark_enemy_7_mark enemy_5_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark::_enemy_5_mark_type arg)
  {
    msg_.enemy_5_mark = std::move(arg);
    return Init_EnemyRobotMark_enemy_7_mark(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::EnemyRobotMark msg_;
};

class Init_EnemyRobotMark_enemy_4_mark
{
public:
  explicit Init_EnemyRobotMark_enemy_4_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark & msg)
  : msg_(msg)
  {}
  Init_EnemyRobotMark_enemy_5_mark enemy_4_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark::_enemy_4_mark_type arg)
  {
    msg_.enemy_4_mark = std::move(arg);
    return Init_EnemyRobotMark_enemy_5_mark(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::EnemyRobotMark msg_;
};

class Init_EnemyRobotMark_enemy_3_mark
{
public:
  explicit Init_EnemyRobotMark_enemy_3_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark & msg)
  : msg_(msg)
  {}
  Init_EnemyRobotMark_enemy_4_mark enemy_3_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark::_enemy_3_mark_type arg)
  {
    msg_.enemy_3_mark = std::move(arg);
    return Init_EnemyRobotMark_enemy_4_mark(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::EnemyRobotMark msg_;
};

class Init_EnemyRobotMark_enemy_2_mark
{
public:
  explicit Init_EnemyRobotMark_enemy_2_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark & msg)
  : msg_(msg)
  {}
  Init_EnemyRobotMark_enemy_3_mark enemy_2_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark::_enemy_2_mark_type arg)
  {
    msg_.enemy_2_mark = std::move(arg);
    return Init_EnemyRobotMark_enemy_3_mark(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::EnemyRobotMark msg_;
};

class Init_EnemyRobotMark_enemy_1_mark
{
public:
  Init_EnemyRobotMark_enemy_1_mark()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EnemyRobotMark_enemy_2_mark enemy_1_mark(::rm_autonomy_interfaces::msg::EnemyRobotMark::_enemy_1_mark_type arg)
  {
    msg_.enemy_1_mark = std::move(arg);
    return Init_EnemyRobotMark_enemy_2_mark(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::EnemyRobotMark msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::EnemyRobotMark>()
{
  return rm_autonomy_interfaces::msg::builder::Init_EnemyRobotMark_enemy_1_mark();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__BUILDER_HPP_
