#include "StateMachine.h"

StateMachine::StateMachine(std::shared_ptr<Vehicle> abv) : mVehicle(abv)
{
    mCurrentState = 0; 
}

StateMachine::~StateMachine()
{
}

void StateMachine::setState(unsigned int s)
{
    if(s < mStates.size())
    {
        mCurrentState = s; 
    }
}

unsigned int StateMachine::getState(){return mCurrentState;}

