#include "State.h"
#include "MainStateMachine.h"

State::State(MainStateMachine* msm) : mStateMachine(msm)
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
    return mStateMachine->getVehicle();
}