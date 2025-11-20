// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__TRAITS_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__TRAITS_HPP_

#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rm_autonomy_interfaces::msg::RadarEnemyPosition>()
{
  return "rm_autonomy_interfaces::msg::RadarEnemyPosition";
}

template<>
inline const char * name<rm_autonomy_interfaces::msg::RadarEnemyPosition>()
{
  return "rm_autonomy_interfaces/msg/RadarEnemyPosition";
}

template<>
struct has_fixed_size<rm_autonomy_interfaces::msg::RadarEnemyPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_autonomy_interfaces::msg::RadarEnemyPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_autonomy_interfaces::msg::RadarEnemyPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__TRAITS_HPP_
