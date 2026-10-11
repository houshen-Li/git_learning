#include<ros/ros.h>
#include"topic_pkg/Person.h"
#include<iostream>


void callback(const topic_pkg::Person::ConstPtr &msg){
    ROS_INFO("Subcriber Person info: name: %s age: %d sex: %d",msg->name.c_str(),msg->age,msg->sex);

}
int main(int argc,char**argv){
    ros::init(argc,argv,"person_subcriber");
    ros::NodeHandle n;
    ros::Subscriber sub_=n.subscribe<topic_pkg::Person>("person_info",10,callback);
    ros::spin();
    //test
    return 0;
}