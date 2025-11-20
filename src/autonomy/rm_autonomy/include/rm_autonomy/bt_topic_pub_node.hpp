#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <rclcpp/rclcpp.hpp>

namespace BT
{

// 泛型Publisher节点，子类只需要指定消息类型和处理逻辑
template <typename MsgT>
class TopicPubNode : public SyncActionNode
{
public:
  TopicPubNode(const std::string& name,
               const NodeConfiguration& config,
               rclcpp::Node::SharedPtr node,
               const std::string& topic_name,
               rclcpp::QoS qos = rclcpp::SystemDefaultsQoS())
      : SyncActionNode(name, config), node_(node)
  {
    pub_ = node_->create_publisher<MsgT>(topic_name, qos);
  }

  static PortsList providedPorts()
  {
    // 留给子类决定需要哪些输入端口
    return {};
  }

protected:
  // 子类在tick()里可以直接调用 publish()
  void publish(const MsgT& msg)
  {
    pub_->publish(msg);
  }

  rclcpp::Node::SharedPtr node_;
  typename rclcpp::Publisher<MsgT>::SharedPtr pub_;
};

} // namespace BT
