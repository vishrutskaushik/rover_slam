#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf2_msgs/TFMessage.h>
#include <tf/transform_listener.h>
#include <iostream>
#include <vector>
#include <fstream>

int itr = 0;
std::vector<std::vector<double>> tf_spoofed_data;

class Map2BaseLink{
  public:
    tf::TransformBroadcaster transformBroadcaster;
    tf::Transform transform;
    tf::TransformListener transformListener;
    tf::StampedTransform stampedTransform;
    std::string map_frame = "map";
    std::string base_link_frame = "velodyne_base_link";

    void tfCallback(const tf2_msgs::TFMessage msg){
      if (msg.transforms[0].header.frame_id == "map" and msg.transforms[0].child_frame_id == "odom"){
        try{
          transformListener.lookupTransform("/map", "/base_link", ros::Time(0), stampedTransform);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          return;
        }
        transform.setOrigin( tf::Vector3(stampedTransform.getOrigin().x(), stampedTransform.getOrigin().y(), 0.0));
        transform.setRotation(stampedTransform.getRotation());
        transformBroadcaster.sendTransform(tf::StampedTransform(transform, ros::Time(tf_spoofed_data[itr][6]), map_frame, base_link_frame));
      }
    }
};


int main(int argc, char** argv){
  ros::init(argc, argv, "map2baselink");

  ros::NodeHandle node;
  Map2BaseLink map2BaseLink;

  ros::Subscriber sub = node.subscribe("tf", 10, &Map2BaseLink::tfCallback, &map2BaseLink);
  ros::spin();
  return 0;
};