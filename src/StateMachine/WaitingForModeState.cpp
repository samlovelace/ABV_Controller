#include "WaitingForModeState.h"
#include <stdio.h>

WaitingForModeState::WaitingForModeState(MainStateMachine* msm) : State(msm)
{
}

WaitingForModeState::~WaitingForModeState()
{

}

void WaitingForModeState::update()
{
    std::shared_ptr<Vehicle> vehicle = getVehicle();

    if(!vehicle->isModeCommandRecvd())
    {
        return;
    }

    ABV_MODE_COMMAND mode = vehicle->getCommandMode(); 

    if(ABV_MODE_COMMAND::POSE == mode)
    {
        requestStateChange(MainStates::State::WAITING_FOR_POSE_COMMAND);
        return; 
    }
    else if(ABV_MODE_COMMAND::THRUSTERS == mode)
    {
        requestStateChange(MainStates::State::WAITING_FOR_THRUSTER_COMMAND);
        return; 
    }

}
