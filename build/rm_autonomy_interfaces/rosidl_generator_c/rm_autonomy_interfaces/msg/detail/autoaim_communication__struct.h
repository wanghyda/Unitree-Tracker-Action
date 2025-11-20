// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_autonomy_interfaces:msg/AutoaimCommunication.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__STRUCT_H_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/AutoaimCommunication in the package rm_autonomy_interfaces.
typedef struct rm_autonomy_interfaces__msg__AutoaimCommunication
{
  uint8_t has_target;
  uint8_t target_id;
  float distance;
} rm_autonomy_interfaces__msg__AutoaimCommunication;

// Struct for a sequence of rm_autonomy_interfaces__msg__AutoaimCommunication.
typedef struct rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence
{
  rm_autonomy_interfaces__msg__AutoaimCommunication * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_autonomy_interfaces__msg__AutoaimCommunication__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__STRUCT_H_
