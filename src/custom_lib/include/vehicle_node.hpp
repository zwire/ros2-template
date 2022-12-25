#ifndef CUSTOM_LIB_VEHICLE_NODE_HPP_
#define CUSTOM_LIB_VEHICLE_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include "custom_msgs/msg/vehicle_status.hpp"

class VehicleNode : public rclcpp::Node
{
private:
  rclcpp::Publisher<custom_msgs::msg::VehicleStatus>::SharedPtr pub_;
  rclcpp::Subscription<custom_msgs::msg::VehicleStatus>::SharedPtr sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  float speed_;
  float steer_;
public:
  VehicleNode(
    const std::string& name_space = "", 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
};

#endif