
#ifndef MAINSTATEMACHINE_H
#define MAINSTATEMACHINE_H

#include <vector>
#include "State.h"
#include "StateEnum.h"
#include "Vehicle.h"

class MainStateMachine
{
public:
    MainStateMachine(std::shared_ptr<Vehicle> abv);
    ~MainStateMachine();

    void run(); 
    void changeState(MainStates::State aState);

    std::shared_ptr<Vehicle> getVehicle() { return mVehicle; }

private:
    std::vector<State*> mStates;
    int mCurrentState;
    std::shared_ptr<Vehicle> mVehicle;
};

#endif