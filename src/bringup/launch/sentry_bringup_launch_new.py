#!/usr/bin/env python3

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction, RegisterEventHandler, TimerAction, 
                            IncludeLaunchDescription, SetEnvironmentVariable, ExecuteProcess)
from launch.event_handlers import (OnExecutionComplete, OnProcessExit,
                                OnProcessIO, OnProcessStart, OnShutdown)
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression, FindExecutable
from launch_ros.actions import PushRosNamespace, Node
from launch.substitutions import Command

from datetime import datetime


def generate_launch_description():
    # Get the directory
    bringup_dir = get_package_share_directory('bringup')
    localization_dir=get_package_share_directory('fast_lio')
    loam_interface_dir=get_package_share_directory('loam_interface')
    pcd_project_launch_dir = get_package_share_directory('pointcloud_to_laserscan')
    livox_ros_driver2_dir=get_package_share_directory('livox_ros_driver2')
    linefit_ground_segmentation_ros_dir = get_package_share_directory('linefit_ground_segmentation_ros')
    # Get the sub-directories
    launch_dir = os.path.join(bringup_dir, 'launch')
    linefit_ground_segmentation_ros_launch_dir = os.path.join(linefit_ground_segmentation_ros_dir, 'launch')
    log_name = '/opt/rosbag/'+datetime.now().strftime('%Y_%m_%d_%H_%M_%S')

    # Create the launch configuration variables
    namespace = LaunchConfiguration('namespace')
    use_namespace = LaunchConfiguration('use_namespace')

    slam_mode = LaunchConfiguration('slam_mode')
    autonomy_mode = LaunchConfiguration('autonomy_mode')
    use_sim_time = LaunchConfiguration('use_sim_time')
    use_rviz = LaunchConfiguration('use_rviz')

    params_file = LaunchConfiguration('params_file')
    map_yaml_file = LaunchConfiguration('map')
    map3d_file = LaunchConfiguration('map3d')

    autostart = LaunchConfiguration('autostart')
    log_level = LaunchConfiguration('log_level')


    # Declare arguments
    colorized_output_envvar = SetEnvironmentVariable("RCUTILS_COLORIZED_OUTPUT", "1")
    stdout_linebuf_envvar = SetEnvironmentVariable(
        'RCUTILS_LOGGING_BUFFERED_STREAM', '1')

    declare_namespace_cmd = DeclareLaunchArgument(
        'namespace',
        default_value='',
        description='Top-level namespace')

    declare_use_namespace_cmd = DeclareLaunchArgument(
        'use_namespace',
        default_value='False',
        description='Whether to apply a namespace to the navigation stack')

    declare_slam_mode_cmd = DeclareLaunchArgument(
        'slam_mode',
        default_value='False',
        description='Whether run a SLAM')

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='False',
        description='Top-level namespace')

    declare_use_rviz_cmd = DeclareLaunchArgument(
        'use_rviz',
        # default_value='False',
        default_value='True',
        description="Use rviz to visualize or not"
    )

    declare_autonomy_mode_cmd = DeclareLaunchArgument(
        'autonomy_mode',
        default_value='True',
        description="Use autonomy or not"
    )

    declare_params_file_cmd = DeclareLaunchArgument(
        "params_file",
        default_value=os.path.join(bringup_dir, "params", "nav2_params.yaml"),
        description="Full path to the ROS2 parameters file to use for all launched nodes",
    )

    declare_map_yaml_cmd = DeclareLaunchArgument(
        'map',
        default_value=os.path.join(


        bringup_dir, 'maps','blank.yaml'),
  
        # bringup_dir, 'maps','rmuc_2025_final.yaml'),

        description='Full path to map yaml file to load')
    
    declare_3dmap_yaml_cmd = DeclareLaunchArgument(
        'map3d',
        default_value=os.path.join(
        bringup_dir, '3dmap',
        # 'rmuc_r_transformed_edited.pcd'),
        # 'Plane_sampled.pcd'),
        'rmuc_2025_fianl.pcd'),

        # 'scans_20250731_092010.pcd'),
        description='Full path to 3dmap yaml file to load')

    declare_autostart_cmd = DeclareLaunchArgument(
        'autostart', 
        default_value='True',
        # default_value='False',
        description='Automatically startup the nav2 stack')

    declare_log_level_cmd = DeclareLaunchArgument(
        'log_level',
        default_value='info',
        description='log level',
    )


    start_rviz_cmd = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(bringup_dir, 'rviz', 'nav2_default_view.rviz')],
        condition=IfCondition(use_rviz),
        output='screen')



    start_autonomy_cmd = Node(
        package='rm_autonomy',
        executable='sentry_autonomy_node',
        output='screen',
        condition=IfCondition(autonomy_mode)
    )

    static_tf_1 = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        # 参数顺序为：x y z roll pitch yaw parent_frame child_frame
        arguments=['0', '0', '0', '0', '0', '0', 'map', 'odom'],
    )




    # Specify the actions

    bringup_cmd_group = GroupAction([
        PushRosNamespace(
            condition=IfCondition(use_namespace),
            namespace=namespace),

            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(
                        pcd_project_launch_dir,'launch', 'sample_pointcloud_to_laserscan_launch.py'
                    )
                ),
            ),


        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(linefit_ground_segmentation_ros_launch_dir, 'segmentation.launch.py')),
            ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(livox_ros_driver2_dir,'launch_ROS2', 'msg_MID360_launch.py'))),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(localization_dir,'launch', 'mapping.launch.py'))),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(loam_interface_dir,'launch', 'loam_interface_launch.py'))),

         IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(launch_dir,
                                                       'localization_launch.py')),
            condition=IfCondition(PythonExpression(['not ', slam_mode])),
            launch_arguments={'namespace': namespace,
                              'map': map_yaml_file,
                              'use_sim_time': use_sim_time,
                              'autostart': autostart,
                              'params_file': params_file,
                              'use_lifecycle_mgr': 'false'}.items()),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(launch_dir, 'navigation_launch.py')),
            launch_arguments={'namespace': namespace,
                              'use_sim_time': use_sim_time,
                              'autostart': autostart,
                              'params_file': params_file,
                              'use_lifecycle_mgr': 'false',
                              'map_subscribe_transient_local': 'true'}.items()),
    ])


    # Create the launch description and populate
    ld = LaunchDescription()

    # Set environment variables
    ld.add_action(stdout_linebuf_envvar)
    ld.add_action(colorized_output_envvar)

    # Set server nodes

    # Declare the launch options
    ld.add_action(declare_namespace_cmd)
    ld.add_action(declare_use_sim_time_cmd)
    ld.add_action(declare_use_namespace_cmd)
    ld.add_action(declare_slam_mode_cmd)
    ld.add_action(declare_use_rviz_cmd)
    ld.add_action(declare_autonomy_mode_cmd)
    ld.add_action(declare_map_yaml_cmd)
    ld.add_action(declare_3dmap_yaml_cmd)
    ld.add_action(declare_params_file_cmd)
    ld.add_action(declare_autostart_cmd)

    # Add the actions to launch all of the navigation nodes


    # ld.add_action(static_tf_1)
    ld.add_action(bringup_cmd_group)
    # ld.add_action(start_autonomy_cmd)
    ld.add_action(start_rviz_cmd)

    return ld
