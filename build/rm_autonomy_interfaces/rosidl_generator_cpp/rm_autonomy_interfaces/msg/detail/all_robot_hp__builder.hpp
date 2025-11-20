// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_autonomy_interfaces:msg/AllRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__BUILDER_HPP_
#define RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__BUILDER_HPP_

#include "rm_autonomy_interfaces/msg/detail/all_robot_hp__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rm_autonomy_interfaces
{

namespace msg
{

namespace builder
{

class Init_AllRobotHP_blue_base_hp
{
public:
  explicit Init_AllRobotHP_blue_base_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  ::rm_autonomy_interfaces::msg::AllRobotHP blue_base_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_base_hp_type arg)
  {
    msg_.blue_base_hp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_outpost_hp
{
public:
  explicit Init_AllRobotHP_blue_outpost_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_base_hp blue_outpost_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_outpost_hp_type arg)
  {
    msg_.blue_outpost_hp = std::move(arg);
    return Init_AllRobotHP_blue_base_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_7_hp
{
public:
  explicit Init_AllRobotHP_blue_7_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_outpost_hp blue_7_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_7_hp_type arg)
  {
    msg_.blue_7_hp = std::move(arg);
    return Init_AllRobotHP_blue_outpost_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_5_hp
{
public:
  explicit Init_AllRobotHP_blue_5_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_7_hp blue_5_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_5_hp_type arg)
  {
    msg_.blue_5_hp = std::move(arg);
    return Init_AllRobotHP_blue_7_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_4_hp
{
public:
  explicit Init_AllRobotHP_blue_4_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_5_hp blue_4_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_4_hp_type arg)
  {
    msg_.blue_4_hp = std::move(arg);
    return Init_AllRobotHP_blue_5_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_3_hp
{
public:
  explicit Init_AllRobotHP_blue_3_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_4_hp blue_3_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_3_hp_type arg)
  {
    msg_.blue_3_hp = std::move(arg);
    return Init_AllRobotHP_blue_4_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_2_hp
{
public:
  explicit Init_AllRobotHP_blue_2_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_3_hp blue_2_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_2_hp_type arg)
  {
    msg_.blue_2_hp = std::move(arg);
    return Init_AllRobotHP_blue_3_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_1_hp
{
public:
  explicit Init_AllRobotHP_blue_1_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_2_hp blue_1_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_blue_1_hp_type arg)
  {
    msg_.blue_1_hp = std::move(arg);
    return Init_AllRobotHP_blue_2_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_base_hp
{
public:
  explicit Init_AllRobotHP_red_base_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_1_hp red_base_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_base_hp_type arg)
  {
    msg_.red_base_hp = std::move(arg);
    return Init_AllRobotHP_blue_1_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_outpost_hp
{
public:
  explicit Init_AllRobotHP_red_outpost_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_base_hp red_outpost_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_outpost_hp_type arg)
  {
    msg_.red_outpost_hp = std::move(arg);
    return Init_AllRobotHP_red_base_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_7_hp
{
public:
  explicit Init_AllRobotHP_red_7_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_outpost_hp red_7_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_7_hp_type arg)
  {
    msg_.red_7_hp = std::move(arg);
    return Init_AllRobotHP_red_outpost_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_5_hp
{
public:
  explicit Init_AllRobotHP_red_5_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_7_hp red_5_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_5_hp_type arg)
  {
    msg_.red_5_hp = std::move(arg);
    return Init_AllRobotHP_red_7_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_4_hp
{
public:
  explicit Init_AllRobotHP_red_4_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_5_hp red_4_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_4_hp_type arg)
  {
    msg_.red_4_hp = std::move(arg);
    return Init_AllRobotHP_red_5_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_3_hp
{
public:
  explicit Init_AllRobotHP_red_3_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_4_hp red_3_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_3_hp_type arg)
  {
    msg_.red_3_hp = std::move(arg);
    return Init_AllRobotHP_red_4_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_2_hp
{
public:
  explicit Init_AllRobotHP_red_2_hp(::rm_autonomy_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_3_hp red_2_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_2_hp_type arg)
  {
    msg_.red_2_hp = std::move(arg);
    return Init_AllRobotHP_red_3_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_1_hp
{
public:
  Init_AllRobotHP_red_1_hp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AllRobotHP_red_2_hp red_1_hp(::rm_autonomy_interfaces::msg::AllRobotHP::_red_1_hp_type arg)
  {
    msg_.red_1_hp = std::move(arg);
    return Init_AllRobotHP_red_2_hp(msg_);
  }

private:
  ::rm_autonomy_interfaces::msg::AllRobotHP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_autonomy_interfaces::msg::AllRobotHP>()
{
  return rm_autonomy_interfaces::msg::builder::Init_AllRobotHP_red_1_hp();
}

}  // namespace rm_autonomy_interfaces

#endif  // RM_AUTONOMY_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__BUILDER_HPP_
