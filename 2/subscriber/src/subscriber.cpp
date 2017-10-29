#include <stdio.h>
#include <ros/ros.h>
#include <std_msgs/Int32.h>

void recieve(const std_msgs::Int32 &msg)
{
  printf("%s: data: %d\n",
         ros::this_node::getName().c_str(),
         msg.data);
  return;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/topic", 1000, recieve);
  ros::spin();
  return 0;
}
