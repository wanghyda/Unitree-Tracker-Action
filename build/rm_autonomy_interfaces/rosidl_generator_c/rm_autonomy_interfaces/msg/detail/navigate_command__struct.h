// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/NavigateCommand.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/NavigateCommand in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__NavigateCommand
{
  float spin_speed;
  bool scap_state;
  bool align_chassis_big_yaw;
} rm_autonomy_interfaces__msg__NavigateCommand;

// Struct for a sequence of rm_autonomy_interfaces__msg__NavigateCommand.
typedef struct rm_autonomy_interfaces__msg__NavigateCommand__Sequence
{
  rm_autonomy_interfaces__msg__NavigateCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__NavigateCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__STRUCT_H_
