// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_autonomy_interfaces:msg/OmniSensing.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__TRAITS_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__TRAITS_HPP_

#include "rm_autonomy_interfaces/msg/detail/omni_sensing__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rm_autonomy_interfaces::msg::OmniSensing>()
{
  return "rm_autonomy_interfaces::msg::OmniSensing";
}

template<>
inline const char * name<rm_autonomy_interfaces::msg::OmniSensing>()
{
  return "rm_autonomy_interfaces/msg/OmniSensing";
}

template<>
struct has_fixed_size<rm_autonomy_interfaces::msg::OmniSensing>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_autonomy_interfaces::msg::OmniSensing>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_autonomy_interfaces::msg::OmniSensing>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__TRAITS_HPP_
