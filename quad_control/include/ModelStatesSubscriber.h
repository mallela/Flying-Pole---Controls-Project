#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <Eigen/Dense>
#include <std_msgs/Bool.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Point.h>
#include <std_srvs/Empty.h>
#include <hector_quadrotor_controller/quadrotor_interface.h>
#include <controller_interface/controller.h>
#include <geometry_msgs/WrenchStamped.h>
#include <gazebo_msgs/ModelStates.h>
#include <gazebo_msgs/ModelState.h>
using namespace Eigen;
using namespace std;

class ModelStatesSubscriber{
private:
  ros::Subscriber model_sub;
  ros::Publisher motor_pub;

public:
  ModelStatesSubscriber(ros::NodeHandle n )
  {

     model_sub = n.subscribe("/gazebo/model_states",10, &ModelStatesSubscriber::modelCB,this);
     motor_pub = n.advertise<hector_uav_msgs::MotorCommand>("/command/motor",10);
   }
   void modelCB(const gazebo_msgs::ModelStates::ConstPtr& msg);
 };
