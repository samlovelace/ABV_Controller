#include "PoseControlState.h"
#include "WaitingForPoseCommandState.h"
#include "ExecutingPoseCommandState.h"

PoseControlState::PoseControlState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm)
{
    mStates.push_back(new WaitingForPoseCommandState(msm, abv));
    mStates.push_back(new ExecutingPoseCommandState(msm, abv));

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
    }
}
