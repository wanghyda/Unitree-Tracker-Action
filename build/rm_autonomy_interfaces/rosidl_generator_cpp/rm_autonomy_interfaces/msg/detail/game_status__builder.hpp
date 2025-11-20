// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/game_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_GameStatus_stage_remain_time
{
public:
  explicit Init_GameStatus_stage_remain_time(::rm_autonomy_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::GameStatus stage_remain_time(::rm_autonomy_interfaces::msg::GameStatus::_stage_remain_time_type arg)
  {
    msg_.stage_remain_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_stage_progress
{
public:
  Init_GameStatus_stage_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameStatus_stage_remain_time stage_progress(::rm_autonomy_interfaces::msg::GameStatus::_stage_progress_type arg)
  {
    msg_.stage_progress = std::move(arg);
    return Init_GameStatus_stage_remain_time(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::GameStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::GameStatus>()
{
  return rm_autonomy_interfaces::msg::builder::Init_GameStatus_stage_progress();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
