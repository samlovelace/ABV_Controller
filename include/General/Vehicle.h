#ifndef VEHICLE_H
#define VEHICLE_H

#include "RosTopicManager.h"

class Vehicle
{
public:
    Vehicle();
    ~Vehicle();

    enum class Mode
    {
        POSE, 
        THRUSTER, 
        NUM_TYPES
    };

    void modeCommandCallback(const std_msgs::msg::String::SharedPtr msg);

    //* Getters and Setters *//
    Mode getCommandMode(){std::scoped_lock lock(mModeMutex); return mCommandMode;}
    bool isModeCommandRecvd(){std::scoped_lock lock(mModeMutex); return mModeCommandRecvd;}
    void setModeCommandRecvd(bool aFlag){std::scoped_lock lock(mModeMutex); mModeCommandRecvd = aFlag;}
    bool isPoseCommandRecvd() {std::scoped_lock lock(mPoseCommandRecvdMutex); return mPoseCommandRecvd; }

private:

    //* Methods *//
    Mode toEnum(std::string aMode); 


    RosTopicManager* mTopicManager;
    Mode mCommandMode;
    std::mutex mModeMutex;
    bool mModeCommandRecvd;
    bool mPoseCommandRecvd; 
    std::mutex mPoseCommandRecvdMutex; 
    bool mThrusterCommandRecvd; 
    std::mutex mThrusterCommandRecvdMutex; 

};

#endif
