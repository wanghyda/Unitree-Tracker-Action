#include "rm_autonomy/plugins/action/get_current_location_action_bt_node.hpp"
#include <rclcpp/logging.hpp>
namespace rm_autonomy
{
GetCurrentLocationActionBTNode::GetCurrentLocationActionBTNode(
  const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
  node_ = std::make_shared<rclcpp::Node>("get_current_location_action_bt_node");


  tf_buffer_ = std::make_shared<tf2_ros::Buffer>(node_->get_clock(), tf2::durationFromSec(10.0));


  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_, node_, true);

}
BT::NodeStatus GetCurrentLocationActionBTNode::tick()
{
  geometry_msgs::msg::TransformStamped t;
  try { 
    t = tf_buffer_->lookupTransform("map", "base_link", tf2::TimePointZero);
    // RCLCPP_INFO(logger_, "Current location: %f %f %f", t.transform.translation.x, t.transform.translation.y, t.transform.translation.z);
    setOutput("current_location", t);
    return BT::NodeStatus::SUCCESS;
  } catch (const  tf2::TransformException & ex){
    RCLCPP_ERROR(logger_,"Failed to transform base_link to map: %s", ex.what() );
    return BT::NodeStatus::FAILURE;
  }
}
}

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::GetCurrentLocationActionBTNode>("GetCurrentLocationActionBTNode");
}