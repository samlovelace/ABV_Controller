
#include "MainStateMachine.h"
#include "InitializingState.h"
#include "WaitingForModeState.h"
#include "PoseControlState.h"
#include "ThrusterControlState.h"
#include <thread>
#include <stdio.h>
#include "plog/Log.h"

MainStateMachine::MainStateMachine(std::shared_ptr<Vehicle> abv) : StateMachine(abv)
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
    PLOG_INFO << "[MSM] Changing state from " << MainStates::names[mCurrentState] << " to " << MainStates::names[s];
    StateMachine::setState(s); 
}