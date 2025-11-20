// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/invincible_target__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/invincible_target__struct.h"
#include "rm_autonomy_interfaces/msg/detail/invincible_target__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _InvincibleTarget__ros_msg_type = rm_autonomy_interfaces__msg__InvincibleTarget;

static bool _InvincibleTarget__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _InvincibleTarget__ros_msg_type * ros_message = static_cast<const _InvincibleTarget__ros_msg_type *>(untyped_ros_message);
  // Field name: invincible_target
  {
    size_t size = 6;
    auto array_ptr = ros_message->invincible_target;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _InvincibleTarget__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _InvincibleTarget__ros_msg_type * ros_message = static_cast<_InvincibleTarget__ros_msg_type *>(untyped_ros_message);
  // Field name: invincible_target
  {
    size_t size = 6;
    auto array_ptr = ros_message->invincible_target;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__InvincibleTarget(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InvincibleTarget__ros_msg_type * ros_message = static_cast<const _InvincibleTarget__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name invincible_target
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->invincible_target;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _InvincibleTarget__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__InvincibleTarget(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__InvincibleTarget(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: invincible_target
  {
    size_t array_size = 6;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _InvincibleTarget__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__InvincibleTarget(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_InvincibleTarget = {
  "rm_autonomy_interfaces::msg",
  "InvincibleTarget",
  _InvincibleTarget__cdr_serialize,
  _InvincibleTarget__cdr_deserialize,
  _InvincibleTarget__get_serialized_size,
  _InvincibleTarget__max_serialized_size
};

static rosidl_message_type_support_t _InvincibleTarget__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_InvincibleTarget,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, InvincibleTarget)() {
  return &_InvincibleTarget__type_support;
}

#if defined(__cplusplus)
}
#endif
