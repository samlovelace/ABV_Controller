
#include "Vehicle.h"
#include "plog/Log.h"

Vehicle::Vehicle() : mTopicManager(new RosTopicManager())
{
    mTopicManager->createModeSubscriber("abv_mode_command", std::bind(&Vehicle::modeCommandCallback, this, std::placeholders::_1));
    mTopicManager->createInputSubscriber("abv_control_input", std::bind(&Vehicle::controlInputCallback, this, std::placeholders::_1));
    mTopicManager->createPublisher<std_msgs::msg::String>("abv_mode_response");
    mTopicManager->spinNode(); 
}

Vehicle::~Vehicle()
{
}

void Vehicle::modeCommandCallback(const std_msgs::msg::String::SharedPtr msg)
{
    mCommandMode = toEnum(msg->data);
    setModeCommandRecvd(true); 

    // respond 
    std_msgs::msg::String response;
    response.data = "ack";
    mTopicManager->publishMessage("abv_mode_response", response);
}

void Vehicle::controlInputCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    // do something with the control input
    setPoseCommandRecvd(true);
    PLOG_INFO << "Control input received" << msg->data; 
}

Vehicle::Mode Vehicle::toEnum(std::string aMode)
{
    Vehicle::Mode modeToReturn; 

    if("pose" == aMode)
    {
        modeToReturn = Vehicle::Mode::POSE; 
    }
    else if ("thruster" == aMode)
    {
        modeToReturn = Vehicle::Mode::THRUSTER; 
    }
    else
    {
        printf("Unsupported type > %d\n", static_cast<int>(Vehicle::Mode::NUM_TYPES));
    }

    return modeToReturn; 
}
