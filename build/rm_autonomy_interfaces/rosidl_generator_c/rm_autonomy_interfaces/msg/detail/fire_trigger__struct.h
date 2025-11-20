// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/FireTrigger.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/FireTrigger in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__FireTrigger
{
  uint8_t fire_trigger;
} rm_autonomy_interfaces__msg__FireTrigger;

// Struct for a sequence of rm_autonomy_interfaces__msg__FireTrigger.
typedef struct rm_autonomy_interfaces__msg__FireTrigger__Sequence
{
  rm_autonomy_interfaces__msg__FireTrigger * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__FireTrigger__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__STRUCT_H_
