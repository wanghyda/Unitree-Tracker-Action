// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/AutoaimCommunication.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_autonomy_interfaces/msg/detail/autoaim_communication__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rm_autonomy_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void AutoaimCommunication_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_autonomy_interfaces::msg::AutoaimCommunication(_init);
}

void AutoaimCommunication_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_autonomy_interfaces::msg::AutoaimCommunication *>(message_memory);
  typed_message->~AutoaimCommunication();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AutoaimCommunication_message_member_array[3] = {
  {
    "has_target",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces::msg::AutoaimCommunication, has_target),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces::msg::AutoaimCommunication, target_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces::msg::AutoaimCommunication, distance),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AutoaimCommunication_message_members = {
  "rm_autonomy_interfaces::msg",  // message namespace
  "AutoaimCommunication",  // message name
  3,  // number of fields
  sizeof(rm_autonomy_interfaces::msg::AutoaimCommunication),
  AutoaimCommunication_message_member_array,  // message members
  AutoaimCommunication_init_function,  // function to initialize message memory (memory has to be allocated)
  AutoaimCommunication_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AutoaimCommunication_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AutoaimCommunication_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rm_autonomy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rm_autonomy_interfaces::msg::AutoaimCommunication>()
{
  return &::rm_autonomy_interfaces::msg::rosidl_typesupport_introspection_cpp::AutoaimCommunication_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_autonomy_interfaces, msg, AutoaimCommunication)() {
  return &::rm_autonomy_interfaces::msg::rosidl_typesupport_introspection_cpp::AutoaimCommunication_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
