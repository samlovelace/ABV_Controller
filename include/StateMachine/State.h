#ifndef STATE_H
#define STATE_H

#include <memory>
#include "Vehicle.h"
#include "StateEnum.h"

class StateMachine; 

class State
{
public:
    State(StateMachine* msm);
    virtual ~State();

    virtual void update() = 0;

    void requestStateChange(unsigned int toState);
    std::shared_ptr<Vehicle> getVehicle();

private:
    StateMachine* mStateMachine; 

};
#endif
