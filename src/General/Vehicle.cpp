
#include "Vehicle.h"

Vehicle::Vehicle(/* args */) : mTopicManager(new RosTopicManager())
{
    mTopicManager->createSubscriber("abv_mode_command", std::bind(&Vehicle::modeCommandCallback, this, std::placeholders::_1));
}

Vehicle::~Vehicle()
{
}

void Vehicle::modeCommandCallback(const std_msgs::msg::String::SharedPtr msg)
{
    std::scoped_lock lock(mModeMutex);
    mCommandMode = msg->data;
    mModeCommandRecvd = true;
}
