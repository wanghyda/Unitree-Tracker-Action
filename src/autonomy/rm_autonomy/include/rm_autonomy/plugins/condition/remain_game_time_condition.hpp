#ifndef RM_AUTONOMY__PLUGINS__CONDITION__REMAIN_GAME_TIME_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__CONDITION__REMAIN_GAME_TIME_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/game_status.hpp"

namespace rm_autonomy
{

class RemainGameTimeCondition : public BT::SimpleConditionNode
{
public:
  RemainGameTimeCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkGameStatus();

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<rm_autonomy_interfaces::msg::GameStatus>("message"),
      BT::InputPort<int>("time_threshold")};
  }
};
}  // namespace rm_autonomy

#endif  //RM_AUTONOMY__PLUGINS__CONDITION__REMAIN_GAME_TIME_CONDITION_HPP_