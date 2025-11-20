// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__rosidl_typesupport_introspection_c.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__functions.h"
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_autonomy_interfaces__msg__EnemyRobotMark__init(message_memory);
}

void EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_fini_function(void * message_memory)
{
  rm_autonomy_interfaces__msg__EnemyRobotMark__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_member_array[6] = {
  {
    "enemy_1_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__EnemyRobotMark, enemy_1_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enemy_2_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__EnemyRobotMark, enemy_2_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enemy_3_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__EnemyRobotMark, enemy_3_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enemy_4_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__EnemyRobotMark, enemy_4_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enemy_5_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__EnemyRobotMark, enemy_5_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enemy_7_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__EnemyRobotMark, enemy_7_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_members = {
  "rm_autonomy_interfaces__msg",  // message namespace
  "EnemyRobotMark",  // message name
  6,  // number of fields
  sizeof(rm_autonomy_interfaces__msg__EnemyRobotMark),
  EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_member_array,  // message members
  EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_init_function,  // function to initialize message memory (memory has to be allocated)
  EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_type_support_handle = {
  0,
  &EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_autonomy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_autonomy_interfaces, msg, EnemyRobotMark)() {
  if (!EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_type_support_handle.typesupport_identifier) {
    EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &EnemyRobotMark__rosidl_typesupport_introspection_c__EnemyRobotMark_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
