// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__GameStatus __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__GameStatus __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameStatus_
{
  using Type = GameStatus_<ContainerAllocator>;

  explicit GameStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stage_progress = 0;
      this->stage_remain_time = 0;
    }
  }

  explicit GameStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stage_progress = 0;
      this->stage_remain_time = 0;
    }
  }

  // field types and members
  using _stage_progress_type =
    uint8_t;
  _stage_progress_type stage_progress;
  using _stage_remain_time_type =
    uint16_t;
  _stage_remain_time_type stage_remain_time;

  // setters for named parameter idiom
  Type & set__stage_progress(
    const uint8_t & _arg)
  {
    this->stage_progress = _arg;
    return *this;
  }
  Type & set__stage_remain_time(
    const uint16_t & _arg)
  {
    this->stage_remain_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__GameStatus
    std::shared_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__GameStatus
    std::shared_ptr<rm_autonomy_interfaces::msg::GameStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameStatus_ & other) const
  {
    if (this->stage_progress != other.stage_progress) {
      return false;
    }
    if (this->stage_remain_time != other.stage_remain_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameStatus_

// alias to use template instance with default allocator
using GameStatus =
  rm_autonomy_interfaces::msg::GameStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
