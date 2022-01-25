# custom_msgs_bridging

## Installation

Setup a ROS1 workspace and clone the right version of the repository:
```
mkdir -p ~/catkin_ws/src && cd ~/catkin_ws/src
catkin_init_workspace
git clone git@github.com:ipa320/custom_msgs_bridging.git -b ros1
source /opt/ros/$ROS_DISTRO/setup.bash
cd ~/catkin_ws
rosdep update && rosdep install --from-paths ./src -y -i -r
catkin build
source devel/setup.bash
```

Setup a ROS2 workspace and clone the right version of the repostory together with the bridge package
```
mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src
git clone git@github.com:ipa320/custom_msgs_bridging.git -b ros2
git clone git@github.com:ros2/ros1_bridge.git
source /opt/ros/$ROS_DISTRO/setup.bash
cd ~/ros2_ws
colcon build
source ~/ros2_ws/install/setup.bash
```

## Execution
