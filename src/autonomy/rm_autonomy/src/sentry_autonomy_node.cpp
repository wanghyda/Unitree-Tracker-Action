#include "rm_autonomy/sentry_autonomy_node.hpp"
#include "rm_autonomy/polygon.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ament_index_cpp/get_package_share_directory.hpp"
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/json_export.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "behaviortree_cpp/utils/shared_library.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rclcpp/rclcpp.hpp"

const std::string tree_path =
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/rmuc_2024.xml";

    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/rmuc_2024_dead.xml";

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/rmuc_2025_blue.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/rmuc_2025_red.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/rmul_2025_test.xml";

    //=============================================================TESTING================================================
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/aatest_sub_info.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/atest_pub_navigate_command.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_relocate.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_send_goal_check.xml";
    ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_chase.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_locate.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_two_point.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_spin.xml";
    // ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/btest_get_height.xml";





// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/test.xml";
//  ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/dtest_defence_behavior.xml";
//  ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/etest_heal.xml";
//  ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/ftest_human_intervention.xml";
//  ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/gtest_pub_navigate_command.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/htest_attack_outpost.xml";
//  ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/itest_pub_navigate_command.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/jtest_reactive.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/ktest_omnisensing.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/ltest_attack_enemy.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/mtest_under_attack.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/ntest_self_ammo_low.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/otest_invincible_enemy.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/unit_test/ptest_chase_communication.xml";

// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/system_test/attack/test_attack.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/system_test/defence/test_defence.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/system_test/dead/dead_120.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/system_test/patrol/120_patrol.xml";
// ament_index_cpp::get_package_share_directory("rm_autonomy") + "/bt_xml/system_test/patrol/partrol.xml";

geometry_msgs::msg::PoseStamped parsePose(const std::string& pose_str) {
    geometry_msgs::msg::PoseStamped pose;
    std::istringstream ss(pose_str);
    std::string token;

    std::getline(ss, token, ';');
    pose.pose.position.x = std::stod(token);
    std::getline(ss, token, ';');
    pose.pose.position.y = std::stod(token);
    std::getline(ss, token, ';');
    pose.pose.position.z = std::stod(token);

    std::getline(ss, token, ';');
    pose.pose.orientation.x = std::stod(token);
    std::getline(ss, token, ';');
    pose.pose.orientation.y = std::stod(token);
    std::getline(ss, token, ';');
    pose.pose.orientation.z = std::stod(token);
    std::getline(ss, token, ';');
    pose.pose.orientation.w = std::stod(token);

    return pose;
}






