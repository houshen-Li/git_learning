#include<ros/ros.h>
#include"topic_pkg/Person.h"
#include<iostream>

int main(int argc,char**argv){
    ros::init(argc,argv,"publisher_topic");
    ros::NodeHandle n;

    ros::Publisher pub_=n.advertise<topic_pkg::Person>("person_info",10);
    ros::Rate loop_rate(10);
    while(ros::ok()){
        topic_pkg::Person msg;
        msg.name="Tom";
        msg.age=18;
        msg.sex=topic_pkg::Person::male;

        pub_.publish(msg);
        ROS_INFO("has sended");
        loop_rate.sleep();
    }
    return 0;
}