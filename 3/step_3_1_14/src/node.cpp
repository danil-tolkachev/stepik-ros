#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Point.h>

class Point2Marker
{
public:
  Point2Marker()
  {
    sub = nh.subscribe("/input", 1000, &Point2Marker::callback, this);
    pub = nh.advertise<visualization_msgs::Marker>("/output", 10, true);
    mrk.header.frame_id = "/frame_id";
    mrk.ns = "namespace";
    mrk.id = 0;
    mrk.action = visualization_msgs::Marker::ADD;
    mrk.type = visualization_msgs::Marker::POINTS;
    mrk.scale.x = 0.5;
    mrk.scale.y = 0.5;
    mrk.color.r = 1.0;
    mrk.color.g = 0.0;
    mrk.color.b = 0.0;
    mrk.color.a = 1.0;
  }

  void callback(const geometry_msgs::Point &pt)
  {
    mrk.points.push_back(pt);
    if (mrk.points.size() == 5)
    {
      mrk.header.stamp = ros::Time::now();
      pub.publish(mrk);
      mrk.points.clear();
    }
  }

private:
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
  visualization_msgs::Marker mrk;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "point2marker");
  Point2Marker object;
  ros::spin();
  return 0;
}
