
#include "InitializingState.h"
#include <stdio.h>

InitializingState::InitializingState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm), mVehicle(abv), mCount(0), mInitialized(false)
{


}

InitializingState::~InitializingState()
{
}


void InitializingState::update()
{
    // setup rclcpp 
    // setup other things.... 
    
    if(isInitialized())
    {
        requestStateChange(MainStates::State::WAITING_FOR_MODE);
    }
    else
    {
        mInitialized = true; 
        printf("Initializing...\n");
    }
}