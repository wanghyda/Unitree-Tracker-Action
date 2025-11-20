// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/SelfState.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/self_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_SelfState_decision_set
{
public:
  explicit Init_SelfState_decision_set(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::SelfState decision_set(::rm_autonomy_interfaces::msg::SelfState::_decision_set_type arg)
  {
    msg_.decision_set = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_energy_left
{
public:
  explicit Init_SelfState_energy_left(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  Init_SelfState_decision_set energy_left(::rm_autonomy_interfaces::msg::SelfState::_energy_left_type arg)
  {
    msg_.energy_left = std::move(arg);
    return Init_SelfState_decision_set(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_current_ammo
{
public:
  explicit Init_SelfState_current_ammo(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  Init_SelfState_energy_left current_ammo(::rm_autonomy_interfaces::msg::SelfState::_current_ammo_type arg)
  {
    msg_.current_ammo = std::move(arg);
    return Init_SelfState_energy_left(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_under_attack
{
public:
  explicit Init_SelfState_under_attack(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  Init_SelfState_current_ammo under_attack(::rm_autonomy_interfaces::msg::SelfState::_under_attack_type arg)
  {
    msg_.under_attack = std::move(arg);
    return Init_SelfState_current_ammo(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_energy_rfid
{
public:
  explicit Init_SelfState_energy_rfid(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  Init_SelfState_under_attack energy_rfid(::rm_autonomy_interfaces::msg::SelfState::_energy_rfid_type arg)
  {
    msg_.energy_rfid = std::move(arg);
    return Init_SelfState_under_attack(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_patrol_rfid
{
public:
  explicit Init_SelfState_patrol_rfid(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  Init_SelfState_energy_rfid patrol_rfid(::rm_autonomy_interfaces::msg::SelfState::_patrol_rfid_type arg)
  {
    msg_.patrol_rfid = std::move(arg);
    return Init_SelfState_energy_rfid(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_current_hp
{
public:
  explicit Init_SelfState_current_hp(::rm_autonomy_interfaces::msg::SelfState & msg)
  : msg_(msg)
  {}
  Init_SelfState_patrol_rfid current_hp(::rm_autonomy_interfaces::msg::SelfState::_current_hp_type arg)
  {
    msg_.current_hp = std::move(arg);
    return Init_SelfState_patrol_rfid(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

class Init_SelfState_robot_id
{
public:
  Init_SelfState_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SelfState_current_hp robot_id(::rm_autonomy_interfaces::msg::SelfState::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_SelfState_current_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::SelfState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::SelfState>()
{
  return rm_autonomy_interfaces::msg::builder::Init_SelfState_robot_id();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__SELF_STATE__BUILDER_HPP_
