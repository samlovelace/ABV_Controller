#include "State.h"

class WaitingForThrusterCommandState : public State
{

public:
    WaitingForThrusterCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv);
    ~WaitingForThrusterCommandState();

    void update(); 

private:
    std::shared_ptr<Vehicle> mVehicle; 

};

