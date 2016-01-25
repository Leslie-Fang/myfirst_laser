#include "ros/ros.h"
#include  "myfirst_laser/second_msg.h"
#include  "myfirst_laser/myfirst_msg.h"

#include <sstream>

myfirst_laser::second_msg my_msg;

void chatterCallback(const myfirst_laser::myfirst_msg::ConstPtr& msg)
{
	ROS_INFO("I hear the name: [%s]",msg->name.c_str());
	my_msg.name=msg->name;
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"second_talker");
	ros::NodeHandle n;
	ros::Publisher myfirst_chatter_pub=n.advertise<myfirst_laser::second_msg>("second_chatter",1000);
	ros::Rate loop_rate(1);

	ros::Subscriber sub=n.subscribe("myfirst_chatter",1000,chatterCallback);
	
	my_msg.name="leslie";
	

	int count=1;
	while(ros::ok())
	{
		my_msg.age=count;
		myfirst_chatter_pub.publish(my_msg);
		ros::spinOnce();
		loop_rate.sleep();
		if(count>=10)
		{
			count=0;
		}
		++count;

	}

	return 0;
}