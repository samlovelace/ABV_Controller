#include "ExecutingThrusterCommandState.h"

ExecutingThrusterCommandState::ExecutingThrusterCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), mVehicle(abv)
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