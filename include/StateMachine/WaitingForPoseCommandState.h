#ifndef WAITINGFORPOSECOMMANDSTATE_H
#define WAITINGFORPOSECOMMANDSTATE_H

#include "State.h"

class WaitingForPoseCommandState : public State
{
public:
    WaitingForPoseCommandState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv);
    ~WaitingForPoseCommandState();

    void update() override;

private:
    std::shared_ptr<Vehicle> mVehicle; 
};
#endif
