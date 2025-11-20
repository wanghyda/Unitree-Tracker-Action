// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/InvincibleTarget.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__InvincibleTarget __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__InvincibleTarget __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InvincibleTarget_
{
  using Type = InvincibleTarget_<ContainerAllocator>;

  explicit InvincibleTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->invincible_target.begin(), this->invincible_target.end(), 0);
    }
  }

  explicit InvincibleTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : invincible_target(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->invincible_target.begin(), this->invincible_target.end(), 0);
    }
  }

  // field types and members
  using _invincible_target_type =
    std::array<uint8_t, 6>;
  _invincible_target_type invincible_target;

  // setters for named parameter idiom
  Type & set__invincible_target(
    const std::array<uint8_t, 6> & _arg)
  {
    this->invincible_target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__InvincibleTarget
    std::shared_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__InvincibleTarget
    std::shared_ptr<rm_autonomy_interfaces::msg::InvincibleTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InvincibleTarget_ & other) const
  {
    if (this->invincible_target != other.invincible_target) {
      return false;
    }
    return true;
  }
  bool operator!=(const InvincibleTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InvincibleTarget_

// alias to use template instance with default allocator
using InvincibleTarget =
  rm_autonomy_interfaces::msg::InvincibleTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__INVINCIBLE_TARGET__STRUCT_HPP_
