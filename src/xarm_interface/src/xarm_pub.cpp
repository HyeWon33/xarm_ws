#include <ros/ros.h>
#include <iostream>
#include <std_msgs/Int32.h>
#include <moveit/move_group_interface/move_group_interface.h>

using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "xarm_pub");

    ros::NodeHandle nh;

    ros::Publisher num_pub = nh.advertise<std_msgs::Int32>("num", 1);

    std_msgs::Int32 check_num;

    check_num.data = 1;

    num_pub.publish(check_num);

    cout << "publish check_num" << endl;
    
    return 0;
}