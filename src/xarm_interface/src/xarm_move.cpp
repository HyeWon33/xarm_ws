//1.
//home으로 이동

/*
#include <ros/ros.h>
#include <moveit/move_group_interface.h>

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

    return 0;
}
*/

//2.
//home으로 이동하고 출력

/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface.h>

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

    return 0;
}
*/


//3.
//home으로 이동하고 출력하고 joint4 이동

/*
#include <ros/ros.h>
#include <iostream>
#include <moveit/move_group_interface.h>

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
    arm.setJointvalueTarget(currentJointValue);
    arm.move();
    sleep(1);

    currentJointValue[3] += 3.141592/2; //0부터 시작하니까 j4야 라디안 값
    arm.setJointvalueTarget(currentJointValue);
    arm.move();
    sleep(1);

    return 0;
}
*/



//3.
//home으로 이동하고 출력하고 x, z이동

/*
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

    // vector<double> currentJointValue=arm.getCurrentJointValues();
    // for(int i = 0; i < currentJointValue.size(); i++){
    //     cout << currentJointValue[i] << ", ";
    // }
    // cout << endl;
    
    // currentJointValue[3] -= 3.141592/2; //0부터 시작하니까 j4야 라디안 값
    // arm.setJointvalueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    // currentJointValue[3] += 3.141592/2;
    // arm.setJointvalueTarget(currentJointValue);
    // arm.move();
    // sleep(1);

    geometry_msgs::PoseStamped currentPose; //curretnPose 에 = operator 없어서.
    currentPose = arm.getCurrentPose();
    cout << currentPose<<endl;

    //포지션 바꾸기
    geometry_msgs::Pose movePose;
    movePose.position.x = currentPose.pose.position.x + 0.1; //미터 단위
    movePose.position.y = currentPose.pose.position.y;
    movePose.position.z = currentPose.pose.position.z + 0.2;
    movePose.orientation = currentPose.pose.orientation;
    arm.setPoseTarget(movePose);
    arm.move();
    sleep(1);

    return 0;
}
*/





//tf
//4.
//home으로 이동하고 출력하고 x, z이동

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
    movePose.position.x = currentPose.pose.position.x + 0.1; //미터 단위
    movePose.position.y = currentPose.pose.position.y;
    movePose.position.z = currentPose.pose.position.z + 0.2;
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