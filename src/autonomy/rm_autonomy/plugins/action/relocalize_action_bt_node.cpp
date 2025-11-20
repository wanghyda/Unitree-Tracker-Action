#include "rm_autonomy/plugins/action/relocalize_action_bt_node.hpp"

namespace rm_autonomy
{

RelocalizeActionBTNode::RelocalizeActionBTNode(
  const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
  node_ = std::make_shared<rclcpp::Node>("relocalize_action_bt_node");
  if (!node_) {
    throw std::runtime_error("Failed to create node 'relocalize_action_bt_node'");
  }
}
BT::NodeStatus RelocalizeActionBTNode::tick()
{
  client_ = node_->create_client<std_srvs::srv::Empty>("relocalize");
  auto request = std::make_shared<std_srvs::srv::Empty::Request>();
  while (!client_->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(logger_, "Interrupted while waiting for the service. Exiting.");
      return BT::NodeStatus::FAILURE;
    }
    RCLCPP_INFO(logger_, "service not available, waiting again...");
  }

  auto result = client_->async_send_request(request);
  if (rclcpp::spin_until_future_complete(node_, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    return BT::NodeStatus::SUCCESS;
  } else {
    return BT::NodeStatus::FAILURE;
  }
}
}
#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::RelocalizeActionBTNode>("RelocalizeActionBTNode");
}