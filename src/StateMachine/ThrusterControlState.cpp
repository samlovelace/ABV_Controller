#include "ThrusterControlState.h"
#include "WaitingForThrusterCommandState.h"
#include "ExecutingThrusterCommandState.h"

ThrusterControlState::ThrusterControlState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm)
{
    mStates.push_back(new WaitingForThrusterCommandState(msm, abv));
}

ThrusterControlState::~ThrusterControlState()
{
}

void ThrusterControlState::update()
{
    mStates.at(mCurrentState)->update(); 

    if(mCurrentState == ThrusterControlStates::DONE)
    {
        // exit out of thruster control state 
    }

}