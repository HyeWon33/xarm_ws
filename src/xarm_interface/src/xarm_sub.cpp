#include <ros/ros.h>
#include <iostream>
#include <std_msgs/Int32.h>
#include <moveit/move_group_interface/move_group_interface.h>

using namespace std;

void numnum(const std_msgs::Int32& msgs){

    cout << "1" << endl;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_sub");

    ros::NodeHandle nh;

    ros::AsyncSpinner spinner(1);
    spinner.start();
    
    
    
    
    int a = 0;

    if(a = 0){
        ros::Subscriber sub_num = nh.subscribe("num", 1, numnum);
        a++;
    }




    moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 

    moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    arm.setNamedTarget("home"); //moveitsetupassistant 
    arm.move(); //robot move
    cout << "home" << endl;
    sleep(1);

    vector<double> currentJointValue = arm.getCurrentJointValues();
    vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    

    // for(int i = 0; i < currentJointValue.size(); i++){
    //     cout << currentJointValue[i] << ", ";
    // }
    // cout << endl;
    
    currentJointValue2[0] = 0.4;
    cout << "gripper open" << endl;
    gripper.setJointValueTarget(currentJointValue2);
    gripper.move();
    sleep(1);

    currentJointValue2[0] = 0.855211;
    cout << "gripper close" << endl;
    gripper.setJointValueTarget(currentJointValue2);
    gripper.move();
    sleep(1);

    // currentJointValue[0] -= 0.174533;
    // arm.setJointValueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    // currentJointValue[1] -= 0.174533;
    // arm.setJointValueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    // currentJointValue[2] -= 0.174533;
    // arm.setJointValueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    // currentJointValue[3] -= 0.174533;
    // arm.setJointValueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    // currentJointValue[4] -= 0.174533;
    // arm.setJointValueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    cout << "end" << endl;

    return 0;
}
