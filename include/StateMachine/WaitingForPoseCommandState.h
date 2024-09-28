#ifndef WAITINGFORPOSECOMMANDSTATE_H
#define WAITINGFORPOSECOMMANDSTATE_H

#include "State.h"

class WaitingForPoseCommandState : public State
{
private:
    /* data */
public:
    WaitingForPoseCommandState(MainStateMachine* msm);
    ~WaitingForPoseCommandState();
};
#endif
