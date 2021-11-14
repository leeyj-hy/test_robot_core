cmake_minimum_required(VERSION 3.0.2)
project(test_robot_core)


find_package(catkin REQUIRED COMPONENTS
  fiducial_msgs
  roscpp
  std_msgs
)

# find_package(Boost REQUIRED COMPONENTS system)

# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

# generate_messages(
#   DEPENDENCIES
#   fiducial_msgs#   std_msgs
# )


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_robot_core
#  CATKIN_DEPENDS fiducial_msgs roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/test_robot_core.cpp
# )

# add_executable(${PROJECT_NAME}_node src/test_robot_core_node.cpp)

# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )