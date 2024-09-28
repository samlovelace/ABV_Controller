#ifndef WAITINGFORMODESTATE_H
#define WAITINGFORMODESTATE_H

#include "State.h"

class WaitingForModeState : public State
{
public:
    WaitingForModeState(MainStateMachine* msm);
    ~WaitingForModeState();

    void update() override;

private:
    /* data */

};
#endif

