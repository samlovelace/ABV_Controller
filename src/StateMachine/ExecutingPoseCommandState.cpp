
#include "ExecutingPoseCommandState.h"


ExecutingPoseCommandState::ExecutingPoseCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), mVehicle(abv)
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

