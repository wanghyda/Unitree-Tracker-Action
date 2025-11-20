// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/game_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_autonomy_interfaces/msg/detail/game_status__struct.hpp"

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
  const rm_autonomy_interfaces::msg::GameStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stage_progress
  cdr << ros_message.stage_progress;
  // Member: stage_remain_time
  cdr << ros_message.stage_remain_time;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_autonomy_interfaces::msg::GameStatus & ros_message)
{
  // Member: stage_progress
  cdr >> ros_message.stage_progress;

  // Member: stage_remain_time
  cdr >> ros_message.stage_remain_time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
get_serialized_size(
  const rm_autonomy_interfaces::msg::GameStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: stage_progress
  {
    size_t item_size = sizeof(ros_message.stage_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stage_remain_time
  {
    size_t item_size = sizeof(ros_message.stage_remain_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
max_serialized_size_GameStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: stage_progress
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stage_remain_time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _GameStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::GameStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GameStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_autonomy_interfaces::msg::GameStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GameStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::GameStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GameStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GameStatus(full_bounded, 0);
}

static message_type_support_callbacks_t _GameStatus__callbacks = {
  "rm_autonomy_interfaces::msg",
  "GameStatus",
  _GameStatus__cdr_serialize,
  _GameStatus__cdr_deserialize,
  _GameStatus__get_serialized_size,
  _GameStatus__max_serialized_size
};

static rosidl_message_type_support_t _GameStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GameStatus__callbacks,
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
get_message_type_support_handle<rm_autonomy_interfaces::msg::GameStatus>()
{
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_GameStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_autonomy_interfaces, msg, GameStatus)() {
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_GameStatus__handle;
}

#ifdef __cplusplus
}
#endif
