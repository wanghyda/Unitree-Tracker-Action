// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/EnemyRobotMark in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__EnemyRobotMark
{
  uint8_t enemy_1_mark;
  uint8_t enemy_2_mark;
  uint8_t enemy_3_mark;
  uint8_t enemy_4_mark;
  uint8_t enemy_5_mark;
  uint8_t enemy_7_mark;
} rm_autonomy_interfaces__msg__EnemyRobotMark;

// Struct for a sequence of rm_autonomy_interfaces__msg__EnemyRobotMark.
typedef struct rm_autonomy_interfaces__msg__EnemyRobotMark__Sequence
{
  rm_autonomy_interfaces__msg__EnemyRobotMark * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__EnemyRobotMark__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__STRUCT_H_
