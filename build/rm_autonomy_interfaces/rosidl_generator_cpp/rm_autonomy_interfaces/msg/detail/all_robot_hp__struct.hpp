// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_autonomy_interfaces:msg/AllRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__STRUCT_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rm_autonomy_interfaces__msg__AllRobotHP __attribute__((deprecated))
#else
# define DEPRECATED__rm_autonomy_interfaces__msg__AllRobotHP __declspec(deprecated)
#endif

namespace rm_autonomy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AllRobotHP_
{
  using Type = AllRobotHP_<ContainerAllocator>;

  explicit AllRobotHP_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red_1_hp = 0;
      this->red_2_hp = 0;
      this->red_3_hp = 0;
      this->red_4_hp = 0;
      this->red_5_hp = 0;
      this->red_7_hp = 0;
      this->red_outpost_hp = 0;
      this->red_base_hp = 0;
      this->blue_1_hp = 0;
      this->blue_2_hp = 0;
      this->blue_3_hp = 0;
      this->blue_4_hp = 0;
      this->blue_5_hp = 0;
      this->blue_7_hp = 0;
      this->blue_outpost_hp = 0;
      this->blue_base_hp = 0;
    }
  }

  explicit AllRobotHP_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red_1_hp = 0;
      this->red_2_hp = 0;
      this->red_3_hp = 0;
      this->red_4_hp = 0;
      this->red_5_hp = 0;
      this->red_7_hp = 0;
      this->red_outpost_hp = 0;
      this->red_base_hp = 0;
      this->blue_1_hp = 0;
      this->blue_2_hp = 0;
      this->blue_3_hp = 0;
      this->blue_4_hp = 0;
      this->blue_5_hp = 0;
      this->blue_7_hp = 0;
      this->blue_outpost_hp = 0;
      this->blue_base_hp = 0;
    }
  }

  // field types and members
  using _red_1_hp_type =
    uint16_t;
  _red_1_hp_type red_1_hp;
  using _red_2_hp_type =
    uint16_t;
  _red_2_hp_type red_2_hp;
  using _red_3_hp_type =
    uint16_t;
  _red_3_hp_type red_3_hp;
  using _red_4_hp_type =
    uint16_t;
  _red_4_hp_type red_4_hp;
  using _red_5_hp_type =
    uint16_t;
  _red_5_hp_type red_5_hp;
  using _red_7_hp_type =
    uint16_t;
  _red_7_hp_type red_7_hp;
  using _red_outpost_hp_type =
    uint16_t;
  _red_outpost_hp_type red_outpost_hp;
  using _red_base_hp_type =
    uint16_t;
  _red_base_hp_type red_base_hp;
  using _blue_1_hp_type =
    uint16_t;
  _blue_1_hp_type blue_1_hp;
  using _blue_2_hp_type =
    uint16_t;
  _blue_2_hp_type blue_2_hp;
  using _blue_3_hp_type =
    uint16_t;
  _blue_3_hp_type blue_3_hp;
  using _blue_4_hp_type =
    uint16_t;
  _blue_4_hp_type blue_4_hp;
  using _blue_5_hp_type =
    uint16_t;
  _blue_5_hp_type blue_5_hp;
  using _blue_7_hp_type =
    uint16_t;
  _blue_7_hp_type blue_7_hp;
  using _blue_outpost_hp_type =
    uint16_t;
  _blue_outpost_hp_type blue_outpost_hp;
  using _blue_base_hp_type =
    uint16_t;
  _blue_base_hp_type blue_base_hp;

  // setters for named parameter idiom
  Type & set__red_1_hp(
    const uint16_t & _arg)
  {
    this->red_1_hp = _arg;
    return *this;
  }
  Type & set__red_2_hp(
    const uint16_t & _arg)
  {
    this->red_2_hp = _arg;
    return *this;
  }
  Type & set__red_3_hp(
    const uint16_t & _arg)
  {
    this->red_3_hp = _arg;
    return *this;
  }
  Type & set__red_4_hp(
    const uint16_t & _arg)
  {
    this->red_4_hp = _arg;
    return *this;
  }
  Type & set__red_5_hp(
    const uint16_t & _arg)
  {
    this->red_5_hp = _arg;
    return *this;
  }
  Type & set__red_7_hp(
    const uint16_t & _arg)
  {
    this->red_7_hp = _arg;
    return *this;
  }
  Type & set__red_outpost_hp(
    const uint16_t & _arg)
  {
    this->red_outpost_hp = _arg;
    return *this;
  }
  Type & set__red_base_hp(
    const uint16_t & _arg)
  {
    this->red_base_hp = _arg;
    return *this;
  }
  Type & set__blue_1_hp(
    const uint16_t & _arg)
  {
    this->blue_1_hp = _arg;
    return *this;
  }
  Type & set__blue_2_hp(
    const uint16_t & _arg)
  {
    this->blue_2_hp = _arg;
    return *this;
  }
  Type & set__blue_3_hp(
    const uint16_t & _arg)
  {
    this->blue_3_hp = _arg;
    return *this;
  }
  Type & set__blue_4_hp(
    const uint16_t & _arg)
  {
    this->blue_4_hp = _arg;
    return *this;
  }
  Type & set__blue_5_hp(
    const uint16_t & _arg)
  {
    this->blue_5_hp = _arg;
    return *this;
  }
  Type & set__blue_7_hp(
    const uint16_t & _arg)
  {
    this->blue_7_hp = _arg;
    return *this;
  }
  Type & set__blue_outpost_hp(
    const uint16_t & _arg)
  {
    this->blue_outpost_hp = _arg;
    return *this;
  }
  Type & set__blue_base_hp(
    const uint16_t & _arg)
  {
    this->blue_base_hp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_autonomy_interfaces__msg__AllRobotHP
    std::shared_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_autonomy_interfaces__msg__AllRobotHP
    std::shared_ptr<rm_autonomy_interfaces::msg::AllRobotHP_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AllRobotHP_ & other) const
  {
    if (this->red_1_hp != other.red_1_hp) {
      return false;
    }
    if (this->red_2_hp != other.red_2_hp) {
      return false;
    }
    if (this->red_3_hp != other.red_3_hp) {
      return false;
    }
    if (this->red_4_hp != other.red_4_hp) {
      return false;
    }
    if (this->red_5_hp != other.red_5_hp) {
      return false;
    }
    if (this->red_7_hp != other.red_7_hp) {
      return false;
    }
    if (this->red_outpost_hp != other.red_outpost_hp) {
      return false;
    }
    if (this->red_base_hp != other.red_base_hp) {
      return false;
    }
    if (this->blue_1_hp != other.blue_1_hp) {
      return false;
    }
    if (this->blue_2_hp != other.blue_2_hp) {
      return false;
    }
    if (this->blue_3_hp != other.blue_3_hp) {
      return false;
    }
    if (this->blue_4_hp != other.blue_4_hp) {
      return false;
    }
    if (this->blue_5_hp != other.blue_5_hp) {
      return false;
    }
    if (this->blue_7_hp != other.blue_7_hp) {
      return false;
    }
    if (this->blue_outpost_hp != other.blue_outpost_hp) {
      return false;
    }
    if (this->blue_base_hp != other.blue_base_hp) {
      return false;
    }
    return true;
  }
  bool operator!=(const AllRobotHP_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AllRobotHP_

// alias to use template instance with default allocator
using AllRobotHP =
  rm_autonomy_interfaces::msg::AllRobotHP_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__STRUCT_HPP_
