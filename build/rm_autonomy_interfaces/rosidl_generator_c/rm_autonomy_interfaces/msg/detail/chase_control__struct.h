// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/ChaseControl.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ChaseControl in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__ChaseControl
{
  uint8_t into_chase;
  uint8_t force_chase;
} rm_autonomy_interfaces__msg__ChaseControl;

// Struct for a sequence of rm_autonomy_interfaces__msg__ChaseControl.
typedef struct rm_autonomy_interfaces__msg__ChaseControl__Sequence
{
  rm_autonomy_interfaces__msg__ChaseControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__ChaseControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__CHASE_CONTROL__STRUCT_H_
