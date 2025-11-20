// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RadarEnemyPosition in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__RadarEnemyPosition
{
  float enemy_1_position_x;
  float enemy_1_position_y;
  float enemy_2_position_x;
  float enemy_2_position_y;
  float enemy_3_position_x;
  float enemy_3_position_y;
  float enemy_4_position_x;
  float enemy_4_position_y;
  float enemy_5_position_x;
  float enemy_5_position_y;
  float enemy_7_position_x;
  float enemy_7_position_y;
} rm_autonomy_interfaces__msg__RadarEnemyPosition;

// Struct for a sequence of rm_autonomy_interfaces__msg__RadarEnemyPosition.
typedef struct rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence
{
  rm_autonomy_interfaces__msg__RadarEnemyPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__RadarEnemyPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__STRUCT_H_
