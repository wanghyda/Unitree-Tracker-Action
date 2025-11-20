#ifndef RM_AUTONOMY__PLUGINS__ACTION__RELOCALIZE_ACTION_BT_NODE_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__RELOCALIZE_ACTION_BT_NODE_HPP_

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/empty.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

namespace rm_autonomy
{

class RelocalizeActionBTNode: public BT::SyncActionNode
{
public:
  explicit RelocalizeActionBTNode(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus tick() override;

  static BT::PortsList providedPorts()
  {
    return {};
  }
private:
  rclcpp::Client<std_srvs::srv::Empty>::SharedPtr client_;
  std::shared_ptr<rclcpp::Node> node_;
};
} // namespace rm_autonomy

#endif //RM_AUTONOMY__PLUGINS__ACTION__RELOCALIZE_ACTION_BT_NODE_HPP_