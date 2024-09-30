#include "StateMachine.h"

StateMachine::StateMachine(/* args */)
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

