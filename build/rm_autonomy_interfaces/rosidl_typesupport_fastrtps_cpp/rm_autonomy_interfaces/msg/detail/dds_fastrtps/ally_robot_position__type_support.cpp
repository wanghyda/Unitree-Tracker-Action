// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice
#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_autonomy_interfaces/msg/detail/ally_robot_position__struct.hpp"

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
  const rm_autonomy_interfaces::msg::AllyRobotPosition & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ally_1_position_x
  cdr << ros_message.ally_1_position_x;
  // Member: ally_1_position_y
  cdr << ros_message.ally_1_position_y;
  // Member: ally_2_position_x
  cdr << ros_message.ally_2_position_x;
  // Member: ally_2_position_y
  cdr << ros_message.ally_2_position_y;
  // Member: ally_3_position_x
  cdr << ros_message.ally_3_position_x;
  // Member: ally_3_position_y
  cdr << ros_message.ally_3_position_y;
  // Member: ally_4_position_x
  cdr << ros_message.ally_4_position_x;
  // Member: ally_4_position_y
  cdr << ros_message.ally_4_position_y;
  // Member: ally_5_position_x
  cdr << ros_message.ally_5_position_x;
  // Member: ally_5_position_y
  cdr << ros_message.ally_5_position_y;
  // Member: ally_7_position_x
  cdr << ros_message.ally_7_position_x;
  // Member: ally_7_position_y
  cdr << ros_message.ally_7_position_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_autonomy_interfaces::msg::AllyRobotPosition & ros_message)
{
  // Member: ally_1_position_x
  cdr >> ros_message.ally_1_position_x;

  // Member: ally_1_position_y
  cdr >> ros_message.ally_1_position_y;

  // Member: ally_2_position_x
  cdr >> ros_message.ally_2_position_x;

  // Member: ally_2_position_y
  cdr >> ros_message.ally_2_position_y;

  // Member: ally_3_position_x
  cdr >> ros_message.ally_3_position_x;

  // Member: ally_3_position_y
  cdr >> ros_message.ally_3_position_y;

  // Member: ally_4_position_x
  cdr >> ros_message.ally_4_position_x;

  // Member: ally_4_position_y
  cdr >> ros_message.ally_4_position_y;

  // Member: ally_5_position_x
  cdr >> ros_message.ally_5_position_x;

  // Member: ally_5_position_y
  cdr >> ros_message.ally_5_position_y;

  // Member: ally_7_position_x
  cdr >> ros_message.ally_7_position_x;

  // Member: ally_7_position_y
  cdr >> ros_message.ally_7_position_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
get_serialized_size(
  const rm_autonomy_interfaces::msg::AllyRobotPosition & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ally_1_position_x
  {
    size_t item_size = sizeof(ros_message.ally_1_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_1_position_y
  {
    size_t item_size = sizeof(ros_message.ally_1_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_2_position_x
  {
    size_t item_size = sizeof(ros_message.ally_2_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_2_position_y
  {
    size_t item_size = sizeof(ros_message.ally_2_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_3_position_x
  {
    size_t item_size = sizeof(ros_message.ally_3_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_3_position_y
  {
    size_t item_size = sizeof(ros_message.ally_3_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_4_position_x
  {
    size_t item_size = sizeof(ros_message.ally_4_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_4_position_y
  {
    size_t item_size = sizeof(ros_message.ally_4_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_5_position_x
  {
    size_t item_size = sizeof(ros_message.ally_5_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_5_position_y
  {
    size_t item_size = sizeof(ros_message.ally_5_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_7_position_x
  {
    size_t item_size = sizeof(ros_message.ally_7_position_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ally_7_position_y
  {
    size_t item_size = sizeof(ros_message.ally_7_position_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_autonomy_interfaces
max_serialized_size_AllyRobotPosition(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: ally_1_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_1_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_2_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_2_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_3_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_3_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_4_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_4_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_5_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_5_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_7_position_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ally_7_position_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _AllyRobotPosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::AllyRobotPosition *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _AllyRobotPosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_autonomy_interfaces::msg::AllyRobotPosition *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _AllyRobotPosition__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_autonomy_interfaces::msg::AllyRobotPosition *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _AllyRobotPosition__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_AllyRobotPosition(full_bounded, 0);
}

static message_type_support_callbacks_t _AllyRobotPosition__callbacks = {
  "rm_autonomy_interfaces::msg",
  "AllyRobotPosition",
  _AllyRobotPosition__cdr_serialize,
  _AllyRobotPosition__cdr_deserialize,
  _AllyRobotPosition__get_serialized_size,
  _AllyRobotPosition__max_serialized_size
};

static rosidl_message_type_support_t _AllyRobotPosition__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_AllyRobotPosition__callbacks,
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
get_message_type_support_handle<rm_autonomy_interfaces::msg::AllyRobotPosition>()
{
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_AllyRobotPosition__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_autonomy_interfaces, msg, AllyRobotPosition)() {
  return &rm_autonomy_interfaces::msg::typesupport_fastrtps_cpp::_AllyRobotPosition__handle;
}

#ifdef __cplusplus
}
#endif
