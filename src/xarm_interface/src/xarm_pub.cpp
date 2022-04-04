// #include <ros/ros.h>
// #include <iostream>
// #include <moveit/move_group_interface/move_group_interface.h>

// using namespace std;

// int main(int argc, char **argv){
//     ros::init(argc, argv, "xarm_move");
//     ros::NodeHandle nh;
//     ros::AsyncSpinner spinner(1);
//     spinner.start();

//     moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 
//     moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

//     vector<double> currentJointValue=arm.getCurrentJointValues();
//     vector<double> currentJointValue2 = gripper.getCurrentJointValues();

//     arm.setGoalJointTolerance(0.001);
//     arm.setMaxAccelerationScalingFactor(0.2);
//     arm.setMaxVelocityScalingFactor(0.05);

//     arm.setNamedTarget("home"); //moveitsetupassistant 
//     arm.move(); //robot move
//     sleep(1);

    
//     for(int i = 0; i < currentJointValue.size(); i++){
//         cout << currentJointValue[i] << ", ";
//     }
//     cout << endl;
    
//     currentJointValue[3] -= 3.141592/2;
//     arm.setJointValueTarget(currentJointValue);
//     arm.move();
//     sleep(1);

//     currentJointValue[3] += 3.141592/2;
//     arm.setJointValueTarget(currentJointValue);
//     arm.move();
//     sleep(1);


//     currentJointValue2[0] = 0.4;
//     cout << "gripper open" << endl;
//     gripper.setJointValueTarget(currentJointValue2);
//     gripper.move();
//     sleep(1);

//     currentJointValue2[0] = 0.855211;
//     cout << "gripper close" << endl;
//     gripper.setJointValueTarget(currentJointValue2);
//     gripper.move();
//     sleep(1);

//     return 0;
// }


// #include <ros/ros.h>
// #include <iostream>
// #include <moveit/move_group_interface/move_group_interface.h>
// #include <geometry_msgs/Pose.h>

// using namespace std;

// int main(int argc, char **argv){
//     ros::init(argc, argv, "xarm_move");
//     ros::NodeHandle nh;
//     ros::AsyncSpinner spinner(1);
//     spinner.start();

//     moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 
//     moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

//     vector<double> currentJointValue=arm.getCurrentJointValues();
//     vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
//     arm.setGoalJointTolerance(0.001);
//     arm.setMaxAccelerationScalingFactor(0.2);
//     arm.setMaxVelocityScalingFactor(0.05);

//     // cout << arm.getCurrentPose() << endl;
//     arm.setNamedTarget("home"); //moveitsetupassistant 
//     arm.move(); //robot move
//     sleep(1);

//     geometry_msgs::Pose target_pose;
//     bool a;
    
//     cout<< "==============================\n" << endl;

//     currentJointValue[3] -= 3.141592/2;
//     arm.setJointValueTarget(currentJointValue);
//     arm.move();
//     sleep(1);

//     for(int i = 0; i < currentJointValue.size(); i++){
//         cout << currentJointValue[i] << ", ";
//     }
//     cout << endl;

//     cout << arm.getCurrentPose() << endl;

//     // cout << arm.getCurrentPose() << endl;

//     // currentJointValue[3] += 3.141592/2;
//     // arm.setJointValueTarget(currentJointValue);
//     // arm.move();
//     // sleep(1);

//     cout<< "==============================\n" << endl;

//     arm.setRandomTarget();
//     arm.move();
//     sleep(1);

//     cout<< "==============================\n" << endl;
//     target_pose.orientation.x = -0.194166;
//     target_pose.orientation.y = 0.077499;
//     target_pose.orientation.z = -0.399222;
//     target_pose.orientation.w = 0.892701;
//     target_pose.position.x = 0.387305;
//     target_pose.position.y = 0.375973;
//     target_pose.position.z = 0.77781;
//     arm.setStartStateToCurrentState();
//     arm.setPoseTarget(target_pose, "link_eef");

//     moveit::planning_interface::MoveGroupInterface::Plan my_plan;
//     moveit_msgs::MotionPlanRequest response;

//     arm.plan(my_plan);
//     arm.execute(my_plan);
//     // target_pose.position.x = 0.292145; 
//     // target_pose.position.y = -0.535103;
//     // target_pose.position.z = -0.095766;

//     a = arm.setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);
//     cout << a << endl;
    
//     // arm.move();
//     sleep(1);

//     return 0;
// }




// home -> 지정한 xyz로 이동하는 코드

// #include <ros/ros.h>
// #include <iostream>
// #include <moveit/move_group_interface/move_group_interface.h>
// #include <geometry_msgs/Pose.h>

// using namespace std;

// int main(int argc, char **argv){
//     ros::init(argc, argv, "xarm_move");
//     ros::NodeHandle nh;
//     ros::AsyncSpinner spinner(1);
//     spinner.start();

//     moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 
//     moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

//     vector<double> currentJointValue=arm.getCurrentJointValues();
//     vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
//     arm.setGoalJointTolerance(0.001);
//     arm.setMaxAccelerationScalingFactor(0.2);
//     arm.setMaxVelocityScalingFactor(0.05);

//     cout << "go home" << endl;
//     arm.setNamedTarget("home"); //moveitsetupassistant 
//     arm.move(); //robot move
//     sleep(1);

//     geometry_msgs::Pose target_pose;
//     bool a;
    

    
//     cout << "go xyzwxyz" << endl;

//     target_pose.orientation.x = -0.194166;
//     target_pose.orientation.y = 0.077499;
//     target_pose.orientation.z = -0.399222;
//     target_pose.orientation.w = 0.892701;
//     target_pose.position.x = 0.387305;
//     target_pose.position.y = 0.375973;
//     target_pose.position.z = 0.77781;
//     arm.setStartStateToCurrentState();
//     arm.setPoseTarget(target_pose, "link_eef");

//     moveit::planning_interface::MoveGroupInterface::Plan my_plan;
//     moveit_msgs::MotionPlanRequest response;

//     arm.plan(my_plan);
//     arm.execute(my_plan);

//     a = arm.setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);
//     cout << a << endl;
    
//     // arm.move();
//     sleep(1);

//     return 0;
// }


#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/Pose.h>

using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_move");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 
    moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

    vector<double> currentJointValue=arm.getCurrentJointValues();
    vector<double> currentJointValue2 = gripper.getCurrentJointValues();
    
    arm.setGoalJointTolerance(0.001);
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.05);

    cout << "go home" << endl;
    arm.setNamedTarget("home"); //moveitsetupassistant 
    arm.move(); //robot move
    sleep(1);

    geometry_msgs::Pose target_pose;
    bool a;
    
    // cout << arm.getCurrentPose() << endl;

    cout << "go xyzwxyz" << endl;

    target_pose.orientation.x = 0.971848;
    target_pose.orientation.y = -0.000121;
    target_pose.orientation.z = 0.235608;
    target_pose.orientation.w = 0.000012;
    target_pose.position.x = 0.406744;
    target_pose.position.y = -0.000064;
    target_pose.position.z = 0.463915;
    arm.setStartStateToCurrentState();
    arm.setPoseTarget(target_pose, "link_eef");

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit_msgs::MotionPlanRequest response;

    arm.plan(my_plan);
    arm.execute(my_plan);

    a = arm.setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);
    cout << a << endl;
    
    // arm.move();
    sleep(1);

    return 0;
}