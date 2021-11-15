cmake_minimum_required(VERSION 3.0.2)
project(test_robot_core)


find_package(catkin REQUIRED COMPONENTS
  fiducial_msgs
  geometry_msgs
  robot_msgs
  roscpp
  std_msgs
)

# find_package(Boost REQUIRED COMPONENTS system)

# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_robot_core
#  CATKIN_DEPENDS fiducial_msgs roscpp std_msgs message_generation geometry_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(robot_core src/robot_core.cpp)

add_dependencies(robot_core ${robot_core_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(robot_core
  ${catkin_LIBRARIES}
)

add_executable(marker_dist src/marker_dist.cpp)

add_dependencies(marker_dist ${marker_dist_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(marker_dist
  ${catkin_LIBRARIES}
)

add_executable(ultrasonic_dist src/ultrasonic_dist.cpp)

add_dependencies(ultrasonic_dist ${ultrasonic_dist_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(ultrasonic_dist
  ${catkin_LIBRARIES}
)
