// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ArenaStatus in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__ArenaStatus
{
  uint8_t healing_front;
  uint8_t healing_inner;
  uint8_t rmul_healing;
  uint8_t energy_occupy_status;
  uint8_t energy_small_status;
  uint8_t energy_big_status;
  uint8_t ring_highground_status;
  uint8_t trapezoid_highground_status;
  uint8_t base_shield_percentage;
  uint8_t rump_central_buff_status;
} rm_autonomy_interfaces__msg__ArenaStatus;

// Struct for a sequence of rm_autonomy_interfaces__msg__ArenaStatus.
typedef struct rm_autonomy_interfaces__msg__ArenaStatus__Sequence
{
  rm_autonomy_interfaces__msg__ArenaStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__ArenaStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__STRUCT_H_
