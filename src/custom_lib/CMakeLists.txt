cmake_minimum_required(VERSION 3.8)
project(custom_lib)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#########   config   #########

set(DEPS
  custom_msgs
)

set(NODES
  vehicle_node
)

##############################

# package dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
foreach(dep IN LISTS DEPS)
  find_package(${dep} REQUIRED)
endforeach()

# custom library generation
foreach(node IN LISTS NODES)
  list(APPEND NODE_FILES src/${node}.cpp)
endforeach()
add_library(lib SHARED ${NODE_FILES})
target_compile_features(lib PUBLIC 
  c_std_99 cxx_std_17
)
target_include_directories(lib PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
  $<INSTALL_INTERFACE:include>
)
target_compile_options(lib PUBLIC -Wall)
ament_target_dependencies(lib rclcpp ${DEPS})

install(
  DIRECTORY include/ 
  DESTINATION include
)
install(
  TARGETS lib
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_libraries(lib)
ament_export_targets(export_${PROJECT_NAME})

ament_package()