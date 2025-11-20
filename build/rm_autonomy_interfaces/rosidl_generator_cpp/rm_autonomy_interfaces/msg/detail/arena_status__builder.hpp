// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/arena_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArenaStatus_rump_central_buff_status
{
public:
  explicit Init_ArenaStatus_rump_central_buff_status(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::ArenaStatus rump_central_buff_status(::rm_autonomy_interfaces::msg::ArenaStatus::_rump_central_buff_status_type arg)
  {
    msg_.rump_central_buff_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_base_shield_percentage
{
public:
  explicit Init_ArenaStatus_base_shield_percentage(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_rump_central_buff_status base_shield_percentage(::rm_autonomy_interfaces::msg::ArenaStatus::_base_shield_percentage_type arg)
  {
    msg_.base_shield_percentage = std::move(arg);
    return Init_ArenaStatus_rump_central_buff_status(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_trapezoid_highground_status
{
public:
  explicit Init_ArenaStatus_trapezoid_highground_status(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_base_shield_percentage trapezoid_highground_status(::rm_autonomy_interfaces::msg::ArenaStatus::_trapezoid_highground_status_type arg)
  {
    msg_.trapezoid_highground_status = std::move(arg);
    return Init_ArenaStatus_base_shield_percentage(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_ring_highground_status
{
public:
  explicit Init_ArenaStatus_ring_highground_status(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_trapezoid_highground_status ring_highground_status(::rm_autonomy_interfaces::msg::ArenaStatus::_ring_highground_status_type arg)
  {
    msg_.ring_highground_status = std::move(arg);
    return Init_ArenaStatus_trapezoid_highground_status(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_energy_big_status
{
public:
  explicit Init_ArenaStatus_energy_big_status(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_ring_highground_status energy_big_status(::rm_autonomy_interfaces::msg::ArenaStatus::_energy_big_status_type arg)
  {
    msg_.energy_big_status = std::move(arg);
    return Init_ArenaStatus_ring_highground_status(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_energy_small_status
{
public:
  explicit Init_ArenaStatus_energy_small_status(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_energy_big_status energy_small_status(::rm_autonomy_interfaces::msg::ArenaStatus::_energy_small_status_type arg)
  {
    msg_.energy_small_status = std::move(arg);
    return Init_ArenaStatus_energy_big_status(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_energy_occupy_status
{
public:
  explicit Init_ArenaStatus_energy_occupy_status(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_energy_small_status energy_occupy_status(::rm_autonomy_interfaces::msg::ArenaStatus::_energy_occupy_status_type arg)
  {
    msg_.energy_occupy_status = std::move(arg);
    return Init_ArenaStatus_energy_small_status(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_rmul_healing
{
public:
  explicit Init_ArenaStatus_rmul_healing(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_energy_occupy_status rmul_healing(::rm_autonomy_interfaces::msg::ArenaStatus::_rmul_healing_type arg)
  {
    msg_.rmul_healing = std::move(arg);
    return Init_ArenaStatus_energy_occupy_status(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_healing_inner
{
public:
  explicit Init_ArenaStatus_healing_inner(::rm_autonomy_interfaces::msg::ArenaStatus & msg)
  : msg_(msg)
  {}
  Init_ArenaStatus_rmul_healing healing_inner(::rm_autonomy_interfaces::msg::ArenaStatus::_healing_inner_type arg)
  {
    msg_.healing_inner = std::move(arg);
    return Init_ArenaStatus_rmul_healing(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

class Init_ArenaStatus_healing_front
{
public:
  Init_ArenaStatus_healing_front()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArenaStatus_healing_inner healing_front(::rm_autonomy_interfaces::msg::ArenaStatus::_healing_front_type arg)
  {
    msg_.healing_front = std::move(arg);
    return Init_ArenaStatus_healing_inner(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ArenaStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::ArenaStatus>()
{
  return rm_autonomy_interfaces::msg::builder::Init_ArenaStatus_healing_front();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__BUILDER_HPP_
