// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/FireTrigger.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_autonomy_interfaces/msg/detail/fire_trigger__struct.hpp"
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

void FireTrigger_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_autonomy_interfaces::msg::FireTrigger(_init);
}

void FireTrigger_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_autonomy_interfaces::msg::FireTrigger *>(message_memory);
  typed_message->~FireTrigger();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FireTrigger_message_member_array[1] = {
  {
    "fire_trigger",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces::msg::FireTrigger, fire_trigger),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FireTrigger_message_members = {
  "rm_autonomy_interfaces::msg",  // message namespace
  "FireTrigger",  // message name
  1,  // number of fields
  sizeof(rm_autonomy_interfaces::msg::FireTrigger),
  FireTrigger_message_member_array,  // message members
  FireTrigger_init_function,  // function to initialize message memory (memory has to be allocated)
  FireTrigger_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FireTrigger_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FireTrigger_message_members,
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
get_message_type_support_handle<rm_autonomy_interfaces::msg::FireTrigger>()
{
  return &::rm_autonomy_interfaces::msg::rosidl_typesupport_introspection_cpp::FireTrigger_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_autonomy_interfaces, msg, FireTrigger)() {
  return &::rm_autonomy_interfaces::msg::rosidl_typesupport_introspection_cpp::FireTrigger_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
