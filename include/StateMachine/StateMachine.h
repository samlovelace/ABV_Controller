#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <vector>

class State; 

class StateMachine
{
    friend class State; 

protected: 
    unsigned int mCurrentState; 
    std::vector<State*> mStates; 
    std::shared_ptr<Vehicle> mVehicle;


public:
    StateMachine(std::shared_ptr<Vehicle> abv);
    ~StateMachine();

    void run(); 
    virtual void setState(unsigned int s);
    unsigned int getState(); 
};

#endif
