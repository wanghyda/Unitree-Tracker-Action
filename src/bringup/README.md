# sentry_nav2_bringup

Sentry bringup assets and scripts.

## Assets

Maps:

- blank.yaml
  Blank map

- rmuc_2023_national.yaml
  Map built in 2023 RMUC national competition.

- RMUL2024_sim.yaml
  Map built in 2024 RMUL simulatior

## Launch Sentry Nav2(not SLAM) in *Simulation* with Gazebo
### Pre-requisites:

* Go to [rm_navigation_simulator](https://mirrors.sustech.edu.cn/git/artinx/rm_navigation_simulator)
* Follow the instruction on that repo.

### Launch

```bash
ros2 launch sentry_nav2_bringup sentry_simulation_launch.py
```

## Launch Sentry Nav2 SLAM in *Simulation* with Gazebo

### Pre-requisites:

* Go to [rm_navigation_simulator](https://mirrors.sustech.edu.cn/git/artinx/rm_navigation_simulator)
* Follow the instruction on that repo.

### Launch

```bash
ros2 launch sentry_nav2_bringup sentry_slam_simulation_launch.py
```

## Launch Nav2 SLAM on a *Sentry*

### Pre-requisites:

- Make Sure that serial-port is available. If using ttl, the port is `/dev/ttyUSB0`. If using micro-usb, the port is `dev/ttyUSB0`

### Launch

```bash
ros2 launch sentry_nav2_bringup sentry_bringup_launch.py
```

## Launch Nav2 on a *Sentry*

### Pre-requisites:

- Make Sure that serial-port is available. If using ttl, the port is `/dev/ttyUSB0`. If using micro-usb, the port is `dev/ttyUSB0`

### Launch

```bash
ros2 launch sentry_nav2_bringup sentry_slam_bringup_launch.py
```

## nav2 params files explained

TODO