#include <memory>
#include "MainStateMachine.h"
#include "Vehicle.h"
#include <rclcpp/rclcpp.hpp>
#include "ABV_Logger.h"

// Signal handler function
void handleSigint(int signal) {
    std::cout << "\nCaught SIGINT (Ctrl+C). Exiting gracefully..." << std::endl;
    // Perform any cleanup here if needed
    exit(0); // Exit the program
}

int main()
{
    // Register the signal handler
    std::signal(SIGINT, handleSigint);

    // initialize the file and console logger
    createLogger(); 

    // Initialize ROS2
    rclcpp::init(0, nullptr);

    // The main vehicle object
    std::shared_ptr<Vehicle> abv = std::make_shared<Vehicle>();

    // The main state machine
    MainStateMachine* stateMachine = new MainStateMachine(abv);
    
    // run the state machine
    stateMachine->run();

    // shut it all down
    delete stateMachine;
    rclcpp::shutdown();

    return 0;
}