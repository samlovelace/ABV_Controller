
#include "State.h"
#include "Vehicle.h"

class ExecutingPoseCommandState : public State
{
public:
    ExecutingPoseCommandState(StateMachine* sm, std::shared_ptr<Vehicle> abv);
    ~ExecutingPoseCommandState();

    void update(); 

private:
    std::shared_ptr<Vehicle> mVehicle;

};

