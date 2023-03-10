cmake_minimum_required(VERSION 3.8)
project(custom_component)

set(TARGET_NAME vehicle_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(custom_msgs REQUIRED)

add_library(${TARGET_NAME} src/vehicle_node.cpp)
target_compile_features(${TARGET_NAME} PUBLIC c_std_99 cxx_std_17)
target_include_directories(${TARGET_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  ${TARGET_NAME}
  "rclcpp"
  "rclcpp_components"
  "custom_msgs"
)

# add a postscript
rclcpp_components_register_node(
  ${TARGET_NAME}
  PLUGIN "custom_component::VehicleNode"
  EXECUTABLE exe
)

target_compile_definitions(${TARGET_NAME} PRIVATE "CUSTOM_COMPONENT_BUILDING_LIBRARY")

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS ${TARGET_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_libraries(${TARGET_NAME})
ament_export_targets(export_${PROJECT_NAME})

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
