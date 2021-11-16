#include "ros/ros.h"
#include "robot_msgs/usDist.h"
#include "std_msgs/Float64.h"


void ultrasonic_pose(const std_msgs::Float64 &us_msg);
bool distances(robot_msgs::usDist::Request &req, 
			 robot_msgs::usDist::Response &res);
using namespace std;


float ultrasonic_dist;
//robot_msgs::usDist::Response &res;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ultrasonic_server");
    ros::NodeHandle nh;

    ros::ServiceServer us_dist= nh.advertiseService("us_dist_srvr", distances);

    ros::Subscriber sub = nh.subscribe("/chatter", 10, ultrasonic_pose);

    ROS_INFO("ready ultrasonic server!");

    ros::spin();

    return 0;
}


void ultrasonic_pose(const std_msgs::Float64 &us_msg)
{
	ultrasonic_dist=us_msg.data;
	ROS_INFO("ULTRASONIC MOD distance : %f",us_msg);
	
}

bool distances(robot_msgs::usDist::Request &req, 
			 robot_msgs::usDist::Response &res)
{
	if(ultrasonic_dist<10)
		res.u_result=true;
	else
		res.u_result=false;

	return true;
}