// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/OmniSensing.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/OmniSensing in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__OmniSensing
{
  float target_yaw;
  float target_pitch;
} rm_autonomy_interfaces__msg__OmniSensing;

// Struct for a sequence of rm_autonomy_interfaces__msg__OmniSensing.
typedef struct rm_autonomy_interfaces__msg__OmniSensing__Sequence
{
  rm_autonomy_interfaces__msg__OmniSensing * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__OmniSensing__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__STRUCT_H_
