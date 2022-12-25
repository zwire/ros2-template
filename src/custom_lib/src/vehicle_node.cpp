#include "vehicle_node.hpp"

VehicleNode::VehicleNode(
  const std::string& name_space, 
  const rclcpp::NodeOptions& options
) : Node("vehicle", name_space, options)
{
  using namespace std::chrono_literals;
  pub_ = this->create_publisher<custom_msgs::msg::VehicleStatus>("info", rclcpp::QoS(10));
  timer_ = this->create_wall_timer(100ms,
    [this]()->void 
    {
      auto msg = std::make_shared<custom_msgs::msg::VehicleStatus>();
      auto stamp = rclcpp::Clock().now();
      msg->header.stamp.sec = stamp.seconds();
      msg->header.stamp.nanosec = stamp.nanoseconds();
      msg->speed = speed_;
      msg->steer = steer_;
      RCLCPP_INFO(this->get_logger(), "Pub: %d s, %f km/h, %f deg", msg->header.stamp.sec, msg->speed * 3.6, msg->steer * 180 / M_PI);
      pub_->publish(*msg);
    }
  );
  sub_ = this->create_subscription<custom_msgs::msg::VehicleStatus>("operation", rclcpp::QoS(10),
    [this](const custom_msgs::msg::VehicleStatus::SharedPtr msg)->void 
    {
      speed_ = msg->speed;
      steer_ = msg->steer;
      RCLCPP_INFO(this->get_logger(), "Sub: %d s, %f km/h, %f deg", msg->header.stamp.sec, msg->speed * 3.6, msg->steer * 180 / M_PI);
    }
  );
}