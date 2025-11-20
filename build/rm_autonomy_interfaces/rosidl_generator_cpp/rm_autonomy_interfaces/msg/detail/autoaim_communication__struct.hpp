// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/AutoaimCommunication.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__AutoaimCommunication __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__AutoaimCommunication __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AutoaimCommunication_
{
  using Type = AutoaimCommunication_<ContainerAllocator>;

  explicit AutoaimCommunication_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->has_target = 0;
      this->target_id = 0;
      this->distance = 0.0f;
    }
  }

  explicit AutoaimCommunication_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->has_target = 0;
      this->target_id = 0;
      this->distance = 0.0f;
    }
  }

  // field types and members
  using _has_target_type =
    uint8_t;
  _has_target_type has_target;
  using _target_id_type =
    uint8_t;
  _target_id_type target_id;
  using _distance_type =
    float;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__has_target(
    const uint8_t & _arg)
  {
    this->has_target = _arg;
    return *this;
  }
  Type & set__target_id(
    const uint8_t & _arg)
  {
    this->target_id = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__AutoaimCommunication
    std::shared_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__AutoaimCommunication
    std::shared_ptr<rm_autonomy_interfaces::msg::AutoaimCommunication_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AutoaimCommunication_ & other) const
  {
    if (this->has_target != other.has_target) {
      return false;
    }
    if (this->target_id != other.target_id) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const AutoaimCommunication_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AutoaimCommunication_

// alias to use template instance with default allocator
using AutoaimCommunication =
  rm_autonomy_interfaces::msg::AutoaimCommunication_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__AUTOAIM_COMMUNICATION__STRUCT_HPP_
