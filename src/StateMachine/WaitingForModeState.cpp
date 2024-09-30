#include "WaitingForModeState.h"
#include <stdio.h>

WaitingForModeState::WaitingForModeState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), mVehicle(abv)
{
}

WaitingForModeState::~WaitingForModeState()
{

}

void WaitingForModeState::update()
{
    if(!mVehicle->isModeCommandRecvd())
    {
        return;
    }

    Vehicle::Mode mode = mVehicle->getCommandMode(); 

    if(Vehicle::Mode::POSE == mode)
    {
        requestStateChange(MainStates::POSE_CONTROL);
        return; 
    }
    else if(Vehicle::Mode::THRUSTER == mode)
    {
        requestStateChange(MainStates::THRUSTER_CONTROL);
        return; 
    }

}
