#include "State.h"
#include "MainStateMachine.h"

State::State(StateMachine* sm) : mStateMachine(sm)
{
}

State::~State()
{
}

void State::requestStateChange(unsigned int toState)
{
    mStateMachine->setState(toState);
}

std::shared_ptr<Vehicle> State::getVehicle()
{
    // i dont like this 
    return mStateMachine->mVehicle;
}