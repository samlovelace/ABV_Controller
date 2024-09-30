
#include "InitializingState.h"
#include <stdio.h>
#include "plog/Log.h"

InitializingState::InitializingState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), mVehicle(abv), mCount(0), mInitialized(false)
{


}

InitializingState::~InitializingState()
{
}


void InitializingState::update()
{
    PLOG_INFO << "[MSM] Initializing the main state machine."; // setup rclcpp 
    
    // setup other things.... 
    // Setup other things...
    
    if(isInitialized())
    {
        requestStateChange(MainStates::State::WAITING_FOR_MODE);
    }
    else
    {
        mInitialized = true; 
    }
}