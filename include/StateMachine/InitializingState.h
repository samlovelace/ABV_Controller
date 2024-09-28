#ifndef INITIALIZINGSTATE_H
#define INITIALIZINGSTATE_H

#include "State.h"

class InitializingState : public State
{
public:
    InitializingState(MainStateMachine* msm);
    ~InitializingState(); 

    void update() override; 

    bool isEverythingInitialized() { return mInitialized; }
    
private:
    int mCount;
    bool mInitialized;
};
#endif