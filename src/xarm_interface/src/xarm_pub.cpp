/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>

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

    arm.setNamedTarget("home"); //moveitsetupassistant 
    arm.move(); //robot move
    sleep(1);

    
    for(int i = 0; i < currentJointValue.size(); i++){
        cout << currentJointValue[i] << ", ";
    }
    cout << endl;
    
    currentJointValue[3] -= 3.141592/2;
    arm.setJointValueTarget(currentJointValue);
    arm.move();
    sleep(1);

    currentJointValue[3] += 3.141592/2;
    arm.setJointValueTarget(currentJointValue);
    arm.move();
    sleep(1);


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


/*
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

    // cout << arm.getCurrentPose() << endl;
    arm.setNamedTarget("home"); //moveitsetupassistant 
    arm.move(); //robot move
    sleep(1);

    geometry_msgs::Pose target_pose;
    bool a;
    
    cout<< "==============================\n" << endl;

    currentJointValue[3] -= 3.141592/2;
    arm.setJointValueTarget(currentJointValue);
    arm.move();
    sleep(1);

    for(int i = 0; i < currentJointValue.size(); i++){
        cout << currentJointValue[i] << ", ";
    }
    cout << endl;

    cout << arm.getCurrentPose() << endl;

    // cout << arm.getCurrentPose() << endl;

    // currentJointValue[3] += 3.141592/2;
    // arm.setJointValueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    cout<< "==============================\n" << endl;

    arm.setRandomTarget();
    arm.move();
    sleep(1);

    cout<< "==============================\n" << endl;
    target_pose.orientation.x = -0.194166;
    target_pose.orientation.y = 0.077499;
    target_pose.orientation.z = -0.399222;
    target_pose.orientation.w = 0.892701;
    target_pose.position.x = 0.387305;
    target_pose.position.y = 0.375973;
    target_pose.position.z = 0.77781;
    arm.setStartStateToCurrentState();
    arm.setPoseTarget(target_pose, "link_eef");

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit_msgs::MotionPlanRequest response;

    arm.plan(my_plan);
    arm.execute(my_plan);
    // target_pose.position.x = 0.292145; 
    // target_pose.position.y = -0.535103;
    // target_pose.position.z = -0.095766;

    a = arm.setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);
    cout << a << endl;
    
    // arm.move();
    sleep(1);

    return 0;
}
*/




// home -> 지정한 xyz로 이동하는 코드

/*
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

    cout << "go xyzwxyz" << endl;

    target_pose.orientation.x = -0.194166;
    target_pose.orientation.y = 0.077499;
    target_pose.orientation.z = -0.399222;
    target_pose.orientation.w = 0.892701;
    target_pose.position.x = 0.387305;
    target_pose.position.y = 0.375973;
    target_pose.position.z = 0.77781;
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
*/


// 이거
/*
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
*/



// 단순히 현재 좌표 출력하는 코드
/*
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
    
    cout << arm.getCurrentPose() << endl;

    sleep(1);

    return 0;
}
*/


