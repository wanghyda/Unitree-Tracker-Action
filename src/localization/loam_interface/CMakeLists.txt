cmake_minimum_required(VERSION 3.10)
project(loam_interface)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## 【建议】注释掉 -Werror。
## PCL 库经常会产生很多警告，开启 Werror 会导致警告变成错误，导致编译失败。
add_definitions(-Wall) 
# add_definitions(-Wall -Werror) 

## Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#######################
## Find dependencies ##
#######################

find_package(ament_cmake_auto REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(pcl_conversions REQUIRED) # 显式查找 pcl_conversions
find_package(pcl_ros REQUIRED)

# ================== 新增：PCL 配置 ==================
find_package(PCL REQUIRED) # 必须查找系统 PCL 库

# 包含 PCL 头文件路径 (解决 fatal error 的关键)
include_directories(
  include
  ${PCL_INCLUDE_DIRS}
)

# 添加 PCL 相关的定义 (防止版本冲突)
add_definitions(${PCL_DEFINITIONS})
link_directories(${PCL_LIBRARY_DIRS})
# ===================================================

ament_auto_find_build_dependencies(REQUIRED
  pcl_ros
  livox_ros_driver2
  tf2_geometry_msgs
  pcl_conversions # 确保这里也包含
)

###########
## Build ##
###########

# 创建库
ament_auto_add_library(${PROJECT_NAME} SHARED
  DIRECTORY src
)

# ================== 新增：链接 PCL 库 ==================
# 将 PCL 的二进制库链接到刚才创建的项目库中
target_link_libraries(${PROJECT_NAME}
  ${PCL_LIBRARIES}
  ${pcl_ros_LIBRARIES}
)
# =======================================================

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN loam_interface::LoamInterfaceNode
  EXECUTABLE ${PROJECT_NAME}_node
)

if(BUILD_TESTING)
  set(ament_cmake_clang_format_CONFIG_FILE "${CMAKE_SOURCE_DIR}/.clang-format")
  find_package(ament_lint_auto REQUIRED)
  list(APPEND AMENT_LINT_AUTO_EXCLUDE
    ament_cmake_uncrustify
    ament_cmake_flake8
  )
  ament_lint_auto_find_test_dependencies()
endif()

#############
## Install ##
#############

ament_auto_package(
  INSTALL_TO_SHARE
  launch
)