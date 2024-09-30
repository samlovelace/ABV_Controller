#include "ExecutingThrusterCommandState.h"

ExecutingThrusterCommandState::ExecutingThrusterCommandState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm), mVehicle(abv)
{

}

ExecutingThrusterCommandState::~ExecutingThrusterCommandState()
{

}

void ExecutingThrusterCommandState::update()
{
    // perform thruster control
    printf("ExecutingTHRUSTERCommandState update()\n"); 
}