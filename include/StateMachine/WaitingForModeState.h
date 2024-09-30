#ifndef WAITINGFORMODESTATE_H
#define WAITINGFORMODESTATE_H

#include "State.h"

class WaitingForModeState : public State
{
public:
    WaitingForModeState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv);
    ~WaitingForModeState();

    void update() override;

private:
    std::shared_ptr<Vehicle> mVehicle; 

};
#endif

