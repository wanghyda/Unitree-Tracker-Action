// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_autonomy_interfaces:msg/ChaseControl.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__TRAITS_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__TRAITS_HPP_

#include "rm_autonomy_interfaces/msg/detail/chase_control__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rm_autonomy_interfaces::msg::ChaseControl>()
{
  return "rm_autonomy_interfaces::msg::ChaseControl";
}

template<>
inline const char * name<rm_autonomy_interfaces::msg::ChaseControl>()
{
  return "rm_autonomy_interfaces/msg/ChaseControl";
}

template<>
struct has_fixed_size<rm_autonomy_interfaces::msg::ChaseControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_autonomy_interfaces::msg::ChaseControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_autonomy_interfaces::msg::ChaseControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__TRAITS_HPP_
