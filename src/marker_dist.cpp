#include "ros/ros.h"
#include "fiducial_msgs/FiducialTransformArray.h"
#include "robot_msgs/mrkrDist.h"


void marker_pose(const fiducial_msgs::FiducialTransformArray &fid_msg);
bool distances(robot_msgs::mrkrDist::Request &req, 
			 robot_msgs::mrkrDist::Response &res);
using namespace std;

float fiducial_dist;
//robot_msgs::mrkrDist::Response &res;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mrkr_server");
    ros::NodeHandle nh;

    ros::ServiceServer marker_dist = nh.advertiseService("mrkr_dist_srvr", distances);

    ros::Subscriber sub = nh.subscribe("/fiducial_transforms", 10, marker_pose);

    ROS_INFO("ready srv server!");

    ros::spin();

    return 0;
}


void marker_pose(const fiducial_msgs::FiducialTransformArray &fid_msg)
{
	for(int i=0; i<fid_msg.transforms.size() ; i++)
	{
		fiducial_dist = fid_msg.transforms[i].transform.translation.z;
		ROS_INFO("MARKER MOD id : %d, distance : %f", i, fiducial_dist);
	}
}


bool distances(robot_msgs::mrkrDist::Request &req, 
			 robot_msgs::mrkrDist::Response &res)
{
	if(fiducial_dist != 0 && fiducial_dist < 1)
		res.m_result = true;
	else
		res.m_result = false;

	return true;
}