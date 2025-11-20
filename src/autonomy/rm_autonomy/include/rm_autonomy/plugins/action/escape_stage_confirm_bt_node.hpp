#ifndef RM_AUTONOMY__PLUGINS__ACTION__ESCAPE_STAGE_CONFIRM_BT_NODE
#define RM_AUTONOMY__PLUGINS__ACTION__ESCAPE_STAGE_CONFIRM_BT_NODE

#include "behaviortree_cpp/action_node.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <behaviortree_cpp/basic_types.h>
namespace rm_autonomy
{
  class EscapeStageConfirmAs: public BT::StatefulActionNode
  {
public:
    EscapeStageConfirmAs(const std::string & name, const BT::NodeConfig & config);
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;
    static BT::PortsList providedPorts()
    {
    return {
            BT::InputPort<bool>("escape_stage")};
    }

    private:
    bool escape_confirm;
    rclcpp::Logger logger_{rclcpp::get_logger("escape_confirm")};
  };
} // namespace rm_autonomy

#endif