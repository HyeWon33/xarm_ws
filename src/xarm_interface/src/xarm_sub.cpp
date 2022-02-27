#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>

using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_move");
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 

    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    arm.setNamedTarget("home"); //moveitsetupassistant 
    arm.move(); //robot move
    sleep(1);

    vector<double> currentJointValue=arm.getCurrentJointValues();
    for(int i = 0; i < currentJointValue.size(); i++){
        cout << currentJointValue[i] << ", ";
    }
    cout << endl;
    
    currentJointValue[3] -= 3.141592/2; //0부터 시작하니까 j4야 라디안 값
    arm.setJointValueTarget(currentJointValue);
    arm.move();
    sleep(1);

    currentJointValue[3] += 3.141592/2; //0부터 시작하니까 j4야 라디안 값
    arm.setJointValueTarget(currentJointValue);

    arm.move();
    sleep(1);

    return 0;
}