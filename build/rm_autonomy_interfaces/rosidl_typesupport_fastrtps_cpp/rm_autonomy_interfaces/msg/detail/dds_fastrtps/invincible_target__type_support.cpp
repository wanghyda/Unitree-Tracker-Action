// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/invincible_target__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_autonomy_interfaces/msg/detail/invincible_target__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rm_autonomy_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
cdr_serialize(
  const rm_autonomy_interfaces::msg::InvincibleTarget & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: invincible_target
  {
    cdr << ros_message.invincible_target;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_autonomy_interfaces::msg::InvincibleTarget & ros_message)
{
  // Member: invincible_target
  {
    cdr >> ros_message.invincible_target;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
get_serialized_size(
  const rm_autonomy_interfaces::msg::InvincibleTarget & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: invincible_target
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.invincible_target[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
max_serialized_size_InvincibleTarget(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: invincible_target
  {
    size_t array_size = 6;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _InvincibleTarget__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::InvincibleTarget *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _InvincibleTarget__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_autonomy_interfaces::msg::InvincibleTarget *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _InvincibleTarget__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::InvincibleTarget *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _InvincibleTarget__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_InvincibleTarget(full_bounded, 0);
}

static message_type_support_callbacks_t _InvincibleTarget__callbacks = {
  "rm_autonomy_interfaces::msg",
  "InvincibleTarget",
  _InvincibleTarget__cdr_serialize,
  _InvincibleTarget__cdr_deserialize,
  _InvincibleTarget__get_serialized_size,
  _InvincibleTarget__max_serialized_size
};

static rosidl_message_type_support_t _InvincibleTarget__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_InvincibleTarget__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rm_autonomy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rm_autonomy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rm_autonomy_interfaces::msg::InvincibleTarget>()
{
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_InvincibleTarget__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_autonomy_interfaces, msg, InvincibleTarget)() {
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_InvincibleTarget__handle;
}

#ifdef __cplusplus
}
#endif
