cmake_minimum_required(VERSION 3.10) 
project(linefit_ground_segmentation_ros)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 注意：您之前设置了Debug模式但又加了-O3优化，这里我保留原样，
# 但建议如果是为了调试，去掉-O3；如果是为了运行速度，用Release模式。
set(CMAKE_BUILD_TYPE debug)
add_definitions(-std=c++17 -O3)

############################################################
#### 1. 新增：显式查找 PCL 库
find_package(PCL REQUIRED)
############################################################

find_package(ament_cmake_auto REQUIRED)

############################################################
#### 2. 新增：添加 PCL 的头文件路径
# 这一步至关重要，否则编译器找不到 <pcl/common/transforms.h>
include_directories(
  include
  ${PCL_INCLUDE_DIRS}
)

# 添加 PCL 的预处理器定义
add_definitions(${PCL_DEFINITIONS})
link_directories(${PCL_LIBRARY_DIRS})
############################################################

ament_auto_find_build_dependencies()

ament_auto_add_executable(ground_segmentation_node src/ground_segmentation_node.cc)

############################################################
#### 3. 新增：链接 PCL 库到可执行文件
target_link_libraries(ground_segmentation_node 
  ${PCL_LIBRARIES}
)
############################################################

ament_auto_package(INSTALL_TO_SHARE launch)

#############
# QTCREATOR #
#############
FILE(GLOB_RECURSE LibFiles "include/*")
add_custom_target(headers SOURCES ${LibFiles})