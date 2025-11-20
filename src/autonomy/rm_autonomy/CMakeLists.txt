cmake_minimum_required(VERSION 3.10)
project(rm_autonomy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find dependencies
find_package(ament_cmake_auto REQUIRED)
find_package(nav2_util REQUIRED)
find_package(nav2_costmap_2d REQUIRED)
find_package(nav_msgs REQUIRED)



ament_auto_find_build_dependencies()

# Install directories

set(PACKAGE_INCLUDE_DEPENDS
    rm_autonomy_interfaces
    rclcpp
    std_msgs
    std_srvs
    behaviortree_cpp
    nav2_util
    nav2_costmap_2d
    nav_msgs
    geometry_msgs
)

ament_auto_add_library(polygon SHARED
  src/polygon.cpp        
)

ament_auto_add_library(occupancy_grid_wrapper SHARED
  src/occupancy_grid_wrapper.cpp        
)

target_include_directories(polygon PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

ament_target_dependencies(polygon ${PACKAGE_INCLUDE_DEPENDS})


function(add_target_dependencies target)
    target_include_directories(${target} PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
    ament_target_dependencies(${target} ${PACKAGE_INCLUDE_DEPENDS})
    target_compile_definitions(${target} PRIVATE BT_PLUGIN_EXPORT)
    target_link_libraries(${target} polygon)
endfunction()

target_include_directories(occupancy_grid_wrapper PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

ament_target_dependencies(occupancy_grid_wrapper ${PACKAGE_INCLUDE_DEPENDS})


function(add_target_dependencies target)
    target_include_directories(${target} PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
    ament_target_dependencies(${target} ${PACKAGE_INCLUDE_DEPENDS})
    target_compile_definitions(${target} PRIVATE BT_PLUGIN_EXPORT)
    target_link_libraries(${target} occupancy_grid_wrapper)
endfunction()

ament_auto_add_executable(sentry_autonomy_node
    src/sentry_autonomy_node.cpp
)

target_include_directories(sentry_autonomy_node PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
ament_target_dependencies(sentry_autonomy_node ${PACKAGE_INCLUDE_DEPENDS})


ament_auto_add_library(get_current_location_action_bt_node SHARED 
    plugins/action/get_current_location_action_bt_node.cpp
)
add_target_dependencies(get_current_location_action_bt_node)

ament_auto_add_library(send_goal_action_bt_node SHARED 
    plugins/action/send_goal_action_bt_node.cpp
)
add_target_dependencies(send_goal_action_bt_node)

ament_auto_add_library(pub_chasing_position_btnode_action SHARED 
    plugins/action/pub_chasing_position_btnode_action.cpp
)
add_target_dependencies(pub_chasing_position_btnode_action)


# # Control nodes
# ament_auto_add_library(pipeline_sequence SHARED 
#     plugins/control/pipeline_sequence.cpp
# )
# add_target_dependencies(pipeline_sequence)

# ament_auto_add_library(round_robin_node SHARED 
#     plugins/control/round_robin_node.cpp
# )
# add_target_dependencies(round_robin_node)

install(TARGETS
    sentry_autonomy_node
    DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  bt_xml launch
  DESTINATION share/${PROJECT_NAME}
)

ament_auto_package()
