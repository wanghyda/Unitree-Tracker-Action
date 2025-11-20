// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__TRAITS_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__TRAITS_HPP_

#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rm_autonomy_interfaces::msg::AllyRobotPosition>()
{
  return "rm_autonomy_interfaces::msg::AllyRobotPosition";
}

template<>
inline const char * name<rm_autonomy_interfaces::msg::AllyRobotPosition>()
{
  return "rm_autonomy_interfaces/msg/AllyRobotPosition";
}

template<>
struct has_fixed_size<rm_autonomy_interfaces::msg::AllyRobotPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_autonomy_interfaces::msg::AllyRobotPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_autonomy_interfaces::msg::AllyRobotPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__TRAITS_HPP_
