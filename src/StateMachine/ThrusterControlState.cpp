#include "ThrusterControlState.h"
#include "WaitingForThrusterCommandState.h"
#include "ExecutingThrusterCommandState.h"

ThrusterControlState::ThrusterControlState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), StateMachine(abv)
{
    mStates.push_back(new WaitingForThrusterCommandState(this, abv));
    mStates.push_back(new ExecutingThrusterCommandState(this, abv));
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