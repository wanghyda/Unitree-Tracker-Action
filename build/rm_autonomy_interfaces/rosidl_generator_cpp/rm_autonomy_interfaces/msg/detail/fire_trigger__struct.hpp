// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/FireTrigger.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__FireTrigger __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__FireTrigger __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FireTrigger_
{
  using Type = FireTrigger_<ContainerAllocator>;

  explicit FireTrigger_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fire_trigger = 0;
    }
  }

  explicit FireTrigger_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fire_trigger = 0;
    }
  }

  // field types and members
  using _fire_trigger_type =
    uint8_t;
  _fire_trigger_type fire_trigger;

  // setters for named parameter idiom
  Type & set__fire_trigger(
    const uint8_t & _arg)
  {
    this->fire_trigger = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__FireTrigger
    std::shared_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__FireTrigger
    std::shared_ptr<rm_autonomy_interfaces::msg::FireTrigger_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FireTrigger_ & other) const
  {
    if (this->fire_trigger != other.fire_trigger) {
      return false;
    }
    return true;
  }
  bool operator!=(const FireTrigger_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FireTrigger_

// alias to use template instance with default allocator
using FireTrigger =
  rm_autonomy_interfaces::msg::FireTrigger_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__FIRE_TRIGGER__STRUCT_HPP_
