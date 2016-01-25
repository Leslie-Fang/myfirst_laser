#include "ros/ros.h"
#include  "myfirst_laser/myfirst_msg.h"

#include <sstream>

int main(int argc,char **argv)
{
	ros::init(argc,argv,"myfirst_talker");
	ros::NodeHandle n;
	//myfirst_laser packagename 
	//msg type name
	ros::Publisher myfirst_chatter_pub=n.advertise<myfirst_laser::myfirst_msg>("myfirst_chatter",1000);
	ros::Rate loop_rate(1.5);

	int count=1;
	while(ros::ok())
	{
		myfirst_laser::myfirst_msg my_msg;
		std::stringstream ss;
		ss<<"first No."<<count;
		my_msg.name=ss.str();
		
		ROS_INFO("%s",my_msg.name.c_str());

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
