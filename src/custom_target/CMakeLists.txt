cmake_minimum_required(VERSION 3.8)
project(custom_target)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(DEPS
  custom_msgs
  custom_lib
)

set(TARGET_NAME exe)

# package dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
foreach(dep IN LISTS DEPS)
  find_package(${dep} REQUIRED)
endforeach()

add_executable(
  ${TARGET_NAME} 
    src/main.cpp
)
ament_target_dependencies(${TARGET_NAME} rclcpp ${DEPS})
install(TARGETS ${TARGET_NAME} DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()