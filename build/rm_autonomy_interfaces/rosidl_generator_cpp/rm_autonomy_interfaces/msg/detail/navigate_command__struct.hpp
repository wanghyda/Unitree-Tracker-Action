// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/NavigateCommand.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__NavigateCommand __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__NavigateCommand __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavigateCommand_
{
  using Type = NavigateCommand_<ContainerAllocator>;

  explicit NavigateCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->spin_speed = 0.0f;
      this->scap_state = false;
      this->align_chassis_big_yaw = false;
    }
  }

  explicit NavigateCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->spin_speed = 0.0f;
      this->scap_state = false;
      this->align_chassis_big_yaw = false;
    }
  }

  // field types and members
  using _spin_speed_type =
    float;
  _spin_speed_type spin_speed;
  using _scap_state_type =
    bool;
  _scap_state_type scap_state;
  using _align_chassis_big_yaw_type =
    bool;
  _align_chassis_big_yaw_type align_chassis_big_yaw;

  // setters for named parameter idiom
  Type & set__spin_speed(
    const float & _arg)
  {
    this->spin_speed = _arg;
    return *this;
  }
  Type & set__scap_state(
    const bool & _arg)
  {
    this->scap_state = _arg;
    return *this;
  }
  Type & set__align_chassis_big_yaw(
    const bool & _arg)
  {
    this->align_chassis_big_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__NavigateCommand
    std::shared_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__NavigateCommand
    std::shared_ptr<rm_autonomy_interfaces::msg::NavigateCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigateCommand_ & other) const
  {
    if (this->spin_speed != other.spin_speed) {
      return false;
    }
    if (this->scap_state != other.scap_state) {
      return false;
    }
    if (this->align_chassis_big_yaw != other.align_chassis_big_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigateCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigateCommand_

// alias to use template instance with default allocator
using NavigateCommand =
  rm_autonomy_interfaces::msg::NavigateCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__NAVIGATE_COMMAND__STRUCT_HPP_
