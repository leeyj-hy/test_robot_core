#include <ros/ros.h>
#include "fiducial_msgs/FiducialTransformArray.h"
#include "std_msgs/Float64.h"
#include "test_robot_core/mrkrDist.h"
#include "test_robot_core/usDist.h"

using namespace std;


bool marker_ok();
bool ultrasonic_ok();
void core_end();


ros::ServiceClient *m_client;
ros::ServiceClient *u_client;


int mod=0;


int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_robot_core");
	ros::NodeHandle nh;


	ros::ServiceClient m_client_tmp = nh.ServiceClient<test_robot_core::mrkrDist>("mrkr_dist_srvr");
	ros::ServiceClient u_client_tmp = nh.ServiceClient<test_robot_core::usDist>("us_dist_srvr");
	m_client=&m_client_tmp;
	u_client=&u_client_tmp;
	test_robot_core::mrkrDist mrkr_srv;
	test_robot_core::usDist us_srv;

	ros::Rate loop_rate(10);

	ROS_INFO("ROBOT READY!");


	mod=1;

	while(ros::ok())
	{

		switch(mod)
		{
			case 1 :  //marker mod
				marker_ok();
			break;


			case 2 ;  //ultrasonic mod
				ultrasonic_ok();
			break;


			case 3:
				core_end();
			break;


			default:

			break;
		}

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}


bool marker_ok()
{
	if(m_client.call(mrkr_srv)&&m_client.Result.m_result)
	{
		ROS_INFO("marker distance under 1 m !");
		mod=2;
	}
}


bool ultrasonic_ok()
{
	if(u_client.call(us_srv)&&u_client.Result.u_result)
	{
		ROS_INFO("ultrasonic distance under 10 cm !");
		mod=3;
	}
}


void core_end()
{
	ROS_INFO("docking finished!");
}