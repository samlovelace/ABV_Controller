#include "WaitingForThrusterCommandState.h"

WaitingForThrusterCommandState::WaitingForThrusterCommandState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv) : State(msm), mVehicle(abv)
{
}

WaitingForThrusterCommandState::~WaitingForThrusterCommandState()
{
}

void WaitingForThrusterCommandState::update()
{

}