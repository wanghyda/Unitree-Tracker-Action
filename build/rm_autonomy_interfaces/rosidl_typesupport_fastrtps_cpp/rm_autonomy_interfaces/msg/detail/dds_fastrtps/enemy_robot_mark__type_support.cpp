// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_autonomy_interfaces/msg/detail/enemy_robot_mark__struct.hpp"

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
  const rm_autonomy_interfaces::msg::EnemyRobotMark & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enemy_1_mark
  cdr << ros_message.enemy_1_mark;
  // Member: enemy_2_mark
  cdr << ros_message.enemy_2_mark;
  // Member: enemy_3_mark
  cdr << ros_message.enemy_3_mark;
  // Member: enemy_4_mark
  cdr << ros_message.enemy_4_mark;
  // Member: enemy_5_mark
  cdr << ros_message.enemy_5_mark;
  // Member: enemy_7_mark
  cdr << ros_message.enemy_7_mark;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_autonomy_interfaces::msg::EnemyRobotMark & ros_message)
{
  // Member: enemy_1_mark
  cdr >> ros_message.enemy_1_mark;

  // Member: enemy_2_mark
  cdr >> ros_message.enemy_2_mark;

  // Member: enemy_3_mark
  cdr >> ros_message.enemy_3_mark;

  // Member: enemy_4_mark
  cdr >> ros_message.enemy_4_mark;

  // Member: enemy_5_mark
  cdr >> ros_message.enemy_5_mark;

  // Member: enemy_7_mark
  cdr >> ros_message.enemy_7_mark;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
get_serialized_size(
  const rm_autonomy_interfaces::msg::EnemyRobotMark & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enemy_1_mark
  {
    size_t item_size = sizeof(ros_message.enemy_1_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_2_mark
  {
    size_t item_size = sizeof(ros_message.enemy_2_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_3_mark
  {
    size_t item_size = sizeof(ros_message.enemy_3_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_4_mark
  {
    size_t item_size = sizeof(ros_message.enemy_4_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_5_mark
  {
    size_t item_size = sizeof(ros_message.enemy_5_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enemy_7_mark
  {
    size_t item_size = sizeof(ros_message.enemy_7_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
max_serialized_size_EnemyRobotMark(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: enemy_1_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_2_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_3_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_4_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_5_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_7_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _EnemyRobotMark__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::EnemyRobotMark *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _EnemyRobotMark__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_autonomy_interfaces::msg::EnemyRobotMark *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _EnemyRobotMark__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::EnemyRobotMark *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _EnemyRobotMark__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_EnemyRobotMark(full_bounded, 0);
}

static message_type_support_callbacks_t _EnemyRobotMark__callbacks = {
  "rm_autonomy_interfaces::msg",
  "EnemyRobotMark",
  _EnemyRobotMark__cdr_serialize,
  _EnemyRobotMark__cdr_deserialize,
  _EnemyRobotMark__get_serialized_size,
  _EnemyRobotMark__max_serialized_size
};

static rosidl_message_type_support_t _EnemyRobotMark__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_EnemyRobotMark__callbacks,
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
get_message_type_support_handle<rm_autonomy_interfaces::msg::EnemyRobotMark>()
{
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_EnemyRobotMark__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_autonomy_interfaces, msg, EnemyRobotMark)() {
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_EnemyRobotMark__handle;
}

#ifdef __cplusplus
}
#endif
