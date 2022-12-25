#include "vehicle_node.hpp"

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VehicleNode>());
  rclcpp::shutdown();
  return 0;
}
