#include "State.h"

class WaitingForThrusterCommandState : public State
{

public:
    WaitingForThrusterCommandState(MainStateMachine* msm, std::shared_ptr<Vehicle> abv);
    ~WaitingForThrusterCommandState();

    void update(); 

private:
    std::shared_ptr<Vehicle> mVehicle; 

};

