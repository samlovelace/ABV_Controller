#include "State.h"
#include "MainStateMachine.h"

class ThrusterControlState : public State, public StateMachine
{
public:
    ThrusterControlState(StateMachine* sm, std::shared_ptr<Vehicle> abv);
    ~ThrusterControlState();

    void update(); 
private:
    /* data */

};

