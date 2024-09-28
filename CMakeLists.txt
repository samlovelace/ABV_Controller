cmake_minimum_required(VERSION 3.8)

project(abv)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Modern way to specify include directories for the project
add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/ABV_Controller.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/StateMachine/MainStateMachine.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/StateMachine/InitializingState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/StateMachine/State.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/StateMachine/WaitingForModeState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/External/ROS/RosTopicManager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/General/Vehicle.cpp
)

# Set include directories for the project
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include/StateMachine
    ${CMAKE_CURRENT_LIST_DIR}/include/External/ROS
    ${CMAKE_CURRENT_LIST_DIR}/include/General
    ${rclcpp_INCLUDE_DIRS}
    ${std_msgs_INCLUDE_DIRS}
)

# Link against ROS 2 libraries (rclcpp and std_msgs)
target_link_libraries(${PROJECT_NAME} PUBLIC ${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES})

# Set the build type to Debug for faster linking (can change to Release later)
set(CMAKE_BUILD_TYPE Debug)

# Disable Link-Time Optimization (LTO) for faster linking
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)
