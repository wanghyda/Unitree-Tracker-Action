#include "rm_autonomy/plugins/action/sub_fire_trigger_action_bt_node.hpp"
namespace rm_autonomy
{

SubFireTriggerActionBTNode::SubFireTriggerActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::FireTrigger>(name, conf, params)
{
}

BT::NodeStatus SubFireTriggerActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::FireTrigger> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    setOutput("fire_trigger_value", *last_msg); 
  }
  return BT::NodeStatus::SUCCESS;
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubFireTriggerActionBTNode, "SubFireTriggerActionBTNode");


