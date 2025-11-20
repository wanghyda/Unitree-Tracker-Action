cmake_minimum_required(VERSION 3.5)
project(cmd_vel_processor)

# 设置 C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# 找到 ROS2 依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# 包含目录`
include_directories(
  include
  /home/unitree/wzb_unitree_sdk2_1110/include         # Unitree SDK 头文件
  /home/unitree/wzb_unitree_sdk2_1110/thirdparty/include/ddscxx            # ROS2 + CycloneDDS 头文件
  /home/unitree/wzb_unitree_sdk2_1110/thirdparty/include/

)

# 链接目录
link_directories(
  /home/unitree/wzb_unitree_sdk2_1110/lib/aarch64             # Unitree SDK 库
  /home/unitree/wzb_unitree_sdk2_1110/thirdparty/lib/aarch64
  
)

# 添加可执行文件
add_executable(cmd_vel_subscriber src/cmd_vel_subscriber.cpp)

# 依赖 ROS2 包
ament_target_dependencies(cmd_vel_subscriber
  rclcpp
  geometry_msgs
)

# 链接库（Unitree SDK + CycloneDDS）
target_link_libraries(cmd_vel_subscriber
  unitree_sdk2
  ddscxx
  ddsc
)

# 安装可执行文件
install(TARGETS
  cmd_vel_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
