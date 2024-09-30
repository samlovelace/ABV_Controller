#ifndef EXECUTINGTHRUSTERCOMMANDSTATE_H
#define EXECUTINGTHRUSTERCOMMANDSTATE_H

#include "State.h"
#include "Vehicle.h"

class ExecutingThrusterCommandState : public State
{
public:
    ExecutingThrusterCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv);
    ~ExecutingThrusterCommandState();

    void update(); 

private:
    std::shared_ptr<Vehicle> mVehicle; 

};

#endif
