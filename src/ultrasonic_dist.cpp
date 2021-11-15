#include "ros/ros.h"
#include "test_robot_core/usDist.h"
#include "std_msgs/Float64.h"



ros::ServiceServer *us_dist;

void ultrasonic_pose(const fiducial_msgs::FiducialTransformArray &msg);
bool distance(test_robot_core::mrkrDist::Response &res);


float fiducial_dist;
test_robot_core::mrkrDist::Response &res

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ultrasonic_server");
    ros::NodeHandle nh;

    ros::ServiceServer us_dist_tmp = nh.advertiseService("us_dist_srvr", distance);
    us_dist=&us_dist_tmp;

    ros::Subscriber sub = n.subscribe("/chatter", 10, arduino_sub);

    ROS_INFO("ready srv server!");

    ros::spin();

    return 0;
}


void ultrasonic_pose(const std_msgs::Flota64 &us_msg)
{
	ROS_INFO("%f",us_msg);
	if(us_msg<10)
	{
		res.request.u_result = 1;
		distance();
	}
	else
		

}


bool distance(test_robot_core::mrkrDist::Response &res)
{
		return true;
}