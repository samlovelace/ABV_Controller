#include "WaitingForThrusterCommandState.h"

WaitingForThrusterCommandState::WaitingForThrusterCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv) : State(sm), mVehicle(abv)
{
}

WaitingForThrusterCommandState::~WaitingForThrusterCommandState()
{
}

void WaitingForThrusterCommandState::update()
{

}