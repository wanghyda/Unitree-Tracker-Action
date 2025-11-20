// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/FireTrigger.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/fire_trigger__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_FireTrigger_fire_trigger
{
public:
  Init_FireTrigger_fire_trigger()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_autonomy_interfaces::msg::FireTrigger fire_trigger(::rm_autonomy_interfaces::msg::FireTrigger::_fire_trigger_type arg)
  {
    msg_.fire_trigger = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::FireTrigger msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::FireTrigger>()
{
  return rm_autonomy_interfaces::msg::builder::Init_FireTrigger_fire_trigger();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__BUILDER_HPP_
