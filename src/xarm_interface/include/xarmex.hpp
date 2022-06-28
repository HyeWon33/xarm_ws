#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/Pose.h>

class Can
{
private:
	ros::NodeHandle nh;
	std::vector<std::string> joint_name;
	std::string planning_group_name;
	std::string planning_group_name2;
	moveit::planning_interface::MoveGroupInterface* arm;
	moveit::planning_interface::MoveGroupInterface* gripper;
	
public:
	Can();
	~Can();
	std::vector<double> currentJointValue;
	std::vector<double> currentJointValue2;
	void home();
	void go_catch();
	void gripper_open();
	void gripper_close();
	void put();

};