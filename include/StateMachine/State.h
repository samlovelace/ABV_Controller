#ifndef STATE_H
#define STATE_H

#include <memory>
#include "Vehicle.h"
#include "StateEnum.h"

class MainStateMachine; 

class State
{
public:
    State(MainStateMachine* msm);
    virtual ~State();

    virtual void update() = 0;

    void requestStateChange(MainStates::State aState);
    std::shared_ptr<Vehicle> getVehicle();

private:
    MainStateMachine* mStateMachine; 

};
#endif
