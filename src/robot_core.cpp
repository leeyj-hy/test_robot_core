#include <ros/ros.h>
#include "fiducial_msgs/FiducialTransformArray.h"
#include "std_msgs/Float64.h"

int mod=0;

void test_marker_3d_t_r(const fiducial_msgs::FiducailTransformArray &msg)
{
	for(int i=0; i<msg.transforms.size() ; i++)
	{
		ROS_INFO("%d", i);
		ROS_INFO("TRANS_Z : %f", msg.transforms[i].transform.translation.z);

		if()
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_robot_core");

	ros::NodeHandle nh;
	ros::Subscriber marker_sub= nh.subscribe("/fiducial_transforms",10,test_marker_3d_t_r);
	ros::Rate loop_rate(10);

	while(ros::ok())
	{

		switch(mod)
		{
			case 1 :

			break;

			case 2 ;

			break;

			default:

			break;
		}

		ros::spinOnce();
		loop_rate.sleep();
	}
}