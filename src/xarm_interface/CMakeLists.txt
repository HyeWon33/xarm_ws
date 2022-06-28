cmake_minimum_required(VERSION 3.0.2)
project(xarm_interface)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  moveit_core
  moveit_ros_planning
  tf2
  tf2_geometry_msgs
  moveit_ros_planning_interface 
  moveit_ros_move_group
  std_msgs
  geometry_msgs
)
find_package(Eigen3 REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES xarm_interface
  CATKIN_DEPENDS roscpp std_msgs geometry_msgs moveit_ros_planning_interface
  DEPENDS EIGEN3
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  SYSTEM ${EIGEN3_INCLUDE_DIRS}
)
set(${PROJECT_NAME}_HDRS
  ${PROJECT_NAME}/include/xarmex.hpp
)
add_executable(xarm_move src/xarm_move.cpp)
target_link_libraries(xarm_move ${catkin_LIBRARIES})
target_link_libraries(xarm_move ${catkin_LIBRARIES} ${Eigen3_LIBRARIES})

add_executable(xarm_sub src/xarm_sub.cpp)
target_link_libraries(xarm_sub ${catkin_LIBRARIES})
target_link_libraries(xarm_sub ${catkin_LIBRARIES} ${Eigen3_LIBRARIES})

add_executable(xarm_pub src/xarm_pub.cpp)
target_link_libraries(xarm_pub ${catkin_LIBRARIES})
target_link_libraries(xarm_pub ${catkin_LIBRARIES} ${Eigen3_LIBRARIES})

install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