/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/LinearMath/Quaternion.h>

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

    geometry_msgs::PoseStamped currentPose; //curretnPose 에 = operator 없어서.
    currentPose = arm.getCurrentPose();
    cout << currentPose<<endl;

    //포지션 바꾸기
    geometry_msgs::Pose movePose;
    movePose.position.x = currentPose.pose.position.x; //미터 단위
    movePose.position.y = currentPose.pose.position.y;
    movePose.position.z = currentPose.pose.position.z + 0.3;
    movePose.orientation = currentPose.pose.orientation;
    arm.setPoseTarget(movePose);
    arm.move();
    sleep(1);

    currentPose = arm.getCurrentPose();
    movePose.position=currentPose.pose.position;


    tf2::Quaternion q_orig, q_rot, q_new;
    double r=0, p=3.141592/2, y=0; //p만 90도 돌려줄려고

    tf2::convert(currentPose.pose.orientation, q_orig);
    q_rot.setRPY(r, p, y);

    q_new = q_orig * q_rot;
    q_new.normalize(); //쿼터니언이 자세를 알려 주는 것 벡터 갑ㅅ 인데 크기 캘리,.. 맵핑.. 
   
    tf2::convert(q_new, movePose.orientation); //tf2라는 객체를 지오메트리 객체로 변경해준다.
    
    arm.setPoseTarget(movePose);
    arm.move();
    sleep(1);
    //포지션은 고정되어있는데 오리만 바뀐다... 

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
    bool a;
    
    // cout << arm.getCurrentPose() << endl;

    arm.getJointValueTarget();
    target_pose.position.x = 0.207033;
    target_pose.position.y = -0.00000807133;
    target_pose.position.z = 0.39458;

    target_pose.orientation.x = 0.7071068;
    target_pose.orientation.y = -0.7071068;
    target_pose.orientation.z = 0;
    target_pose.orientation.w = 0;

    sleep(1);
   
    
    arm.setStartStateToCurrentState();
    arm.setPoseTarget(target_pose, "link_tcp");

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit_msgs::MotionPlanRequest response;

    arm.plan(my_plan);
    arm.execute(my_plan);

    // a = arm.setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);
    // cout << a << endl;
    
    // arm.move();
    sleep(1);

    return 0;
}



// #include <ros/ros.h>
// #include <iostream>
// #include <moveit/move_group_interface/move_group_interface.h>
// #include <moveit/planning_scene_interface/planning_scene_interface.h>
// #include <geometry_msgs/Pose.h>
// #include <sensor_msgs/JointState.h>

// #include <moveit_visual_tools/moveit_visual_tools.h>
// #include <moveit_msgs/DisplayRobotState.h>
// #include <moveit_msgs/DisplayTrajectory.h>

// #include <moveit_msgs/AttachedCollisionObject.h>
// #include <moveit_msgs/CollisionObject.h>

// #include <moveit/robot_model_loader/robot_model_loader.h>
// #include <moveit/robot_model/robot_model.h>
// #include <moveit/robot_state/robot_state.h>

// using namespace std;

// int main(int argc, char **argv){
//     ros::init(argc, argv, "xarm_move");
//     ros::NodeHandle nh;
//     ros::AsyncSpinner spinner(1);
//     spinner.start();
//     static const std::string PLANNING_GROUP = "xarm5";

//     moveit::planning_interface::MoveGroupInterface arm("xarm5"); //moveitsetupassistant 
//     moveit::planning_interface::MoveGroupInterface gripper("xarm_gripper");

//     vector<double> currentJointValue=arm.getCurrentJointValues();
//     vector<double> currentJointValue2 = gripper.getCurrentJointValues();
//     const robot_model::JointModelGroup* joint_model_group_;
    
//     arm.setGoalJointTolerance(0.001);
//     arm.setMaxAccelerationScalingFactor(0.2);
//     arm.setMaxVelocityScalingFactor(0.05);

    
//     // joint_std::vector<double> joint_values;

//     // kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
//     // for (std::size_t i = 0; i < joint_names.size(); ++i)
//     // {
//     //     ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
//     // }


//     cout << arm.getCurrentPose("link_tcp") << endl;


//     // cout << "go home" << endl;
//     // arm.setNamedTarget("home"); //moveitsetupassistant 
//     // arm.move(); //robot move
//     // sleep(1);
//     // geometry_msgs::Pose target_pose;

//     // const robot_state::JointModelGroup* joint_model_group =
//     //   arm.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

//     // ROS_INFO_NAMED("tutorial", "Planning frame: %s", arm.getPlanningFrame().c_str());

//     // ROS_INFO_NAMED("tutorial", "End effector link: %s", arm.getEndEffectorLink().c_str());

//     // ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
//     // std::copy(arm.getJointModelGroupNames().begin(), arm.getJointModelGroupNames().end(),
//     // std::ostream_iterator<std::string>(std::cout, ", "));

//     // cout << arm.getRobotModel() << endl;

//     // cout << arm.getCurrentPose() << endl;
   


    
//     sleep(1);

//     return 0;
// }