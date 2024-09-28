
#include "MainStateMachine.h"
#include "InitializingState.h"
#include "WaitingForModeState.h"
#include "WaitingForPoseCommandState.h"
#include <thread>
#include <stdio.h>

MainStateMachine::MainStateMachine(std::shared_ptr<Vehicle> abv) : mVehicle(abv)
{
    mCurrentState = 0; 
    mStates.push_back(new InitializingState(this));
    mStates.push_back(new WaitingForModeState(this));
    mStates.push_back(new WaitingForPoseCommandState(this));
}

MainStateMachine::~MainStateMachine()
{
    for (int i = 0; i < mStates.size(); i++)
    {
        delete mStates[i];
    }
}

void MainStateMachine::run()
{
    bool done = false; 

    while(!done)
    {
        mStates.at(mCurrentState)->update();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    mStates[mCurrentState]->update();
}

void MainStateMachine::changeState(MainStates::State aState)
{
    printf("Changing state from %s to %s\n", MainStates::names[mCurrentState], MainStates::names[static_cast<int>(aState)]);
    mCurrentState = static_cast<int>(aState);
}