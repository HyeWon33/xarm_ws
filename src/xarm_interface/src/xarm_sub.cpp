
//1.
//joint 이동

/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/JointState.h>


using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_move");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface arm("xarm5"); 
    moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

    vector<double> currentJointValue=arm.getCurrentJointValues();
    vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    cout << "go home" << endl;
    arm.setNamedTarget("home"); 
    arm.move(); //robot move
    sleep(1);

    geometry_msgs::Pose target_pose;
    bool a;


    geometry_msgs::PoseStamped currentPose; //curretnPose 에 = operator 없어서.
    currentPose = arm.getCurrentPose();
    cout << currentPose<<endl;


    currentJointValue[3] -= 3.141592/2;
    arm.setJointValueTarget(currentJointValue);
    arm.move();
    sleep(1);

    // target_pose.position.x = 0.3;
    // target_pose.position.y = -0.00000807133;
    // target_pose.position.z = 0.39458;

    // target_pose.orientation.x = -0.710263;
    // target_pose.orientation.y = 0.703931;
    // target_pose.orientation.z = -0.00206424;
    // target_pose.orientation.w = 0.00204172;

    // target_pose.orientation = currentPose.pose.orientation;
    
    // sleep(1);
    // arm.setStartStateToCurrentState();
    // arm.setPoseTarget(target_pose, "link_tcp");

    // moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    // moveit_msgs::MotionPlanRequest response;

    // arm.plan(my_plan);
    // arm.execute(my_plan);

    
    // arm.move();
    sleep(1);

    return 0;
}
*/


// 2.
// xyz이동

/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/JointState.h>


using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_move");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface arm("xarm5"); 
    moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

    vector<double> currentJointValue=arm.getCurrentJointValues();
    vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    cout << "go home" << endl;
    arm.setNamedTarget("home"); 
    arm.move(); //robot move
    sleep(1);

    geometry_msgs::Pose target_pose;
    bool a;


    geometry_msgs::PoseStamped currentPose; //curretnPose 에 = operator 없어서.
    currentPose = arm.getCurrentPose();
    cout << currentPose<<endl;


    target_pose.position.x = 0.3;
    target_pose.position.y = -0.00000807133;
    target_pose.position.z = 0.39458;

    target_pose.orientation.x = -0.710263;
    target_pose.orientation.y = 0.703931;
    target_pose.orientation.z = -0.00206424;
    target_pose.orientation.w = 0.00204172;

    // target_pose.orientation = currentPose.pose.orientation;
    
    sleep(1);
    arm.setStartStateToCurrentState();
    arm.setPoseTarget(target_pose, "link_tcp");

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit_msgs::MotionPlanRequest response;

    arm.plan(my_plan);
    arm.execute(my_plan);

    
    // arm.move();
    sleep(1);

    return 0;
}
*/

// 3.
//gripper

/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/JointState.h>


using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_move");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface arm("xarm5"); 
    moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

    vector<double> currentJointValue=arm.getCurrentJointValues();
    vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    cout << "go home" << endl;
    arm.setNamedTarget("home"); 
    arm.move(); //robot move
    sleep(1);

    // geometry_msgs::Pose target_pose;
    // bool a;


    // geometry_msgs::PoseStamped currentPose; //curretnPose 에 = operator 없어서.
    // currentPose = arm.getCurrentPose();
    // cout << currentPose << endl;


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

    return 0;
}
*/










#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/JointState.h>


using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_move");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface arm("xarm5"); 
    moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

    vector<double> currentJointValue=arm.getCurrentJointValues();
    vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    cout << "go home" << endl;
    arm.setNamedTarget("home"); 
    arm.move(); //robot move
    sleep(1);

    geometry_msgs::Pose target_pose;


    geometry_msgs::PoseStamped currentPose; //curretnPose 에 = operator 없어서.
    currentPose = arm.getCurrentPose();
    cout << currentPose<<endl;


    target_pose.position.x = 0.207533;
    target_pose.position.y = -0.341972;
    target_pose.position.z = 0.591564;

    target_pose.orientation.x = 0.616216;
    target_pose.orientation.y = -0.346819;
    target_pose.orientation.z = 0.616182;
    target_pose.orientation.w = 0.3468565;

    // target_pose.orientation = currentPose.pose.orientation;
    
    sleep(1);
    arm.setStartStateToCurrentState();
    arm.setPoseTarget(target_pose, "link_tcp");

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit_msgs::MotionPlanRequest response;

    arm.plan(my_plan);
    arm.execute(my_plan);


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


    target_pose.position.x = 0.709229;
    target_pose.position.y = -0.00404761;
    target_pose.position.z = 0.151429;

    target_pose.orientation.x = 0.720195;
    target_pose.orientation.y = 0.0000165608;
    target_pose.orientation.z = 0.693761;
    target_pose.orientation.w = 0.00397689;

    sleep(1);
    // arm.setStartStateToCurrentState();
    arm.setPoseTarget(target_pose, "link_tcp");

    // moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    // moveit_msgs::MotionPlanRequest response;

    // arm.plan(my_plan);
    // arm.execute(my_plan);
    arm.move();

    currentJointValue2[0] = 0.4;
    cout << "gripper open" << endl;
    gripper.setJointValueTarget(currentJointValue2);
    gripper.move();
    sleep(1);


    cout << "go home" << endl;
    arm.setNamedTarget("home"); 
    arm.move(); //robot move
    sleep(1);
    // arm.move();
    sleep(1);

    return 0;
}