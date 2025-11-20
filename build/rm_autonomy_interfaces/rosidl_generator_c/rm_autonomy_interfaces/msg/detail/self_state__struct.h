// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SelfState in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__SelfState
{
  uint8_t robot_id;
  uint16_t current_hp;
  uint8_t patrol_rfid;
  uint8_t energy_rfid;
  uint8_t under_attack;
  uint16_t current_ammo;
  uint16_t energy_left;
  uint8_t decision_set;
} rm_autonomy_interfaces__msg__SelfState;

// Struct for a sequence of rm_autonomy_interfaces__msg__SelfState.
typedef struct rm_autonomy_interfaces__msg__SelfState__Sequence
{
  rm_autonomy_interfaces__msg__SelfState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__SelfState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__STRUCT_H_
