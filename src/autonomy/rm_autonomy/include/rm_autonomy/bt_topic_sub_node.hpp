#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <rclcpp/rclcpp.hpp>

namespace BT
{

// 泛型Subscriber节点，子类只需要指定消息类型和处理逻辑
template <typename MsgT>
class TopicSubNode : public ConditionNode
{
public:
  TopicSubNode(const std::string& name,
               const NodeConfiguration& config,
               rclcpp::Node::SharedPtr node,
               const std::string& topic_name,
               rclcpp::QoS qos = rclcpp::SystemDefaultsQoS())
      : ConditionNode(name, config), node_(node)
  {
    sub_ = node_->create_subscription<MsgT>(
        topic_name, qos,
        [this](typename MsgT::SharedPtr msg)
        {
          last_msg_ = *msg;
          got_msg_ = true;
        });
  }

  static PortsList providedPorts()
  {
    // 留给子类决定输出哪些端口
    return {};
  }

protected:
  // 子类可在tick()里调用 getLastMsg()
  bool hasMsg() const { return got_msg_; }

  MsgT getLastMsg()
  {
    got_msg_ = false;  // 消费一次
    return last_msg_;
  }

  rclcpp::Node::SharedPtr node_;
  typename rclcpp::Subscription<MsgT>::SharedPtr sub_;
  MsgT last_msg_;
  bool got_msg_ = false;
};

} // namespace BT
