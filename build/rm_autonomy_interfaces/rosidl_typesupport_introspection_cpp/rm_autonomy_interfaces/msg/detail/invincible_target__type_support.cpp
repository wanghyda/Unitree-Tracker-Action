// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_autonomy_interfaces/msg/detail/invincible_target__struct.hpp"
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

void InvincibleTarget_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_autonomy_interfaces::msg::InvincibleTarget(_init);
}

void InvincibleTarget_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_autonomy_interfaces::msg::InvincibleTarget *>(message_memory);
  typed_message->~InvincibleTarget();
}

size_t size_function__InvincibleTarget__invincible_target(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__InvincibleTarget__invincible_target(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__InvincibleTarget__invincible_target(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 6> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember InvincibleTarget_message_member_array[1] = {
  {
    "invincible_target",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_autonomy_interfaces::msg::InvincibleTarget, invincible_target),  // bytes offset in struct
    nullptr,  // default value
    size_function__InvincibleTarget__invincible_target,  // size() function pointer
    get_const_function__InvincibleTarget__invincible_target,  // get_const(index) function pointer
    get_function__InvincibleTarget__invincible_target,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers InvincibleTarget_message_members = {
  "rm_autonomy_interfaces::msg",  // message namespace
  "InvincibleTarget",  // message name
  1,  // number of fields
  sizeof(rm_autonomy_interfaces::msg::InvincibleTarget),
  InvincibleTarget_message_member_array,  // message members
  InvincibleTarget_init_function,  // function to initialize message memory (memory has to be allocated)
  InvincibleTarget_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t InvincibleTarget_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &InvincibleTarget_message_members,
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
get_message_type_support_handle<rm_autonomy_interfaces::msg::InvincibleTarget>()
{
  return &::rm_autonomy_interfaces::msg::rosidl_typesupport_introspection_cpp::InvincibleTarget_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_autonomy_interfaces, msg, InvincibleTarget)() {
  return &::rm_autonomy_interfaces::msg::rosidl_typesupport_introspection_cpp::InvincibleTarget_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
