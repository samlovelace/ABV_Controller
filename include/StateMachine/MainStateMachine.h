
#ifndef MAINSTATEMACHINE_H
#define MAINSTATEMACHINE_H

#include "StateMachine.h"
#include <vector>
#include "State.h"
#include "StateEnum.h"
#include "Vehicle.h"

class MainStateMachine : public StateMachine
{
public:
    MainStateMachine(std::shared_ptr<Vehicle> abv);
    ~MainStateMachine();

    void run(); 
    void setState(unsigned int s); 

    std::shared_ptr<Vehicle> getVehicle() { return mVehicle; }

private:
    std::shared_ptr<Vehicle> mVehicle;
};

#endif