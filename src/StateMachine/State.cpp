#include "State.h"
#include "MainStateMachine.h"

State::State(MainStateMachine* msm) : mStateMachine(msm)
{
}

State::~State()
{
}

void State::requestStateChange(MainStates::State aState)
{
    mStateMachine->changeState(aState);
}

std::shared_ptr<Vehicle> State::getVehicle()
{
    return mStateMachine->getVehicle();
}