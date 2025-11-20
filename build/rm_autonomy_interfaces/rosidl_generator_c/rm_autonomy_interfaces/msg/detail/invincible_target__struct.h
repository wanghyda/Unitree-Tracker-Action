// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/InvincibleTarget in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__InvincibleTarget
{
  uint8_t invincible_target[6];
} rm_autonomy_interfaces__msg__InvincibleTarget;

// Struct for a sequence of rm_autonomy_interfaces__msg__InvincibleTarget.
typedef struct rm_autonomy_interfaces__msg__InvincibleTarget__Sequence
{
  rm_autonomy_interfaces__msg__InvincibleTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__InvincibleTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__STRUCT_H_
