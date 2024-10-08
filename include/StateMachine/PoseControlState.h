#ifndef POSECONTROLSTATE_H 
#define POSECONTROLSTATE_H

#include "State.h"
#include "StateMachine.h"  

class PoseControlState : public State, StateMachine
{
public:
    PoseControlState(StateMachine* sm, std::shared_ptr<Vehicle> abv);
    ~PoseControlState();

    // state functions 
    void update(); 

private:
    /* data */

};

#endif

