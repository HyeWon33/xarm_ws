cmake_minimum_required(VERSION 3.0.2)
project(xarm_interface)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
  tf2
  tf2_geometry_msgs
  moveit_ros_planning_interface 
  moveit_ros_move_group
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES xarm_interface
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(xarm_move src/xarm_move.cpp)
target_link_libraries(xarm_move ${catkin_LIBRARIES})
