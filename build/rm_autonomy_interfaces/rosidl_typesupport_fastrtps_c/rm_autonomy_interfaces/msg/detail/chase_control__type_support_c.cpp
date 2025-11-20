// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/ChaseControl.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/chase_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/chase_control__struct.h"
#include "rm_autonomy_interfaces/msg/detail/chase_control__functions.h"
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


using _ChaseControl__ros_msg_type = rm_autonomy_interfaces__msg__ChaseControl;

static bool _ChaseControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ChaseControl__ros_msg_type * ros_message = static_cast<const _ChaseControl__ros_msg_type *>(untyped_ros_message);
  // Field name: into_chase
  {
    cdr << ros_message->into_chase;
  }

  // Field name: force_chase
  {
    cdr << ros_message->force_chase;
  }

  return true;
}

static bool _ChaseControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ChaseControl__ros_msg_type * ros_message = static_cast<_ChaseControl__ros_msg_type *>(untyped_ros_message);
  // Field name: into_chase
  {
    cdr >> ros_message->into_chase;
  }

  // Field name: force_chase
  {
    cdr >> ros_message->force_chase;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__ChaseControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ChaseControl__ros_msg_type * ros_message = static_cast<const _ChaseControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name into_chase
  {
    size_t item_size = sizeof(ros_message->into_chase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name force_chase
  {
    size_t item_size = sizeof(ros_message->force_chase);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ChaseControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__ChaseControl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__ChaseControl(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: into_chase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: force_chase
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ChaseControl__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__ChaseControl(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ChaseControl = {
  "rm_autonomy_interfaces::msg",
  "ChaseControl",
  _ChaseControl__cdr_serialize,
  _ChaseControl__cdr_deserialize,
  _ChaseControl__get_serialized_size,
  _ChaseControl__max_serialized_size
};

static rosidl_message_type_support_t _ChaseControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ChaseControl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, ChaseControl)() {
  return &_ChaseControl__type_support;
}

#if defined(__cplusplus)
}
#endif
