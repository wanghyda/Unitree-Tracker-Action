#pragma once
#include <behaviortree_cpp/bt_factory.h>
#include <rclcpp/rclcpp.hpp>

// v4 注册插件宏
#define CREATE_BT_ROS_NODE_PLUGIN(NodeClass, NodeName)                    \
BT_REGISTER_NODES(factory)                                                \
{                                                                         \
    auto node = rclcpp::Node::make_shared("bt_node_plugin_" #NodeName);   \
    factory.registerNodeType<NodeClass>(#NodeName, node);                 \
}
