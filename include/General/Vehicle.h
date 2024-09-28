
#include "RosTopicManager.h"

class Vehicle
{
public:
    Vehicle(Vehicle* abv);
    ~Vehicle();

    void modeCommandCallback(const std_msgs::msg::String::SharedPtr msg);

    //* Getters and Setters *//
    std::string getCommandMode()
    {
        std::scoped_lock lock(mModeMutex);
        return mCommandMode;
    }

    bool isModeCommandRecvd()
    {
        std::scoped_lock lock(mModeMutex);
        return mModeCommandRecvd;
    }

private:
    RosTopicManager* mTopicManager;
    std::string mCommandMode;
    std::mutex mModeMutex;
    bool mModeCommandRecvd;

};
