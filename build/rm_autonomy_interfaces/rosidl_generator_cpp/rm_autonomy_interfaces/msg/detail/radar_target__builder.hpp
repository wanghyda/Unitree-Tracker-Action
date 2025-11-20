// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/RadarTarget.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_TARGET__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_TARGET__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/radar_target__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_RadarTarget_target_map_y
{
public:
  explicit Init_RadarTarget_target_map_y(::rm_autonomy_interfaces::msg::RadarTarget & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::RadarTarget target_map_y(::rm_autonomy_interfaces::msg::RadarTarget::_target_map_y_type arg)
  {
    msg_.target_map_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarTarget msg_;
};

class Init_RadarTarget_target_map_x
{
public:
  explicit Init_RadarTarget_target_map_x(::rm_autonomy_interfaces::msg::RadarTarget & msg)
  : msg_(msg)
  {}
  Init_RadarTarget_target_map_y target_map_x(::rm_autonomy_interfaces::msg::RadarTarget::_target_map_x_type arg)
  {
    msg_.target_map_x = std::move(arg);
    return Init_RadarTarget_target_map_y(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarTarget msg_;
};

class Init_RadarTarget_target_id
{
public:
  Init_RadarTarget_target_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarTarget_target_map_x target_id(::rm_autonomy_interfaces::msg::RadarTarget::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_RadarTarget_target_map_x(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::RadarTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::RadarTarget>()
{
  return rm_autonomy_interfaces::msg::builder::Init_RadarTarget_target_id();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_TARGET__BUILDER_HPP_
