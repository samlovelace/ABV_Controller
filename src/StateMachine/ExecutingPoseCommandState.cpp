
#include "ExecutingPoseCommandState.h"


ExecutingPoseCommandState::ExecutingPoseCommandState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm), mVehicle(abv)
{
}

ExecutingPoseCommandState::~ExecutingPoseCommandState()
{
}

void ExecutingPoseCommandState::update()
{
    // perform feedback control on vehicle pose
    printf("ExecutingPoseCommandState update()\n"); 
}

