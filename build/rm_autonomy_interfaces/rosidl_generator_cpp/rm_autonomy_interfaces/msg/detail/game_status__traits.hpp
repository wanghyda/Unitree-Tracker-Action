// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_autonomy_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_

#include "rm_autonomy_interfaces/msg/detail/game_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rm_autonomy_interfaces::msg::GameStatus>()
{
  return "rm_autonomy_interfaces::msg::GameStatus";
}

template<>
inline const char * name<rm_autonomy_interfaces::msg::GameStatus>()
{
  return "rm_autonomy_interfaces/msg/GameStatus";
}

template<>
struct has_fixed_size<rm_autonomy_interfaces::msg::GameStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_autonomy_interfaces::msg::GameStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_autonomy_interfaces::msg::GameStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_
