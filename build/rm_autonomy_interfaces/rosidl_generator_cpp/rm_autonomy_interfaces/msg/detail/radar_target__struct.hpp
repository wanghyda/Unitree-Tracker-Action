// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/RadarTarget.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_TARGET__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_TARGET__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__RadarTarget __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__RadarTarget __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarTarget_
{
  using Type = RadarTarget_<ContainerAllocator>;

  explicit RadarTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_id = 0;
      this->target_map_x = 0.0f;
      this->target_map_y = 0.0f;
    }
  }

  explicit RadarTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_id = 0;
      this->target_map_x = 0.0f;
      this->target_map_y = 0.0f;
    }
  }

  // field types and members
  using _target_id_type =
    uint8_t;
  _target_id_type target_id;
  using _target_map_x_type =
    float;
  _target_map_x_type target_map_x;
  using _target_map_y_type =
    float;
  _target_map_y_type target_map_y;

  // setters for named parameter idiom
  Type & set__target_id(
    const uint8_t & _arg)
  {
    this->target_id = _arg;
    return *this;
  }
  Type & set__target_map_x(
    const float & _arg)
  {
    this->target_map_x = _arg;
    return *this;
  }
  Type & set__target_map_y(
    const float & _arg)
  {
    this->target_map_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__RadarTarget
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__RadarTarget
    std::shared_ptr<rm_autonomy_interfaces::msg::RadarTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarTarget_ & other) const
  {
    if (this->target_id != other.target_id) {
      return false;
    }
    if (this->target_map_x != other.target_map_x) {
      return false;
    }
    if (this->target_map_y != other.target_map_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarTarget_

// alias to use template instance with default allocator
using RadarTarget =
  rm_autonomy_interfaces::msg::RadarTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__RADAR_TARGET__STRUCT_HPP_
