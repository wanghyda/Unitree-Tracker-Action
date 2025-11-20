// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/AllyRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__AllyRobotPosition __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__AllyRobotPosition __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AllyRobotPosition_
{
  using Type = AllyRobotPosition_<ContainerAllocator>;

  explicit AllyRobotPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ally_1_position_x = 0.0f;
      this->ally_1_position_y = 0.0f;
      this->ally_2_position_x = 0.0f;
      this->ally_2_position_y = 0.0f;
      this->ally_3_position_x = 0.0f;
      this->ally_3_position_y = 0.0f;
      this->ally_4_position_x = 0.0f;
      this->ally_4_position_y = 0.0f;
      this->ally_5_position_x = 0.0f;
      this->ally_5_position_y = 0.0f;
      this->ally_7_position_x = 0.0f;
      this->ally_7_position_y = 0.0f;
    }
  }

  explicit AllyRobotPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ally_1_position_x = 0.0f;
      this->ally_1_position_y = 0.0f;
      this->ally_2_position_x = 0.0f;
      this->ally_2_position_y = 0.0f;
      this->ally_3_position_x = 0.0f;
      this->ally_3_position_y = 0.0f;
      this->ally_4_position_x = 0.0f;
      this->ally_4_position_y = 0.0f;
      this->ally_5_position_x = 0.0f;
      this->ally_5_position_y = 0.0f;
      this->ally_7_position_x = 0.0f;
      this->ally_7_position_y = 0.0f;
    }
  }

  // field types and members
  using _ally_1_position_x_type =
    float;
  _ally_1_position_x_type ally_1_position_x;
  using _ally_1_position_y_type =
    float;
  _ally_1_position_y_type ally_1_position_y;
  using _ally_2_position_x_type =
    float;
  _ally_2_position_x_type ally_2_position_x;
  using _ally_2_position_y_type =
    float;
  _ally_2_position_y_type ally_2_position_y;
  using _ally_3_position_x_type =
    float;
  _ally_3_position_x_type ally_3_position_x;
  using _ally_3_position_y_type =
    float;
  _ally_3_position_y_type ally_3_position_y;
  using _ally_4_position_x_type =
    float;
  _ally_4_position_x_type ally_4_position_x;
  using _ally_4_position_y_type =
    float;
  _ally_4_position_y_type ally_4_position_y;
  using _ally_5_position_x_type =
    float;
  _ally_5_position_x_type ally_5_position_x;
  using _ally_5_position_y_type =
    float;
  _ally_5_position_y_type ally_5_position_y;
  using _ally_7_position_x_type =
    float;
  _ally_7_position_x_type ally_7_position_x;
  using _ally_7_position_y_type =
    float;
  _ally_7_position_y_type ally_7_position_y;

  // setters for named parameter idiom
  Type & set__ally_1_position_x(
    const float & _arg)
  {
    this->ally_1_position_x = _arg;
    return *this;
  }
  Type & set__ally_1_position_y(
    const float & _arg)
  {
    this->ally_1_position_y = _arg;
    return *this;
  }
  Type & set__ally_2_position_x(
    const float & _arg)
  {
    this->ally_2_position_x = _arg;
    return *this;
  }
  Type & set__ally_2_position_y(
    const float & _arg)
  {
    this->ally_2_position_y = _arg;
    return *this;
  }
  Type & set__ally_3_position_x(
    const float & _arg)
  {
    this->ally_3_position_x = _arg;
    return *this;
  }
  Type & set__ally_3_position_y(
    const float & _arg)
  {
    this->ally_3_position_y = _arg;
    return *this;
  }
  Type & set__ally_4_position_x(
    const float & _arg)
  {
    this->ally_4_position_x = _arg;
    return *this;
  }
  Type & set__ally_4_position_y(
    const float & _arg)
  {
    this->ally_4_position_y = _arg;
    return *this;
  }
  Type & set__ally_5_position_x(
    const float & _arg)
  {
    this->ally_5_position_x = _arg;
    return *this;
  }
  Type & set__ally_5_position_y(
    const float & _arg)
  {
    this->ally_5_position_y = _arg;
    return *this;
  }
  Type & set__ally_7_position_x(
    const float & _arg)
  {
    this->ally_7_position_x = _arg;
    return *this;
  }
  Type & set__ally_7_position_y(
    const float & _arg)
  {
    this->ally_7_position_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__AllyRobotPosition
    std::shared_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__AllyRobotPosition
    std::shared_ptr<rm_autonomy_interfaces::msg::AllyRobotPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AllyRobotPosition_ & other) const
  {
    if (this->ally_1_position_x != other.ally_1_position_x) {
      return false;
    }
    if (this->ally_1_position_y != other.ally_1_position_y) {
      return false;
    }
    if (this->ally_2_position_x != other.ally_2_position_x) {
      return false;
    }
    if (this->ally_2_position_y != other.ally_2_position_y) {
      return false;
    }
    if (this->ally_3_position_x != other.ally_3_position_x) {
      return false;
    }
    if (this->ally_3_position_y != other.ally_3_position_y) {
      return false;
    }
    if (this->ally_4_position_x != other.ally_4_position_x) {
      return false;
    }
    if (this->ally_4_position_y != other.ally_4_position_y) {
      return false;
    }
    if (this->ally_5_position_x != other.ally_5_position_x) {
      return false;
    }
    if (this->ally_5_position_y != other.ally_5_position_y) {
      return false;
    }
    if (this->ally_7_position_x != other.ally_7_position_x) {
      return false;
    }
    if (this->ally_7_position_y != other.ally_7_position_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const AllyRobotPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AllyRobotPosition_

// alias to use template instance with default allocator
using AllyRobotPosition =
  rm_autonomy_interfaces::msg::AllyRobotPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALLY_ROBOT_POSITION__STRUCT_HPP_
