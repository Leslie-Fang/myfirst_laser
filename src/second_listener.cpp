#include "ros/ros.h"
#include  "myfirst_laser/second_msg.h"

void chatterCallback(const myfirst_laser::second_msg::ConstPtr& msg)
{
	ROS_INFO("I hear name:%s age:%d",msg->name.c_str(),msg->age);
	
	//ROS_INFO(msg->age);
	//ROS_INFO("I hear:");

}



int main(int argc,char **argv)
{
	ros::init(argc,argv,"second_listener");
	ros::NodeHandle n;
	ros::Subscriber sub=n.subscribe("second_chatter",1000,chatterCallback);
	//ros::Subscriber sub2=n.subscribe("myfirst_chatter",1000,chatterCallback2);
	ros::spin();
	return 0;
}