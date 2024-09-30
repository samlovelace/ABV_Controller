#include "PoseControlState.h"
#include "WaitingForPoseCommandState.h"
#include "ExecutingPoseCommandState.h"

PoseControlState::PoseControlState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), StateMachine(abv)
{
    mStates.push_back(new WaitingForPoseCommandState(this, abv));
    mStates.push_back(new ExecutingPoseCommandState(this, abv));

    mCurrentState = 0; 
} 

PoseControlState::~PoseControlState()
{
}

void PoseControlState::update()
{
    mStates.at(mCurrentState)->update(); 

    if(mCurrentState == PoseControlStates::DONE)
    {
        // exit out of pose control state machine
        requestStateChange(MainStates::INITIALIZING); 
    }
}
