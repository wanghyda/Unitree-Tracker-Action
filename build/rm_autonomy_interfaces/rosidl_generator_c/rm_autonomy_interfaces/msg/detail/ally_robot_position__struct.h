// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/AllyRobotPosition in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__AllyRobotPosition
{
  float ally_1_position_x;
  float ally_1_position_y;
  float ally_2_position_x;
  float ally_2_position_y;
  float ally_3_position_x;
  float ally_3_position_y;
  float ally_4_position_x;
  float ally_4_position_y;
  float ally_5_position_x;
  float ally_5_position_y;
  float ally_7_position_x;
  float ally_7_position_y;
} rm_autonomy_interfaces__msg__AllyRobotPosition;

// Struct for a sequence of rm_autonomy_interfaces__msg__AllyRobotPosition.
typedef struct rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence
{
  rm_autonomy_interfaces__msg__AllyRobotPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__AllyRobotPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__STRUCT_H_
