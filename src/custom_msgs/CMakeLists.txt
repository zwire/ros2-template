cmake_minimum_required(VERSION 3.8)
project(custom_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#########   config   #########

set(DEPS
  std_msgs
)

set(MSGS 
  VehicleStatus
)

##############################

# package dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
foreach(dep IN LISTS DEPS)
  find_package(${dep} REQUIRED)
endforeach()

# custom message generation
foreach(dep IN LISTS MSGS)
  list(APPEND MSG_FILES msg/${dep}.msg)
endforeach()
rosidl_generate_interfaces(
  ${PROJECT_NAME} ${MSG_FILES}
  DEPENDENCIES ${DEPS}
)
ament_export_dependencies(rosidl_default_runtime)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()