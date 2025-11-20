// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/NavigateCommand.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/navigate_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/navigate_command__struct.h"
#include "rm_autonomy_interfaces/msg/detail/navigate_command__functions.h"
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


using _NavigateCommand__ros_msg_type = rm_autonomy_interfaces__msg__NavigateCommand;

static bool _NavigateCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NavigateCommand__ros_msg_type * ros_message = static_cast<const _NavigateCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: spin_speed
  {
    cdr << ros_message->spin_speed;
  }

  // Field name: scap_state
  {
    cdr << (ros_message->scap_state ? true : false);
  }

  // Field name: align_chassis_big_yaw
  {
    cdr << (ros_message->align_chassis_big_yaw ? true : false);
  }

  return true;
}

static bool _NavigateCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NavigateCommand__ros_msg_type * ros_message = static_cast<_NavigateCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: spin_speed
  {
    cdr >> ros_message->spin_speed;
  }

  // Field name: scap_state
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->scap_state = tmp ? true : false;
  }

  // Field name: align_chassis_big_yaw
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->align_chassis_big_yaw = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__NavigateCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavigateCommand__ros_msg_type * ros_message = static_cast<const _NavigateCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name spin_speed
  {
    size_t item_size = sizeof(ros_message->spin_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name scap_state
  {
    size_t item_size = sizeof(ros_message->scap_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name align_chassis_big_yaw
  {
    size_t item_size = sizeof(ros_message->align_chassis_big_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NavigateCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__NavigateCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__NavigateCommand(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: spin_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: scap_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: align_chassis_big_yaw
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _NavigateCommand__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__NavigateCommand(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_NavigateCommand = {
  "rm_autonomy_interfaces::msg",
  "NavigateCommand",
  _NavigateCommand__cdr_serialize,
  _NavigateCommand__cdr_deserialize,
  _NavigateCommand__get_serialized_size,
  _NavigateCommand__max_serialized_size
};

static rosidl_message_type_support_t _NavigateCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavigateCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, NavigateCommand)() {
  return &_NavigateCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
