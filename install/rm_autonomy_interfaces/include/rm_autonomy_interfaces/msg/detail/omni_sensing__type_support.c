// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_autonomy_interfaces:msg/OmniSensing.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_autonomy_interfaces/msg/detail/omni_sensing__rosidl_typesupport_introspection_c.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_autonomy_interfaces/msg/detail/omni_sensing__functions.h"
#include "rm_autonomy_interfaces/msg/detail/omni_sensing__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_autonomy_interfaces__msg__OmniSensing__init(message_memory);
}

void OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_fini_function(void * message_memory)
{
  rm_autonomy_interfaces__msg__OmniSensing__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_member_array[2] = {
  {
    "target_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__OmniSensing, target_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces__msg__OmniSensing, target_pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_members = {
  "rm_autonomy_interfaces__msg",  // message namespace
  "OmniSensing",  // message name
  2,  // number of fields
  sizeof(rm_autonomy_interfaces__msg__OmniSensing),
  OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_member_array,  // message members
  OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_init_function,  // function to initialize message memory (memory has to be allocated)
  OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_type_support_handle = {
  0,
  &OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_autonomy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_autonomy_interfaces, msg, OmniSensing)() {
  if (!OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_type_support_handle.typesupport_identifier) {
    OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &OmniSensing__rosidl_typesupport_introspection_c__OmniSensing_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
