#include <memory>
#include "MainStateMachine.h"
#include "Vehicle.h"
#include <rclcpp/rclcpp.hpp>

int main()
{
    rclcpp::init(0, nullptr);

    std::shared_ptr<Vehicle> abv = std::make_shared<Vehicle>();

    MainStateMachine* stateMachine = new MainStateMachine(abv);
    
    // run the state machine
    stateMachine->run();

    delete stateMachine;

    rclcpp::shutdown();

    return 0;


}