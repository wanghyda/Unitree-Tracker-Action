# Sentry Autonomy

基于决策树的导航决策脚本

参考开源：

https://github.com/BehaviorTree/BehaviorTree.ROS2

https://github.com/sea-bass/turtlebot3_behavior_demos

## 决策树

- rmul_2024: 2024联盟赛决策树

## 自定义Nodes

目前只自定义了Action、Condition和Control

```
.
├── action
│   ├── get_current_location_action_bt_node.hpp //获取底盘在世界坐标系下的位置
│   ├── relocalize_action_bt_node.hpp //使用ICP/BBS进行重定位
│   ├── send_goal_action_bt_node.hpp //前往目标点
│   ├── sub_all_robot_hp_action_bt_node.hpp
│   ├── sub_ally_robot_position_action_bt_node.hpp
│   ├── sub_arena_status_action_bt_node.hpp
│   ├── sub_autoaim_communication_action_bt_node.hpp
│   ├── sub_game_status_action_bt_node.hpp
│   ├── sub_human_intervention_action_bt_node.hpp
│   ├── sub_radar_enemy_position_action_bt_node.hpp
│   └── sub_self_state_action_bt_node.hpp
├── condition
│   ├── enemy_autoaim_detected_condition.hpp //检测到自瞄敌人
│   ├── is_game_start_condition.hpp //对局开始
│   ├── is_outpost_hp_low_condition.hpp //前哨战血量低
│   ├── is_rmul_healing_available_condition.hpp //rmul专用，是否有中心增益点
│   ├── is_self_hp_low_condition.hpp //自身血量低
│   └── under_attack_condition.hpp //被攻击判断
└── control
    ├── pipeline_sequence.hpp
    └── round_robin_node.hpp
```