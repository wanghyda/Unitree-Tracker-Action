// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__struct.h"
#include "rm_autonomy_interfaces/msg/detail/radar_enemy_position__functions.h"
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


using _RadarEnemyPosition__ros_msg_type = rm_autonomy_interfaces__msg__RadarEnemyPosition;

static bool _RadarEnemyPosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RadarEnemyPosition__ros_msg_type * ros_message = static_cast<const _RadarEnemyPosition__ros_msg_type *>(untyped_ros_message);
  // Field name: enemy_1_position_x
  {
    cdr << ros_message->enemy_1_position_x;
  }

  // Field name: enemy_1_position_y
  {
    cdr << ros_message->enemy_1_position_y;
  }

  // Field name: enemy_2_position_x
  {
    cdr << ros_message->enemy_2_position_x;
  }

  // Field name: enemy_2_position_y
  {
    cdr << ros_message->enemy_2_position_y;
  }

  // Field name: enemy_3_position_x
  {
    cdr << ros_message->enemy_3_position_x;
  }

  // Field name: enemy_3_position_y
  {
    cdr << ros_message->enemy_3_position_y;
  }

  // Field name: enemy_4_position_x
  {
    cdr << ros_message->enemy_4_position_x;
  }

  // Field name: enemy_4_position_y
  {
    cdr << ros_message->enemy_4_position_y;
  }

  // Field name: enemy_5_position_x
  {
    cdr << ros_message->enemy_5_position_x;
  }

  // Field name: enemy_5_position_y
  {
    cdr << ros_message->enemy_5_position_y;
  }

  // Field name: enemy_7_position_x
  {
    cdr << ros_message->enemy_7_position_x;
  }

  // Field name: enemy_7_position_y
  {
    cdr << ros_message->enemy_7_position_y;
  }

  return true;
}

static bool _RadarEnemyPosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RadarEnemyPosition__ros_msg_type * ros_message = static_cast<_RadarEnemyPosition__ros_msg_type *>(untyped_ros_message);
  // Field name: enemy_1_position_x
  {
    cdr >> ros_message->enemy_1_position_x;
  }

  // Field name: enemy_1_position_y
  {
    cdr >> ros_message->enemy_1_position_y;
  }

  // Field name: enemy_2_position_x
  {
    cdr >> ros_message->enemy_2_position_x;
  }

  // Field name: enemy_2_position_y
  {
    cdr >> ros_message->enemy_2_position_y;
  }

  // Field name: enemy_3_position_x
  {
    cdr >> ros_message->enemy_3_position_x;
  }

  // Field name: enemy_3_position_y
  {
    cdr >> ros_message->enemy_3_position_y;
  }

  // Field name: enemy_4_position_x
  {
    cdr >> ros_message->enemy_4_position_x;
  }

  // Field name: enemy_4_position_y
  {
    cdr >> ros_message->enemy_4_position_y;
  }

  // Field name: enemy_5_position_x
  {
    cdr >> ros_message->enemy_5_position_x;
  }

  // Field name: enemy_5_position_y
  {
    cdr >> ros_message->enemy_5_position_y;
  }

  // Field name: enemy_7_position_x
  {
    cdr >> ros_message->enemy_7_position_x;
  }

  // Field name: enemy_7_position_y
  {
    cdr >> ros_message->enemy_7_position_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__RadarEnemyPosition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RadarEnemyPosition__ros_msg_type * ros_message = static_cast<const _RadarEnemyPosition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name enemy_1_position_x
  {
    size_t item_size = sizeof(ros_message->enemy_1_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_1_position_y
  {
    size_t item_size = sizeof(ros_message->enemy_1_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_2_position_x
  {
    size_t item_size = sizeof(ros_message->enemy_2_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_2_position_y
  {
    size_t item_size = sizeof(ros_message->enemy_2_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_3_position_x
  {
    size_t item_size = sizeof(ros_message->enemy_3_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_3_position_y
  {
    size_t item_size = sizeof(ros_message->enemy_3_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_4_position_x
  {
    size_t item_size = sizeof(ros_message->enemy_4_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_4_position_y
  {
    size_t item_size = sizeof(ros_message->enemy_4_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_5_position_x
  {
    size_t item_size = sizeof(ros_message->enemy_5_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_5_position_y
  {
    size_t item_size = sizeof(ros_message->enemy_5_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_7_position_x
  {
    size_t item_size = sizeof(ros_message->enemy_7_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_7_position_y
  {
    size_t item_size = sizeof(ros_message->enemy_7_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RadarEnemyPosition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__RadarEnemyPosition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__RadarEnemyPosition(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: enemy_1_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_1_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_2_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_2_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_3_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_3_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_4_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_4_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_5_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_5_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_7_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_7_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RadarEnemyPosition__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__RadarEnemyPosition(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RadarEnemyPosition = {
  "rm_autonomy_interfaces::msg",
  "RadarEnemyPosition",
  _RadarEnemyPosition__cdr_serialize,
  _RadarEnemyPosition__cdr_deserialize,
  _RadarEnemyPosition__get_serialized_size,
  _RadarEnemyPosition__max_serialized_size
};

static rosidl_message_type_support_t _RadarEnemyPosition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RadarEnemyPosition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, RadarEnemyPosition)() {
  return &_RadarEnemyPosition__type_support;
}

#if defined(__cplusplus)
}
#endif
