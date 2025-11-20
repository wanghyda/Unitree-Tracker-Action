// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/arena_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_autonomy_interfaces/msg/detail/arena_status__struct.hpp"

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
  const rm_autonomy_interfaces::msg::ArenaStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: healing_front
  cdr << ros_message.healing_front;
  // Member: healing_inner
  cdr << ros_message.healing_inner;
  // Member: rmul_healing
  cdr << ros_message.rmul_healing;
  // Member: energy_occupy_status
  cdr << ros_message.energy_occupy_status;
  // Member: energy_small_status
  cdr << ros_message.energy_small_status;
  // Member: energy_big_status
  cdr << ros_message.energy_big_status;
  // Member: ring_highground_status
  cdr << ros_message.ring_highground_status;
  // Member: trapezoid_highground_status
  cdr << ros_message.trapezoid_highground_status;
  // Member: base_shield_percentage
  cdr << ros_message.base_shield_percentage;
  // Member: rump_central_buff_status
  cdr << ros_message.rump_central_buff_status;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_autonomy_interfaces::msg::ArenaStatus & ros_message)
{
  // Member: healing_front
  cdr >> ros_message.healing_front;

  // Member: healing_inner
  cdr >> ros_message.healing_inner;

  // Member: rmul_healing
  cdr >> ros_message.rmul_healing;

  // Member: energy_occupy_status
  cdr >> ros_message.energy_occupy_status;

  // Member: energy_small_status
  cdr >> ros_message.energy_small_status;

  // Member: energy_big_status
  cdr >> ros_message.energy_big_status;

  // Member: ring_highground_status
  cdr >> ros_message.ring_highground_status;

  // Member: trapezoid_highground_status
  cdr >> ros_message.trapezoid_highground_status;

  // Member: base_shield_percentage
  cdr >> ros_message.base_shield_percentage;

  // Member: rump_central_buff_status
  cdr >> ros_message.rump_central_buff_status;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
get_serialized_size(
  const rm_autonomy_interfaces::msg::ArenaStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: healing_front
  {
    size_t item_size = sizeof(ros_message.healing_front);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: healing_inner
  {
    size_t item_size = sizeof(ros_message.healing_inner);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rmul_healing
  {
    size_t item_size = sizeof(ros_message.rmul_healing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: energy_occupy_status
  {
    size_t item_size = sizeof(ros_message.energy_occupy_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: energy_small_status
  {
    size_t item_size = sizeof(ros_message.energy_small_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: energy_big_status
  {
    size_t item_size = sizeof(ros_message.energy_big_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ring_highground_status
  {
    size_t item_size = sizeof(ros_message.ring_highground_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: trapezoid_highground_status
  {
    size_t item_size = sizeof(ros_message.trapezoid_highground_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: base_shield_percentage
  {
    size_t item_size = sizeof(ros_message.base_shield_percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rump_central_buff_status
  {
    size_t item_size = sizeof(ros_message.rump_central_buff_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
max_serialized_size_ArenaStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: healing_front
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: healing_inner
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rmul_healing
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: energy_occupy_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: energy_small_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: energy_big_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ring_highground_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: trapezoid_highground_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: base_shield_percentage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rump_central_buff_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ArenaStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::ArenaStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArenaStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_autonomy_interfaces::msg::ArenaStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArenaStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::ArenaStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArenaStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ArenaStatus(full_bounded, 0);
}

static message_type_support_callbacks_t _ArenaStatus__callbacks = {
  "rm_autonomy_interfaces::msg",
  "ArenaStatus",
  _ArenaStatus__cdr_serialize,
  _ArenaStatus__cdr_deserialize,
  _ArenaStatus__get_serialized_size,
  _ArenaStatus__max_serialized_size
};

static rosidl_message_type_support_t _ArenaStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArenaStatus__callbacks,
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
get_message_type_support_handle<rm_autonomy_interfaces::msg::ArenaStatus>()
{
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_ArenaStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_autonomy_interfaces, msg, ArenaStatus)() {
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_ArenaStatus__handle;
}

#ifdef __cplusplus
}
#endif
