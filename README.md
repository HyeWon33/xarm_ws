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

