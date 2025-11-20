#include "rm_autonomy/plugins/action/get_current_height_action_bt_node.hpp"
#include "rm_autonomy/polygon.hpp"
#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/basic_types.h>
#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <memory>
#include <rclcpp/logging.hpp>

namespace rm_autonomy 
{
GetCurrentHeightAction::GetCurrentHeightAction(
  const std::string & name, const BT::NodeConfig & config)
:BT::SyncActionNode(name,config)
{    
}

BT::NodeStatus GetCurrentHeightAction::tick(){
    geometry_msgs::msg::TransformStamped current_pose;
    getInput<geometry_msgs::msg::TransformStamped>("current_location",current_pose);
    std::shared_ptr<Polygon> slide_area_1,slide_area_2,slide_area_3,slide_area_4;
    getInput<std::shared_ptr<Polygon>>("slide_area_4",slide_area_4);
    getInput<std::shared_ptr<Polygon>>("slide_area_2",slide_area_2);
    getInput<std::shared_ptr<Polygon>>("slide_area_3",slide_area_3);
    getInput<std::shared_ptr<Polygon>>("slide_area_1",slide_area_1);
    bool is_in_region;
    int slide;
    if(!slide_area_1 && !slide_area_2 && !slide_area_3 && !slide_area_4)
    {
      RCLCPP_ERROR(logger_,"No slide area");
      return BT::NodeStatus::FAILURE;
    }
    is_in_region=(slide_area_1->contains(current_pose)||
                  slide_area_2->contains(current_pose)||
                  slide_area_3->contains(current_pose) ||
                  slide_area_4->contains(current_pose));
    if (is_in_region) {
        slide=1;
    }else{
        slide=0;
    }
    setOutput("slide", slide);
    RCLCPP_INFO(logger_,"slide=%d",slide);
    return BT::NodeStatus::SUCCESS;
}

}

#include "behaviortree_cpp/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_autonomy::GetCurrentHeightAction>("GetCurrentHeightAction");
}