// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_autonomy_interfaces/msg/detail/self_state__rosidl_typesupport_introspection_c.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_autonomy_interfaces/msg/detail/self_state__functions.h"
#include "rm_autonomy_interfaces/msg/detail/self_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SelfState__rosidl_typesupport_introspection_c__SelfState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_autonomy_interfaces__msg__SelfState__init(message_memory);
}

void SelfState__rosidl_typesupport_introspection_c__SelfState_fini_function(void * message_memory)
{
  rm_autonomy_interfaces__msg__SelfState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SelfState__rosidl_typesupport_introspection_c__SelfState_message_member_array[8] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_hp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, current_hp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "patrol_rfid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, patrol_rfid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "energy_rfid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, energy_rfid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "under_attack",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, under_attack),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_ammo",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, current_ammo),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "energy_left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, energy_left),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "decision_set",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__SelfState, decision_set),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SelfState__rosidl_typesupport_introspection_c__SelfState_message_members = {
  "rm_autonomy_interfaces__msg",  // message namespace
  "SelfState",  // message name
  8,  // number of fields
  sizeof(rm_autonomy_interfaces__msg__SelfState),
  SelfState__rosidl_typesupport_introspection_c__SelfState_message_member_array,  // message members
  SelfState__rosidl_typesupport_introspection_c__SelfState_init_function,  // function to initialize message memory (memory has to be allocated)
  SelfState__rosidl_typesupport_introspection_c__SelfState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SelfState__rosidl_typesupport_introspection_c__SelfState_message_type_support_handle = {
  0,
  &SelfState__rosidl_typesupport_introspection_c__SelfState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_autonomy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_autonomy_interfaces, msg, SelfState)() {
  if (!SelfState__rosidl_typesupport_introspection_c__SelfState_message_type_support_handle.typesupport_identifier) {
    SelfState__rosidl_typesupport_introspection_c__SelfState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SelfState__rosidl_typesupport_introspection_c__SelfState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
