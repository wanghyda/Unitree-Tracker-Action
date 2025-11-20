// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/OmniSensing.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__OmniSensing __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__OmniSensing __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OmniSensing_
{
  using Type = OmniSensing_<ContainerAllocator>;

  explicit OmniSensing_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_yaw = 0.0f;
      this->target_pitch = 0.0f;
    }
  }

  explicit OmniSensing_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_yaw = 0.0f;
      this->target_pitch = 0.0f;
    }
  }

  // field types and members
  using _target_yaw_type =
    float;
  _target_yaw_type target_yaw;
  using _target_pitch_type =
    float;
  _target_pitch_type target_pitch;

  // setters for named parameter idiom
  Type & set__target_yaw(
    const float & _arg)
  {
    this->target_yaw = _arg;
    return *this;
  }
  Type & set__target_pitch(
    const float & _arg)
  {
    this->target_pitch = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__OmniSensing
    std::shared_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__OmniSensing
    std::shared_ptr<rm_autonomy_interfaces::msg::OmniSensing_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OmniSensing_ & other) const
  {
    if (this->target_yaw != other.target_yaw) {
      return false;
    }
    if (this->target_pitch != other.target_pitch) {
      return false;
    }
    return true;
  }
  bool operator!=(const OmniSensing_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OmniSensing_

// alias to use template instance with default allocator
using OmniSensing =
  rm_autonomy_interfaces::msg::OmniSensing_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__OMNI_SENSING__STRUCT_HPP_
