#include "rm_autonomy/plugins/action/sub_human_intervention_action_bt_node.hpp"
// #include "rclcpp/rclcpp.hpp"
namespace rm_autonomy
{

SubHumanInterventionActionBTNode::SubHumanInterventionActionBTNode(
  const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params)
: BT::RosTopicSubNode<rm_autonomy_interfaces::msg::HumanIntervention>(name, conf, params)
{
}

BT::NodeStatus SubHumanInterventionActionBTNode::onTick(
  const std::shared_ptr<rm_autonomy_interfaces::msg::HumanIntervention> & last_msg)
{
  if (last_msg)  // empty if no new message received, since the last tick
  {
    last_dart=last_msg->command_header;
    geometry_msgs::msg::PoseStamped goal;
    goal.pose.position.x = last_msg-> goal_pose_x;
    goal.pose.position.y = last_msg-> goal_pose_y;
    goal.header.stamp = this->node_->get_clock()->now();
    goal.header.frame_id = "map";
    if(last_dart!=65)
    {
      
      setOutput("human_intervention_pose", goal);
      geometry_msgs::msg::TransformStamped current_pose;
      getInput("current_location",current_pose);
      double dx = goal.pose.position.x - current_pose.transform.translation.x;
      double dy = goal.pose.position.y - current_pose.transform.translation.y;
      double dx_last=goal.pose.position.x - last_goal.pose.position.x;
      double dy_last=goal.pose.position.y - last_goal.pose.position.y;

      if(dx_last*dx_last+dy_last*dy_last<0.25)
      {
        RCLCPP_INFO(logger_, "Repeated,Publishing: command_header=%d", 0);
        setOutput("dart_value", 0.0);
        return BT::NodeStatus::SUCCESS;
      }else
      {
        if(dx*dx+dy*dy<0.0025)
        {
          tick_times+=1;
          if(tick_times==200)
          {
            last_goal=goal;
            RCLCPP_INFO(logger_, "Finished,Publishing: command_header=%d", 0);
            setOutput("dart_value", 0.0);
            tick_times=0;
            return BT::NodeStatus::SUCCESS;
          }else{
            RCLCPP_INFO(logger_, "Waiting,Publishing: command_header=%d", last_msg->command_header);
            setOutput("dart_value", last_msg->command_header); 
            return BT::NodeStatus::SUCCESS;
          }
        }else{
          RCLCPP_INFO(logger_, "Not_arrived,Publishing: command_header=%d", last_msg->command_header);
          setOutput("dart_value", last_msg->command_header);
          return BT::NodeStatus::SUCCESS;
        }
      }
 
    }else{
      RCLCPP_INFO(logger_, "Permanant,Publishing: command_header=%d", last_msg->command_header);
      setOutput("dart_value", last_msg->command_header);
      return BT::NodeStatus::SUCCESS;
    }

  }else {
      RCLCPP_INFO(logger_, "Not received,Publishing: command_header=%d", 0);
      setOutput("dart_value", 0.0);
      return BT::NodeStatus::SUCCESS; 
  }
  
}

}  // namespace rm_autonomy

#include "behaviortree_ros2/plugins.hpp"
CreateRosNodePlugin(rm_autonomy::SubHumanInterventionActionBTNode, "SubHumanInterventionActionBTNode");