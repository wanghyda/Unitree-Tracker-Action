// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/arena_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/arena_status__struct.h"
#include "rm_autonomy_interfaces/msg/detail/arena_status__functions.h"
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


using _ArenaStatus__ros_msg_type = rm_autonomy_interfaces__msg__ArenaStatus;

static bool _ArenaStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ArenaStatus__ros_msg_type * ros_message = static_cast<const _ArenaStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: healing_front
  {
    cdr << ros_message->healing_front;
  }

  // Field name: healing_inner
  {
    cdr << ros_message->healing_inner;
  }

  // Field name: rmul_healing
  {
    cdr << ros_message->rmul_healing;
  }

  // Field name: energy_occupy_status
  {
    cdr << ros_message->energy_occupy_status;
  }

  // Field name: energy_small_status
  {
    cdr << ros_message->energy_small_status;
  }

  // Field name: energy_big_status
  {
    cdr << ros_message->energy_big_status;
  }

  // Field name: ring_highground_status
  {
    cdr << ros_message->ring_highground_status;
  }

  // Field name: trapezoid_highground_status
  {
    cdr << ros_message->trapezoid_highground_status;
  }

  // Field name: base_shield_percentage
  {
    cdr << ros_message->base_shield_percentage;
  }

  // Field name: rump_central_buff_status
  {
    cdr << ros_message->rump_central_buff_status;
  }

  return true;
}

static bool _ArenaStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ArenaStatus__ros_msg_type * ros_message = static_cast<_ArenaStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: healing_front
  {
    cdr >> ros_message->healing_front;
  }

  // Field name: healing_inner
  {
    cdr >> ros_message->healing_inner;
  }

  // Field name: rmul_healing
  {
    cdr >> ros_message->rmul_healing;
  }

  // Field name: energy_occupy_status
  {
    cdr >> ros_message->energy_occupy_status;
  }

  // Field name: energy_small_status
  {
    cdr >> ros_message->energy_small_status;
  }

  // Field name: energy_big_status
  {
    cdr >> ros_message->energy_big_status;
  }

  // Field name: ring_highground_status
  {
    cdr >> ros_message->ring_highground_status;
  }

  // Field name: trapezoid_highground_status
  {
    cdr >> ros_message->trapezoid_highground_status;
  }

  // Field name: base_shield_percentage
  {
    cdr >> ros_message->base_shield_percentage;
  }

  // Field name: rump_central_buff_status
  {
    cdr >> ros_message->rump_central_buff_status;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__ArenaStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ArenaStatus__ros_msg_type * ros_message = static_cast<const _ArenaStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name healing_front
  {
    size_t item_size = sizeof(ros_message->healing_front);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name healing_inner
  {
    size_t item_size = sizeof(ros_message->healing_inner);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rmul_healing
  {
    size_t item_size = sizeof(ros_message->rmul_healing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name energy_occupy_status
  {
    size_t item_size = sizeof(ros_message->energy_occupy_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name energy_small_status
  {
    size_t item_size = sizeof(ros_message->energy_small_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name energy_big_status
  {
    size_t item_size = sizeof(ros_message->energy_big_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ring_highground_status
  {
    size_t item_size = sizeof(ros_message->ring_highground_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name trapezoid_highground_status
  {
    size_t item_size = sizeof(ros_message->trapezoid_highground_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name base_shield_percentage
  {
    size_t item_size = sizeof(ros_message->base_shield_percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rump_central_buff_status
  {
    size_t item_size = sizeof(ros_message->rump_central_buff_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ArenaStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__ArenaStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__ArenaStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: healing_front
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: healing_inner
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rmul_healing
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: energy_occupy_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: energy_small_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: energy_big_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ring_highground_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: trapezoid_highground_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: base_shield_percentage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rump_central_buff_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ArenaStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__ArenaStatus(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ArenaStatus = {
  "rm_autonomy_interfaces::msg",
  "ArenaStatus",
  _ArenaStatus__cdr_serialize,
  _ArenaStatus__cdr_deserialize,
  _ArenaStatus__get_serialized_size,
  _ArenaStatus__max_serialized_size
};

static rosidl_message_type_support_t _ArenaStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ArenaStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, ArenaStatus)() {
  return &_ArenaStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
