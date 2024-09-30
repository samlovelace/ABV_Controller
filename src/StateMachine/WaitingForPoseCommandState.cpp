
#include "WaitingForPoseCommandState.h"


WaitingForPoseCommandState::WaitingForPoseCommandState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm), mVehicle(abv)
{
}

WaitingForPoseCommandState::~WaitingForPoseCommandState()
{
}

void WaitingForPoseCommandState::update()
{
    if(!mVehicle->isPoseCommandRecvd())
    {
        return; 
    }
    else
    {
        requestStateChange(PoseControlStates::EXECUTING_POSE_COMMAND); 
        return; 
    }
}