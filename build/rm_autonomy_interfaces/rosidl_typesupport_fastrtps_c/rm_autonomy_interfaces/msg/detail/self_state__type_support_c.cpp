// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/self_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_autonomy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_autonomy_interfaces/msg/detail/self_state__struct.h"
#include "rm_autonomy_interfaces/msg/detail/self_state__functions.h"
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


using _SelfState__ros_msg_type = rm_autonomy_interfaces__msg__SelfState;

static bool _SelfState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SelfState__ros_msg_type * ros_message = static_cast<const _SelfState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_id
  {
    cdr << ros_message->robot_id;
  }

  // Field name: current_hp
  {
    cdr << ros_message->current_hp;
  }

  // Field name: patrol_rfid
  {
    cdr << ros_message->patrol_rfid;
  }

  // Field name: energy_rfid
  {
    cdr << ros_message->energy_rfid;
  }

  // Field name: under_attack
  {
    cdr << ros_message->under_attack;
  }

  // Field name: current_ammo
  {
    cdr << ros_message->current_ammo;
  }

  // Field name: energy_left
  {
    cdr << ros_message->energy_left;
  }

  // Field name: decision_set
  {
    cdr << ros_message->decision_set;
  }

  return true;
}

static bool _SelfState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SelfState__ros_msg_type * ros_message = static_cast<_SelfState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_id
  {
    cdr >> ros_message->robot_id;
  }

  // Field name: current_hp
  {
    cdr >> ros_message->current_hp;
  }

  // Field name: patrol_rfid
  {
    cdr >> ros_message->patrol_rfid;
  }

  // Field name: energy_rfid
  {
    cdr >> ros_message->energy_rfid;
  }

  // Field name: under_attack
  {
    cdr >> ros_message->under_attack;
  }

  // Field name: current_ammo
  {
    cdr >> ros_message->current_ammo;
  }

  // Field name: energy_left
  {
    cdr >> ros_message->energy_left;
  }

  // Field name: decision_set
  {
    cdr >> ros_message->decision_set;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t get_serialized_size_rm_autonomy_interfaces__msg__SelfState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SelfState__ros_msg_type * ros_message = static_cast<const _SelfState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_id
  {
    size_t item_size = sizeof(ros_message->robot_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_hp
  {
    size_t item_size = sizeof(ros_message->current_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name patrol_rfid
  {
    size_t item_size = sizeof(ros_message->patrol_rfid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name energy_rfid
  {
    size_t item_size = sizeof(ros_message->energy_rfid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name under_attack
  {
    size_t item_size = sizeof(ros_message->under_attack);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_ammo
  {
    size_t item_size = sizeof(ros_message->current_ammo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name energy_left
  {
    size_t item_size = sizeof(ros_message->energy_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name decision_set
  {
    size_t item_size = sizeof(ros_message->decision_set);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SelfState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_autonomy_interfaces__msg__SelfState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_autonomy_interfaces
size_t max_serialized_size_rm_autonomy_interfaces__msg__SelfState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: robot_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: current_hp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: patrol_rfid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: energy_rfid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: under_attack
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: current_ammo
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: energy_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: decision_set
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SelfState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rm_autonomy_interfaces__msg__SelfState(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SelfState = {
  "rm_autonomy_interfaces::msg",
  "SelfState",
  _SelfState__cdr_serialize,
  _SelfState__cdr_deserialize,
  _SelfState__get_serialized_size,
  _SelfState__max_serialized_size
};

static rosidl_message_type_support_t _SelfState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SelfState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_autonomy_interfaces, msg, SelfState)() {
  return &_SelfState__type_support;
}

#if defined(__cplusplus)
}
#endif
