// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/HumanIntervention.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__HumanIntervention __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__HumanIntervention __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HumanIntervention_
{
  using Type = HumanIntervention_<ContainerAllocator>;

  explicit HumanIntervention_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_header = 0;
      this->goal_pose_x = 0.0f;
      this->goal_pose_y = 0.0f;
    }
  }

  explicit HumanIntervention_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_header = 0;
      this->goal_pose_x = 0.0f;
      this->goal_pose_y = 0.0f;
    }
  }

  // field types and members
  using _command_header_type =
    uint8_t;
  _command_header_type command_header;
  using _goal_pose_x_type =
    float;
  _goal_pose_x_type goal_pose_x;
  using _goal_pose_y_type =
    float;
  _goal_pose_y_type goal_pose_y;

  // setters for named parameter idiom
  Type & set__command_header(
    const uint8_t & _arg)
  {
    this->command_header = _arg;
    return *this;
  }
  Type & set__goal_pose_x(
    const float & _arg)
  {
    this->goal_pose_x = _arg;
    return *this;
  }
  Type & set__goal_pose_y(
    const float & _arg)
  {
    this->goal_pose_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__HumanIntervention
    std::shared_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__HumanIntervention
    std::shared_ptr<rm_autonomy_interfaces::msg::HumanIntervention_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HumanIntervention_ & other) const
  {
    if (this->command_header != other.command_header) {
      return false;
    }
    if (this->goal_pose_x != other.goal_pose_x) {
      return false;
    }
    if (this->goal_pose_y != other.goal_pose_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const HumanIntervention_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HumanIntervention_

// alias to use template instance with default allocator
using HumanIntervention =
  rm_autonomy_interfaces::msg::HumanIntervention_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__HUMAN_INTERVENTION__STRUCT_HPP_
