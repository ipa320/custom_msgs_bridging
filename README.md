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

## Shell 1
Source your ros1 installation
Start roscore

## Shell 2
cd ros1/ws
source devel/setup.bash
rosrun custom_msg_ros1 talker.py

## Shell 3
Source ROS 1 first: source /opt/ros/noetic/setup.bash
Or: source home/catkin ws/devel/setup.bash
Source ROS 2 next:
source home/ros2_ws/install/localsetup.bash
export ROS MASTER URI=http://localhost:11311
ros2 run ros1_bridge dynamic_bridge  //The program will start outputting the currently available topics in ROS 1 and ROS 2 in a regular interval.

## Shell 4
cd ros2_ws/
source install/setup.bash
ros2 run custom_msgs_ros2 listener

