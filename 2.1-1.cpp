#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "node");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::Int32>("/topic", 1000);

	ros::Rate loop_rate(1);
	int number;
	while (std::cin >> number)
	{
		std_msgs::Int32 msg;
		msg.data = number;
		ROS_INFO("Read number: %d\n", msg.data);
		pub.publish(msg);
		loop_rate.sleep();
	}
	ros::spinOnce();
	return 0;
}
