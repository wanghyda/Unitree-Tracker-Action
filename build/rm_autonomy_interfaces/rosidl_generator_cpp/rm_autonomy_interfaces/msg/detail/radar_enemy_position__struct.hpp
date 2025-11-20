// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/RadarEnemyPosition.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__RadarEnemyPosition __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__RadarEnemyPosition __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarEnemyPosition_
{
  using Type = RadarEnemyPosition_<ContainerAllocator>;

  explicit RadarEnemyPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enemy_1_position_x = 0.0f;
      this->enemy_1_position_y = 0.0f;
      this->enemy_2_position_x = 0.0f;
      this->enemy_2_position_y = 0.0f;
      this->enemy_3_position_x = 0.0f;
      this->enemy_3_position_y = 0.0f;
      this->enemy_4_position_x = 0.0f;
      this->enemy_4_position_y = 0.0f;
      this->enemy_5_position_x = 0.0f;
      this->enemy_5_position_y = 0.0f;
      this->enemy_7_position_x = 0.0f;
      this->enemy_7_position_y = 0.0f;
    }
  }

  explicit RadarEnemyPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enemy_1_position_x = 0.0f;
      this->enemy_1_position_y = 0.0f;
      this->enemy_2_position_x = 0.0f;
      this->enemy_2_position_y = 0.0f;
      this->enemy_3_position_x = 0.0f;
      this->enemy_3_position_y = 0.0f;
      this->enemy_4_position_x = 0.0f;
      this->enemy_4_position_y = 0.0f;
      this->enemy_5_position_x = 0.0f;
      this->enemy_5_position_y = 0.0f;
      this->enemy_7_position_x = 0.0f;
      this->enemy_7_position_y = 0.0f;
    }
  }

  // field types and members
  using _enemy_1_position_x_type =
    float;
  _enemy_1_position_x_type enemy_1_position_x;
  using _enemy_1_position_y_type =
    float;
  _enemy_1_position_y_type enemy_1_position_y;
  using _enemy_2_position_x_type =
    float;
  _enemy_2_position_x_type enemy_2_position_x;
  using _enemy_2_position_y_type =
    float;
  _enemy_2_position_y_type enemy_2_position_y;
  using _enemy_3_position_x_type =
    float;
  _enemy_3_position_x_type enemy_3_position_x;
  using _enemy_3_position_y_type =
    float;
  _enemy_3_position_y_type enemy_3_position_y;
  using _enemy_4_position_x_type =
    float;
  _enemy_4_position_x_type enemy_4_position_x;
  using _enemy_4_position_y_type =
    float;
  _enemy_4_position_y_type enemy_4_position_y;
  using _enemy_5_position_x_type =
    float;
  _enemy_5_position_x_type enemy_5_position_x;
  using _enemy_5_position_y_type =
    float;
  _enemy_5_position_y_type enemy_5_position_y;
  using _enemy_7_position_x_type =
    float;
  _enemy_7_position_x_type enemy_7_position_x;
  using _enemy_7_position_y_type =
    float;
  _enemy_7_position_y_type enemy_7_position_y;

  // setters for named parameter idiom
  Type & set__enemy_1_position_x(
    const float & _arg)
  {
    this->enemy_1_position_x = _arg;
    return *this;
  }
  Type & set__enemy_1_position_y(
    const float & _arg)
  {
    this->enemy_1_position_y = _arg;
    return *this;
  }
  Type & set__enemy_2_position_x(
    const float & _arg)
  {
    this->enemy_2_position_x = _arg;
    return *this;
  }
  Type & set__enemy_2_position_y(
    const float & _arg)
  {
    this->enemy_2_position_y = _arg;
    return *this;
  }
  Type & set__enemy_3_position_x(
    const float & _arg)
  {
    this->enemy_3_position_x = _arg;
    return *this;
  }
  Type & set__enemy_3_position_y(
    const float & _arg)
  {
    this->enemy_3_position_y = _arg;
    return *this;
  }
  Type & set__enemy_4_position_x(
    const float & _arg)
  {
    this->enemy_4_position_x = _arg;
    return *this;
  }
  Type & set__enemy_4_position_y(
    const float & _arg)
  {
    this->enemy_4_position_y = _arg;
    return *this;
  }
  Type & set__enemy_5_position_x(
    const float & _arg)
  {
    this->enemy_5_position_x = _arg;
    return *this;
  }
  Type & set__enemy_5_position_y(
    const float & _arg)
  {
    this->enemy_5_position_y = _arg;
    return *this;
  }
  Type & set__enemy_7_position_x(
    const float & _arg)
  {
    this->enemy_7_position_x = _arg;
    return *this;
  }
  Type & set__enemy_7_position_y(
    const float & _arg)
  {
    this->enemy_7_position_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__RadarEnemyPosition
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__RadarEnemyPosition
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarEnemyPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarEnemyPosition_ & other) const
  {
    if (this->enemy_1_position_x != other.enemy_1_position_x) {
      return false;
    }
    if (this->enemy_1_position_y != other.enemy_1_position_y) {
      return false;
    }
    if (this->enemy_2_position_x != other.enemy_2_position_x) {
      return false;
    }
    if (this->enemy_2_position_y != other.enemy_2_position_y) {
      return false;
    }
    if (this->enemy_3_position_x != other.enemy_3_position_x) {
      return false;
    }
    if (this->enemy_3_position_y != other.enemy_3_position_y) {
      return false;
    }
    if (this->enemy_4_position_x != other.enemy_4_position_x) {
      return false;
    }
    if (this->enemy_4_position_y != other.enemy_4_position_y) {
      return false;
    }
    if (this->enemy_5_position_x != other.enemy_5_position_x) {
      return false;
    }
    if (this->enemy_5_position_y != other.enemy_5_position_y) {
      return false;
    }
    if (this->enemy_7_position_x != other.enemy_7_position_x) {
      return false;
    }
    if (this->enemy_7_position_y != other.enemy_7_position_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarEnemyPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarEnemyPosition_

// alias to use template instance with default allocator
using RadarEnemyPosition =
  rm_autonomy_interfaces::msg::RadarEnemyPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_ENEMY_POSITION__STRUCT_HPP_
