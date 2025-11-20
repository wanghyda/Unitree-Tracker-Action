cmake_minimum_required(VERSION 3.8)
project(rm_autonomy_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_auto REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/AllRobotHP.msg"
  "msg/AllyRobotPosition.msg"
  "msg/ArenaStatus.msg"
  "msg/AutoaimCommunication.msg"
  "msg/GameStatus.msg"
  "msg/EnemyRobotMark.msg"
  "msg/HumanIntervention.msg"
  "msg/OmniSensing.msg"
  "msg/RadarEnemyPosition.msg"
  "msg/RadarTarget.msg"
  "msg/SelfState.msg"
  "msg/NavigateCommand.msg"
  "msg/FireTrigger.msg"
  "msg/InvincibleTarget.msg"
  "msg/ChaseControl.msg"

  DEPENDENCIES
    std_msgs
)

ament_package()
