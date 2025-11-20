#ifndef RM_AUTONOMY__PLUGINS__ACTION__IS_GAME_START_CONDITION_HPP_
#define RM_AUTONOMY__PLUGINS__ACTION__IS_GAME_START_CONDITION_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "rm_autonomy_interfaces/msg/game_status.hpp"

namespace rm_autonomy
{
class IsGameStartCondition : public BT::SimpleConditionNode
{
public:
  IsGameStartCondition(const std::string & name, const BT::NodeConfig & config);

  BT::NodeStatus checkGameStart();

  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<rm_autonomy_interfaces::msg::GameStatus>("message")};
  }
};
}  // namespace rm_autonomy

#endif  // RM_AUTONOMY__PLUGINS__ACTION__IS_GAME_START_CONDITION_HPP_