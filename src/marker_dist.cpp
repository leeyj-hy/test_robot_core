#include "ros/ros.h"
#include "fiducial_msgs/FiducialTransformArray.h"
#include "test_robot_core/mrkrDist.h"
#include "fiducial_msgs/FiducialTransformArray.h"


void marker_pose(const fiducial_msgs::FiducialTransformArray &msg);
bool distance(test_robot_core::mrkrDist::Response &res);


float fiducial_dist;
test_robot_core::mrkrDist::Response &res

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mrkr_server");
    ros::NodeHandle nh;

    ros::ServiceServer marker_dist = nh.advertiseService("mrkr_dist_srvr", distance);

    ros::Subscriber sub = n.subscribe("/fiducial_transforms", 10, marker_pose);

    ROS_INFO("ready srv server!");

    ros::spin();

    return 0;
}


void marker_pose(const fiducial_msgs::FiducialTransformArray &fid_msg)
{
	fiducial_dist = fid_msg.transforms[0].transform.translation.z;
	ROS_INFO("%f",fiducial_dist);
}


bool distance(test_robot_core::mrkrDist::Request &req, 
			 test_robot_core::mrkrDist::Response &res)
{
	if(fiducial_dist < 1)
		res.response.m_result = true;
	else
		res.response.m_result = false;

	return true;
}