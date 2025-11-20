// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__SelfState __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__SelfState __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SelfState_
{
  using Type = SelfState_<ContainerAllocator>;

  explicit SelfState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->current_hp = 0;
      this->patrol_rfid = 0;
      this->energy_rfid = 0;
      this->under_attack = 0;
      this->current_ammo = 0;
      this->energy_left = 0;
      this->decision_set = 0;
    }
  }

  explicit SelfState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->current_hp = 0;
      this->patrol_rfid = 0;
      this->energy_rfid = 0;
      this->under_attack = 0;
      this->current_ammo = 0;
      this->energy_left = 0;
      this->decision_set = 0;
    }
  }

  // field types and members
  using _robot_id_type =
    uint8_t;
  _robot_id_type robot_id;
  using _current_hp_type =
    uint16_t;
  _current_hp_type current_hp;
  using _patrol_rfid_type =
    uint8_t;
  _patrol_rfid_type patrol_rfid;
  using _energy_rfid_type =
    uint8_t;
  _energy_rfid_type energy_rfid;
  using _under_attack_type =
    uint8_t;
  _under_attack_type under_attack;
  using _current_ammo_type =
    uint16_t;
  _current_ammo_type current_ammo;
  using _energy_left_type =
    uint16_t;
  _energy_left_type energy_left;
  using _decision_set_type =
    uint8_t;
  _decision_set_type decision_set;

  // setters for named parameter idiom
  Type & set__robot_id(
    const uint8_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__current_hp(
    const uint16_t & _arg)
  {
    this->current_hp = _arg;
    return *this;
  }
  Type & set__patrol_rfid(
    const uint8_t & _arg)
  {
    this->patrol_rfid = _arg;
    return *this;
  }
  Type & set__energy_rfid(
    const uint8_t & _arg)
  {
    this->energy_rfid = _arg;
    return *this;
  }
  Type & set__under_attack(
    const uint8_t & _arg)
  {
    this->under_attack = _arg;
    return *this;
  }
  Type & set__current_ammo(
    const uint16_t & _arg)
  {
    this->current_ammo = _arg;
    return *this;
  }
  Type & set__energy_left(
    const uint16_t & _arg)
  {
    this->energy_left = _arg;
    return *this;
  }
  Type & set__decision_set(
    const uint8_t & _arg)
  {
    this->decision_set = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__SelfState
    std::shared_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__SelfState
    std::shared_ptr<rm_autonomy_interfaces::msg::SelfState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SelfState_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->current_hp != other.current_hp) {
      return false;
    }
    if (this->patrol_rfid != other.patrol_rfid) {
      return false;
    }
    if (this->energy_rfid != other.energy_rfid) {
      return false;
    }
    if (this->under_attack != other.under_attack) {
      return false;
    }
    if (this->current_ammo != other.current_ammo) {
      return false;
    }
    if (this->energy_left != other.energy_left) {
      return false;
    }
    if (this->decision_set != other.decision_set) {
      return false;
    }
    return true;
  }
  bool operator!=(const SelfState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SelfState_

// alias to use template instance with default allocator
using SelfState =
  rm_autonomy_interfaces::msg::SelfState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__STRUCT_HPP_
