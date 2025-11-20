#ifndef RM_AUTONOMY__PLUGINS__ACTION__GET_CURRENT_HEIGHT_BT_NODE
#define RM_AUTONOMY__PLUGINS__ACTION__GET_CURRENT_HEIGHT_BT_NODE

#include "behaviortree_cpp/action_node.h"
#include"rm_autonomy/polygon.hpp"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <behaviortree_cpp/basic_types.h>
namespace rm_autonomy
{
  class GetCurrentHeightAction: public BT::SyncActionNode
  {
public:
    GetCurrentHeightAction(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus tick() override;
    static BT::PortsList providedPorts()
    {
    return {
            BT::InputPort<std::shared_ptr<Polygon>>("slide_area_1"),
            BT::InputPort<std::shared_ptr<Polygon>>("slide_area_2"),
            BT::InputPort<std::shared_ptr<Polygon>>("slide_area_3"),
            BT::InputPort<std::shared_ptr<Polygon>>("slide_area_4"),
          BT::InputPort<geometry_msgs::msg::TransformStamped>("current_location"),
            BT::OutputPort<int>("slide"),
            };
    }

    private:
    rclcpp::Logger logger_{rclcpp::get_logger("get_current_height")};
  };
} // namespace rm_autonomy

#endif