
#include "MainStateMachine.h"
#include "InitializingState.h"
#include "WaitingForModeState.h"
#include "PoseControlState.h"
#include "ThrusterControlState.h"
#include <thread>
#include <stdio.h>

MainStateMachine::MainStateMachine(std::shared_ptr<Vehicle> abv) : mVehicle(abv)
{
    mCurrentState = 0; 
    mStates.push_back(new InitializingState(this, abv));
    mStates.push_back(new WaitingForModeState(this, abv));
    mStates.push_back(new PoseControlState(this, abv)); 
    mStates.push_back(new ThrusterControlState(this, abv));
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
    
}

void MainStateMachine::setState(unsigned int s)
{
    printf("Changing state from %s to %s\n", MainStates::names[mCurrentState], MainStates::names[s]);
    StateMachine::setState(s); 
}