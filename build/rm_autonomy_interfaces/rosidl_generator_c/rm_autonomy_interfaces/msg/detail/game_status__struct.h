// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/GameStatus in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__GameStatus
{
  uint8_t stage_progress;
  uint16_t stage_remain_time;
} rm_autonomy_interfaces__msg__GameStatus;

// Struct for a sequence of rm_autonomy_interfaces__msg__GameStatus.
typedef struct rm_autonomy_interfaces__msg__GameStatus__Sequence
{
  rm_autonomy_interfaces__msg__GameStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__GameStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_H_
