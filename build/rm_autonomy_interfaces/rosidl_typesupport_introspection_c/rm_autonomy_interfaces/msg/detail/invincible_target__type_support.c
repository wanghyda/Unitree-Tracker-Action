// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_autonomy_interfaces/msg/detail/invincible_target__rosidl_typesupport_introspection_c.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_autonomy_interfaces/msg/detail/invincible_target__functions.h"
#include "rm_autonomy_interfaces/msg/detail/invincible_target__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_autonomy_interfaces__msg__InvincibleTarget__init(message_memory);
}

void InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_fini_function(void * message_memory)
{
  rm_autonomy_interfaces__msg__InvincibleTarget__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_member_array[1] = {
  {
    "invincible_target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__InvincibleTarget, invincible_target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_members = {
  "rm_autonomy_interfaces__msg",  // message namespace
  "InvincibleTarget",  // message name
  1,  // number of fields
  sizeof(rm_autonomy_interfaces__msg__InvincibleTarget),
  InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_member_array,  // message members
  InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_init_function,  // function to initialize message memory (memory has to be allocated)
  InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_type_support_handle = {
  0,
  &InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_autonomy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_autonomy_interfaces, msg, InvincibleTarget)() {
  if (!InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_type_support_handle.typesupport_identifier) {
    InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &InvincibleTarget__rosidl_typesupport_introspection_c__InvincibleTarget_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
