// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/ChaseControl.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/chase_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_ChaseControl_force_chase
{
public:
  explicit Init_ChaseControl_force_chase(::rm_autonomy_interfaces::msg::ChaseControl & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::ChaseControl force_chase(::rm_autonomy_interfaces::msg::ChaseControl::_force_chase_type arg)
  {
    msg_.force_chase = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ChaseControl msg_;
};

class Init_ChaseControl_into_chase
{
public:
  Init_ChaseControl_into_chase()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChaseControl_force_chase into_chase(::rm_autonomy_interfaces::msg::ChaseControl::_into_chase_type arg)
  {
    msg_.into_chase = std::move(arg);
    return Init_ChaseControl_force_chase(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::ChaseControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::ChaseControl>()
{
  return rm_autonomy_interfaces::msg::builder::Init_ChaseControl_into_chase();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__BUILDER_HPP_
