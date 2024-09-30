
#include "WaitingForPoseCommandState.h"
#include "plog/Log.h"

WaitingForPoseCommandState::WaitingForPoseCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), mVehicle(abv)
{
}

WaitingForPoseCommandState::~WaitingForPoseCommandState()
{
}

void WaitingForPoseCommandState::update()
{
    PLOG_WARNING << "WaitingForPoseCommandState update()";

    if(!mVehicle->isPoseCommandRecvd())
    {
        return; 
    }
    else
    {
        PLOG_WARNING << "Requesting state change to EXECUTING_POSE_COMMAND";
        requestStateChange(PoseControlStates::EXECUTING_POSE_COMMAND); 
        return; 
    }
}