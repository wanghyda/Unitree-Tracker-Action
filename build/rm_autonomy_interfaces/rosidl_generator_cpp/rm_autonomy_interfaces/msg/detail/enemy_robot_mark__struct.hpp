// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/EnemyRobotMark.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__EnemyRobotMark __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__EnemyRobotMark __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EnemyRobotMark_
{
  using Type = EnemyRobotMark_<ContainerAllocator>;

  explicit EnemyRobotMark_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enemy_1_mark = 0;
      this->enemy_2_mark = 0;
      this->enemy_3_mark = 0;
      this->enemy_4_mark = 0;
      this->enemy_5_mark = 0;
      this->enemy_7_mark = 0;
    }
  }

  explicit EnemyRobotMark_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enemy_1_mark = 0;
      this->enemy_2_mark = 0;
      this->enemy_3_mark = 0;
      this->enemy_4_mark = 0;
      this->enemy_5_mark = 0;
      this->enemy_7_mark = 0;
    }
  }

  // field types and members
  using _enemy_1_mark_type =
    uint8_t;
  _enemy_1_mark_type enemy_1_mark;
  using _enemy_2_mark_type =
    uint8_t;
  _enemy_2_mark_type enemy_2_mark;
  using _enemy_3_mark_type =
    uint8_t;
  _enemy_3_mark_type enemy_3_mark;
  using _enemy_4_mark_type =
    uint8_t;
  _enemy_4_mark_type enemy_4_mark;
  using _enemy_5_mark_type =
    uint8_t;
  _enemy_5_mark_type enemy_5_mark;
  using _enemy_7_mark_type =
    uint8_t;
  _enemy_7_mark_type enemy_7_mark;

  // setters for named parameter idiom
  Type & set__enemy_1_mark(
    const uint8_t & _arg)
  {
    this->enemy_1_mark = _arg;
    return *this;
  }
  Type & set__enemy_2_mark(
    const uint8_t & _arg)
  {
    this->enemy_2_mark = _arg;
    return *this;
  }
  Type & set__enemy_3_mark(
    const uint8_t & _arg)
  {
    this->enemy_3_mark = _arg;
    return *this;
  }
  Type & set__enemy_4_mark(
    const uint8_t & _arg)
  {
    this->enemy_4_mark = _arg;
    return *this;
  }
  Type & set__enemy_5_mark(
    const uint8_t & _arg)
  {
    this->enemy_5_mark = _arg;
    return *this;
  }
  Type & set__enemy_7_mark(
    const uint8_t & _arg)
  {
    this->enemy_7_mark = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__EnemyRobotMark
    std::shared_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__EnemyRobotMark
    std::shared_ptr<rm_autonomy_interfaces::msg::EnemyRobotMark_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EnemyRobotMark_ & other) const
  {
    if (this->enemy_1_mark != other.enemy_1_mark) {
      return false;
    }
    if (this->enemy_2_mark != other.enemy_2_mark) {
      return false;
    }
    if (this->enemy_3_mark != other.enemy_3_mark) {
      return false;
    }
    if (this->enemy_4_mark != other.enemy_4_mark) {
      return false;
    }
    if (this->enemy_5_mark != other.enemy_5_mark) {
      return false;
    }
    if (this->enemy_7_mark != other.enemy_7_mark) {
      return false;
    }
    return true;
  }
  bool operator!=(const EnemyRobotMark_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EnemyRobotMark_

// alias to use template instance with default allocator
using EnemyRobotMark =
  rm_autonomy_interfaces::msg::EnemyRobotMark_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ENEMY_ROBOT_MARK__STRUCT_HPP_
