#include "ros/ros.h"
#include  "myfirst_laser/myfirst_msg.h"
#include  "myfirst_laser/second_msg.h"

void chatterCallback(const myfirst_laser::myfirst_msg::ConstPtr& msg)
{
	ROS_INFO("I hear: [%s]",msg->name.c_str());
}

void chatterCallback2(const myfirst_laser::second_msg::ConstPtr& msg)
{
	ROS_INFO("I hear:%s age:%d",msg->name.c_str(),msg->age);

}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"myfirst_listener");
	ros::NodeHandle n;
	ros::Subscriber sub=n.subscribe("myfirst_chatter",1000,chatterCallback);
	ros::Subscriber sub2=n.subscribe("second_chatter",1000,chatterCallback2);
	ros::spin();
	return 0;
}