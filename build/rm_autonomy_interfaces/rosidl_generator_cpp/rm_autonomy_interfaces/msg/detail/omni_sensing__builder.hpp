// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/OmniSensing.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/omni_sensing__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_OmniSensing_target_pitch
{
public:
  explicit Init_OmniSensing_target_pitch(::rm_autonomy_interfaces::msg::OmniSensing & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::OmniSensing target_pitch(::rm_autonomy_interfaces::msg::OmniSensing::_target_pitch_type arg)
  {
    msg_.target_pitch = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::OmniSensing msg_;
};

class Init_OmniSensing_target_yaw
{
public:
  Init_OmniSensing_target_yaw()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OmniSensing_target_pitch target_yaw(::rm_autonomy_interfaces::msg::OmniSensing::_target_yaw_type arg)
  {
    msg_.target_yaw = std::move(arg);
    return Init_OmniSensing_target_pitch(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::OmniSensing msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::OmniSensing>()
{
  return rm_autonomy_interfaces::msg::builder::Init_OmniSensing_target_yaw();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__BUILDER_HPP_
