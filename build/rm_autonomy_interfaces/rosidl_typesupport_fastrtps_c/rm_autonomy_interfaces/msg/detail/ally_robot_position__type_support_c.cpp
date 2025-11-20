// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__struct.h"
#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__functions.h"
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


using _AllyRobotPosition__ros_msg_type = rm_autonomy_interfaces__msg__AllyRobotPosition;

static bool _AllyRobotPosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AllyRobotPosition__ros_msg_type * ros_message = static_cast<const _AllyRobotPosition__ros_msg_type *>(untyped_ros_message);
  // Field name: ally_1_position_x
  {
    cdr << ros_message->ally_1_position_x;
  }

  // Field name: ally_1_position_y
  {
    cdr << ros_message->ally_1_position_y;
  }

  // Field name: ally_2_position_x
  {
    cdr << ros_message->ally_2_position_x;
  }

  // Field name: ally_2_position_y
  {
    cdr << ros_message->ally_2_position_y;
  }

  // Field name: ally_3_position_x
  {
    cdr << ros_message->ally_3_position_x;
  }

  // Field name: ally_3_position_y
  {
    cdr << ros_message->ally_3_position_y;
  }

  // Field name: ally_4_position_x
  {
    cdr << ros_message->ally_4_position_x;
  }

  // Field name: ally_4_position_y
  {
    cdr << ros_message->ally_4_position_y;
  }

  // Field name: ally_5_position_x
  {
    cdr << ros_message->ally_5_position_x;
  }

  // Field name: ally_5_position_y
  {
    cdr << ros_message->ally_5_position_y;
  }

  // Field name: ally_7_position_x
  {
    cdr << ros_message->ally_7_position_x;
  }

  // Field name: ally_7_position_y
  {
    cdr << ros_message->ally_7_position_y;
  }

  return true;
}

static bool _AllyRobotPosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AllyRobotPosition__ros_msg_type * ros_message = static_cast<_AllyRobotPosition__ros_msg_type *>(untyped_ros_message);
  // Field name: ally_1_position_x
  {
    cdr >> ros_message->ally_1_position_x;
  }

  // Field name: ally_1_position_y
  {
    cdr >> ros_message->ally_1_position_y;
  }

  // Field name: ally_2_position_x
  {
    cdr >> ros_message->ally_2_position_x;
  }

  // Field name: ally_2_position_y
  {
    cdr >> ros_message->ally_2_position_y;
  }

  // Field name: ally_3_position_x
  {
    cdr >> ros_message->ally_3_position_x;
  }

  // Field name: ally_3_position_y
  {
    cdr >> ros_message->ally_3_position_y;
  }

  // Field name: ally_4_position_x
  {
    cdr >> ros_message->ally_4_position_x;
  }

  // Field name: ally_4_position_y
  {
    cdr >> ros_message->ally_4_position_y;
  }

  // Field name: ally_5_position_x
  {
    cdr >> ros_message->ally_5_position_x;
  }

  // Field name: ally_5_position_y
  {
    cdr >> ros_message->ally_5_position_y;
  }

  // Field name: ally_7_position_x
  {
    cdr >> ros_message->ally_7_position_x;
  }

  // Field name: ally_7_position_y
  {
    cdr >> ros_message->ally_7_position_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__AllyRobotPosition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AllyRobotPosition__ros_msg_type * ros_message = static_cast<const _AllyRobotPosition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ally_1_position_x
  {
    size_t item_size = sizeof(ros_message->ally_1_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_1_position_y
  {
    size_t item_size = sizeof(ros_message->ally_1_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_2_position_x
  {
    size_t item_size = sizeof(ros_message->ally_2_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_2_position_y
  {
    size_t item_size = sizeof(ros_message->ally_2_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_3_position_x
  {
    size_t item_size = sizeof(ros_message->ally_3_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_3_position_y
  {
    size_t item_size = sizeof(ros_message->ally_3_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_4_position_x
  {
    size_t item_size = sizeof(ros_message->ally_4_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_4_position_y
  {
    size_t item_size = sizeof(ros_message->ally_4_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_5_position_x
  {
    size_t item_size = sizeof(ros_message->ally_5_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_5_position_y
  {
    size_t item_size = sizeof(ros_message->ally_5_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_7_position_x
  {
    size_t item_size = sizeof(ros_message->ally_7_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ally_7_position_y
  {
    size_t item_size = sizeof(ros_message->ally_7_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AllyRobotPosition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__AllyRobotPosition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__AllyRobotPosition(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: ally_1_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_1_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_2_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_2_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_3_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_3_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_4_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_4_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_5_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_5_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_7_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ally_7_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _AllyRobotPosition__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__AllyRobotPosition(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_AllyRobotPosition = {
  "rm_autonomy_interfaces::msg",
  "AllyRobotPosition",
  _AllyRobotPosition__cdr_serialize,
  _AllyRobotPosition__cdr_deserialize,
  _AllyRobotPosition__get_serialized_size,
  _AllyRobotPosition__max_serialized_size
};

static rosidl_message_type_support_t _AllyRobotPosition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AllyRobotPosition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, AllyRobotPosition)() {
  return &_AllyRobotPosition__type_support;
}

#if defined(__cplusplus)
}
#endif
