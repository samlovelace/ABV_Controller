#ifndef INITIALIZINGSTATE_H
#define INITIALIZINGSTATE_H

#include "State.h"
#include "StateMachine.h"

class InitializingState : public State
{
public:
    InitializingState(StateMachine* sm, std::shared_ptr<Vehicle> abv);
    ~InitializingState(); 

    void update() override; 

    bool isInitialized() { std::scoped_lock lock(mInitializedMutex); return mInitialized; }
    void setInitialized(bool aFlag) {std::scoped_lock lock(mInitializedMutex); mInitialized = aFlag;}
    
private:
    std::shared_ptr<Vehicle> mVehicle; 

    int mCount;
    bool mInitialized;
    std::mutex mInitializedMutex; 
};
#endif