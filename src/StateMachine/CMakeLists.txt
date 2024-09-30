cmake_minimum_required(VERSION 3.8)

set(ABV_STATE_MACHINE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/ExecutingPoseCommandState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ExecutingThrusterCommandState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/InitializingState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MainStateMachine.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PoseControlState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/State.cpp
    ${CMAKE_CURRENT_LIST_DIR}/StateMachine.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ThrusterControlState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/WaitingForModeState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/WaitingForPoseCommandState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/WaitingForThrusterCommandState.cpp    
)