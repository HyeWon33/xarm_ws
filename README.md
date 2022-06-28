# xarm_ws



## 1. ip setting

usb ethernet

wired setting

+

name

ipv4

manual 클릭

address에 192.168.1.10로 설정



연결 확인 : $ping 192.168.1.204



## 2. 그리퍼 빼고 bringup

```
$ caktin_make
$ source devel/setup.bash
$ roslaunch xarm_bringup xarm5_server.launch robot_ip:=192.168.1.204

$ source devel/setup.bash
$ roslaunch xarm5_moveit_config realMove_exec.launch robot_ip:=192.168.1.204
```



### 3. controller

```
$ sudo apt-get install ros-melodic-rqt-joint-trajectory-controller
$ rosrun rqt_joint_traj_controller rqt_joint_trajectory_controller
```





## 4. xarm_move 코드 작동

```
$ caktin_make
$ source devel/setup.bash
$ rosrun xarm_interface xarm_move
```

---------------------------------------------------------------------------------------------------------------------
## 1. 셋팅

```
$ cd ~/catkin_ws/src
$ git clone https://github.com/xArm-Developer/xarm_ros.git --recursive
```

```
$ cd ~/catkin_ws/src/xarm_ros
$ git pull
$ git submodule sync
$ git submodule update --init --remote
```

```
$ rosdep update
$ rosdep check --from-paths . --ignore-src --rosdistro melodic
```

## 2.bringup
```
$ caktin_make
$ source devel/setup.bash
$ roslaunch xarm_bringup xarm5_server.launch robot_ip:=192.168.1.210

$ source devel/setup.bash
$ roslaunch xarm5_gripper_moveit_config realMove_exec.launch robot_ip:=192.168.1.210
```
  ## 3. gazebo
  ```
$ roslaunch xarm5_gripper_moveit_config xarm5_gripper_moveit_gazebo.launch  
$ roslaunch xarm_gazebo xarm5_beside_table.launch add_gripper:=true  
$ rosrun PACK_NAME FILE_NAME
  ```