int main(int argc, char** argv) {
    std::cout << "Start Sentry Autonomy" << '\n';

    rclcpp::init(argc, argv);
    BT::BehaviorTreeFactory factory;

    //register nav2 node







  const std::vector<std::string> bt_plugin_libs = {

    "get_current_location_action_bt_node",
    "send_goal_action_bt_node",
    "pub_chasing_position_btnode_action"
  };
    // clang-format on


    for(const auto& p : bt_plugin_libs) {
        factory.registerFromPlugin(BT::SharedLibrary::getOSName(p));
    }

    std::unordered_map<std::string, std::string> target_points = {
        { "red_base_left","3.77;7.28;0;    0;0;0;1"},
        { "red_base_right", "3.81;8.09;0;    0;0;0;1" },
        { "red_home", "1.54;2.98;0;   0;0;0;1" },
        { "red_defend_1", "9.05;9.65;0;  0;0;0;1" },
        {"red_defend_2", "10.8;12.9;0;  0;0;0;1"},
        {"red_patrol_1", "12.2;11.2;0;  0;0;0;1"},
        {"red_patrol_2", "11.0;6.26;0;  0;0;0;1"},
        {"red_outpost", "12.2;5.41;0;  0;0;0;1"},
        {"red_castle", "6.54;7.64;0;  0;0;0;1"},
        {"pre_red_outpost","16.3;7.17;0;  0;0;0;1"},

        { "blue_base_left", "24.2;8.0;0;    0;0;0;1"},
        { "blue_base_right", "24.2;7.32;0;    0;0;0;1" },
        { "blue_home", "26.5;12.5;0;   0;0;0;1" },
        { "blue_defend_1", "19.0;4.38;0;  0;0;0;1" },
        {"blue_defend_2", "21.9;5.79;0;  0;0;0;1"},
        {"blue_patrol_1", "11.1;7.28;0;  0;0;0;1"},
        {"blue_patrol_2", "8.75;1.07;0;  0;0;0;1"},
        {"blue_outpost", "15.5;9.9;0;  0;0;0;1"},
        {"blue_castle", "21.5;7.91;0;  0;0;0;1"},



        // the following points are in 120 for testing purpose
        { "upper_left", "12.5; 8.1; 0; 0;0;0;1" },  // 大符前
        {"center_luckin", "1.73;-7.11;0;  0;0;0;1"},
        { "outpost_test", "10.8;-0.75;0; 0;0;0;1" },
        { "heal", "6.2;7.5;0; 0;0;0;1" },
        { "bottom_center", "5.9;7.17;0; 0;0;0;1" },
        { "base_left", "6.01;4.25;0;  0;0;0;1" },
        { "patrol1", "-4.12;1.27;0;  0;0;0;1" },
        { "patrol2", "-33.772;15.853;0;    0;0;0;1" },
        {"home_test","-2.6;0;0;    0;0;0;1"},
        {"center_6f","6.61;4.07;0;     0;0;0;1"},
        {"outpost_6f","8.31;4.44;0    0;0;0;1"},
        // { "enemy_patrol_right",    "6.15;4.67;0; 0;0;0;1"},
        // { "patrol_center","6.15;6.02;0;   0;0;0;1"},
    };

    std::unordered_map<std::string,std::vector<double>> region =
    {
        {"red_slide",{3.64,3.37/*左上角*/,8.2,3.49/*右上角*/,8.2,2.1/*右下角*/,3.64,2.1/*左下角*/}},
        {"blue_slide",{20.2,11.9/*左下*/,20.2,13.2/*左上*/,24.4,13.2/*右上*/,24.4,11.9/*右下*/}},
        {"red_castle_area",{4.91,6.63/*左下*/,4.91,9.03/*左上*/,7.84,9.03/*右上*/,7.84,6.63/*右下*/}},
        {"blue_castle_area",{19.8,6.5,19.8,10.0,23.4,10.0,23.4,6.5}},
        {"red_outpost_area",{11.7,5.5/*左下*/,12.2,5.0/*左上*/,13.5,4.84/*右上*/,13.1,6.01/*右下*/}},
        {"blue_outpost_area",{15.9,10.5,15.9,9.37,14.7,9.38,14.5,10.6}},
        {"center_self_outpost",{16.0,5.9/*左下*/,16.0,2.48/*左上*/,10.1,2.4/*右上*/,10.1,6.0/*右下*/}},
        {"self_highway",{14.2,2.45/*左下*/,14.1,0.0/*左上*/,4.33,0.0/*右上*/,4.33,2.45/*右下*/}},
        {"chasing_area",{24.9,15.5,24.9,13.4,18.4,13.3,18.4,5.9,14.1,0.0,
        4.33,0.0,4.33,2.45,10.1,2.4,10.7,9.85
        ,16.0,15.5}},
        {"chasing_area_2",{17.1,12.0,13.1,12.0,11.7,9.74,11.7,4.01,16.1,3.94,17.3,6.06}},
        {"chasing_area_6f",{0.04,0.7,0.899,6.51,12.8,6.14,11.4,0.4}},
        {"T_height_castle_slide",{6.02,14.2,4.13,14.2,3.95,9.36,6.14,5.99,8.77,6.23,8.59,9.79,6.13,9.66}},
        {"highway_slide",{8.32,4.47,4.21,4.55,4.27,2.54,8.26,2.58}},
        {"center_slide_us",{11.0,3.63,9.93,1.81,15.8,1.72,16.6,3.26}},
        {"center_slide_enemy",{14.0,14.3,12.8,12.7,18.0,12.5,18.9,13.4}},
        {"test_area",{5.02,1.43/*左下*/,8.4,1.43/*右下*/,8.4,5.0/*右上*/,5.02,5.0/*左上*/}},
        {"test_area_luckin",{-2.86,-13.1/*左下*/,2.54,6.22/*右下*/,19.8,-4.62/*右上*/,5.18,3.03/*左上*/}},
    };

    auto blackboard = BT::Blackboard::create();

    for(const auto& pair : target_points) {
        const std::string& key = pair.first;
        const std::string& pose_str = pair.second;
        geometry_msgs::msg::PoseStamped pose = parsePose(pose_str);
        blackboard->set<geometry_msgs::msg::PoseStamped>(key, pose);
    }
    for(const auto& pair : region) {
        const std::string& key = pair.first;
        const std::vector<double>& pose_str = pair.second;
        blackboard->set(key, std::make_shared<Polygon>(pose_str));
    }
    auto tree = factory.createTreeFromFile(tree_path, blackboard);

    // Connect the Groot2Publisher. This will allow Groot2 to get the tree and poll status updates.
    // const unsigned port = 1668;
    // BT::Groot2Publisher publisher(tree, port);
    rclcpp::Rate loop_rate(10);
    while(rclcpp::ok()) {
        tree.tickWhileRunning();
        loop_rate.sleep();
    }
    
    rclcpp::shutdown();
    return 0;
}