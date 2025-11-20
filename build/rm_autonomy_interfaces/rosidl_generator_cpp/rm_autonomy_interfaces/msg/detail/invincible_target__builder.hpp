// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/invincible_target__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_InvincibleTarget_invincible_target
{
public:
  Init_InvincibleTarget_invincible_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_autonomy_interfaces::msg::InvincibleTarget invincible_target(::rm_autonomy_interfaces::msg::InvincibleTarget::_invincible_target_type arg)
  {
    msg_.invincible_target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::InvincibleTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::InvincibleTarget>()
{
  return rm_autonomy_interfaces::msg::builder::Init_InvincibleTarget_invincible_target();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__BUILDER_HPP_
