// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/AutoaimCommunication.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/autoaim_communication__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_AutoaimCommunication_distance
{
public:
  explicit Init_AutoaimCommunication_distance(::rm_autonomy_interfaces::msg::AutoaimCommunication & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::AutoaimCommunication distance(::rm_autonomy_interfaces::msg::AutoaimCommunication::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AutoaimCommunication msg_;
};

class Init_AutoaimCommunication_target_id
{
public:
  explicit Init_AutoaimCommunication_target_id(::rm_autonomy_interfaces::msg::AutoaimCommunication & msg)
  : msg_(msg)
  {}
  Init_AutoaimCommunication_distance target_id(::rm_autonomy_interfaces::msg::AutoaimCommunication::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_AutoaimCommunication_distance(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AutoaimCommunication msg_;
};

class Init_AutoaimCommunication_has_target
{
public:
  Init_AutoaimCommunication_has_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AutoaimCommunication_target_id has_target(::rm_autonomy_interfaces::msg::AutoaimCommunication::_has_target_type arg)
  {
    msg_.has_target = std::move(arg);
    return Init_AutoaimCommunication_target_id(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AutoaimCommunication msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::AutoaimCommunication>()
{
  return rm_autonomy_interfaces::msg::builder::Init_AutoaimCommunication_has_target();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__BUILDER_HPP_
