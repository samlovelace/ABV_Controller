
#include "InitializingState.h"
#include <stdio.h>

InitializingState::InitializingState(MainStateMachine* msm) : State(msm), mCount(0), mInitialized(false)
{


}

InitializingState::~InitializingState()
{
}


void InitializingState::update()
{
    // setup rclcpp 
    // setup other things.... 
    
    if(isEverythingInitialized())
    {
        requestStateChange(MainStates::State::WAITING_FOR_MODE);
    }
    else
    {
        mInitialized = true; 
        printf("Initializing...\n");
    }
}