// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/ArenaStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__ArenaStatus __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__ArenaStatus __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArenaStatus_
{
  using Type = ArenaStatus_<ContainerAllocator>;

  explicit ArenaStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->healing_front = 0;
      this->healing_inner = 0;
      this->rmul_healing = 0;
      this->energy_occupy_status = 0;
      this->energy_small_status = 0;
      this->energy_big_status = 0;
      this->ring_highground_status = 0;
      this->trapezoid_highground_status = 0;
      this->base_shield_percentage = 0;
      this->rump_central_buff_status = 0;
    }
  }

  explicit ArenaStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->healing_front = 0;
      this->healing_inner = 0;
      this->rmul_healing = 0;
      this->energy_occupy_status = 0;
      this->energy_small_status = 0;
      this->energy_big_status = 0;
      this->ring_highground_status = 0;
      this->trapezoid_highground_status = 0;
      this->base_shield_percentage = 0;
      this->rump_central_buff_status = 0;
    }
  }

  // field types and members
  using _healing_front_type =
    uint8_t;
  _healing_front_type healing_front;
  using _healing_inner_type =
    uint8_t;
  _healing_inner_type healing_inner;
  using _rmul_healing_type =
    uint8_t;
  _rmul_healing_type rmul_healing;
  using _energy_occupy_status_type =
    uint8_t;
  _energy_occupy_status_type energy_occupy_status;
  using _energy_small_status_type =
    uint8_t;
  _energy_small_status_type energy_small_status;
  using _energy_big_status_type =
    uint8_t;
  _energy_big_status_type energy_big_status;
  using _ring_highground_status_type =
    uint8_t;
  _ring_highground_status_type ring_highground_status;
  using _trapezoid_highground_status_type =
    uint8_t;
  _trapezoid_highground_status_type trapezoid_highground_status;
  using _base_shield_percentage_type =
    uint8_t;
  _base_shield_percentage_type base_shield_percentage;
  using _rump_central_buff_status_type =
    uint8_t;
  _rump_central_buff_status_type rump_central_buff_status;

  // setters for named parameter idiom
  Type & set__healing_front(
    const uint8_t & _arg)
  {
    this->healing_front = _arg;
    return *this;
  }
  Type & set__healing_inner(
    const uint8_t & _arg)
  {
    this->healing_inner = _arg;
    return *this;
  }
  Type & set__rmul_healing(
    const uint8_t & _arg)
  {
    this->rmul_healing = _arg;
    return *this;
  }
  Type & set__energy_occupy_status(
    const uint8_t & _arg)
  {
    this->energy_occupy_status = _arg;
    return *this;
  }
  Type & set__energy_small_status(
    const uint8_t & _arg)
  {
    this->energy_small_status = _arg;
    return *this;
  }
  Type & set__energy_big_status(
    const uint8_t & _arg)
  {
    this->energy_big_status = _arg;
    return *this;
  }
  Type & set__ring_highground_status(
    const uint8_t & _arg)
  {
    this->ring_highground_status = _arg;
    return *this;
  }
  Type & set__trapezoid_highground_status(
    const uint8_t & _arg)
  {
    this->trapezoid_highground_status = _arg;
    return *this;
  }
  Type & set__base_shield_percentage(
    const uint8_t & _arg)
  {
    this->base_shield_percentage = _arg;
    return *this;
  }
  Type & set__rump_central_buff_status(
    const uint8_t & _arg)
  {
    this->rump_central_buff_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__ArenaStatus
    std::shared_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__ArenaStatus
    std::shared_ptr<rm_autonomy_interfaces::msg::ArenaStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArenaStatus_ & other) const
  {
    if (this->healing_front != other.healing_front) {
      return false;
    }
    if (this->healing_inner != other.healing_inner) {
      return false;
    }
    if (this->rmul_healing != other.rmul_healing) {
      return false;
    }
    if (this->energy_occupy_status != other.energy_occupy_status) {
      return false;
    }
    if (this->energy_small_status != other.energy_small_status) {
      return false;
    }
    if (this->energy_big_status != other.energy_big_status) {
      return false;
    }
    if (this->ring_highground_status != other.ring_highground_status) {
      return false;
    }
    if (this->trapezoid_highground_status != other.trapezoid_highground_status) {
      return false;
    }
    if (this->base_shield_percentage != other.base_shield_percentage) {
      return false;
    }
    if (this->rump_central_buff_status != other.rump_central_buff_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArenaStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArenaStatus_

// alias to use template instance with default allocator
using ArenaStatus =
  rm_autonomy_interfaces::msg::ArenaStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ARENA_STATUS__STRUCT_HPP_
