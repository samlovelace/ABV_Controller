#ifndef STATEENUM_H
#define STATEENUM_H
#include <string>


namespace MainStates
{
    enum State
    {
        INITIALIZING,
        WAITING_FOR_MODE, 
        POSE_CONTROL, 
        THRUSTER_CONTROL
    };

    inline const char* names[] =
    {
        "Initializing",
        "WaitingForMode", 
        "PoseControl", 
        "ThrusterControl"
    };
}

namespace PoseControlStates
{
    enum States
    {
        WAITING_FOR_POSE_COMMAND,
        EXECUTING_POSE_COMMAND, 
        DONE
    };

    inline const char* names[] = 
    {
        "WaitingForPoseCommand", 
        "ExecutingPoseCommand",
        "Done"
    };
}

namespace ThrusterControlStates
{
    enum States
    {
        WAITING_FOR_THRUSTER_COMMAND, 
        EXECUTING_THRUSTER_COMMAND, 
        DONE
    };

    inline const char* names[] = 
    {
        "WaitingForThrusterCommand", 
        "ExecutingThrusterCommand", 
        "Done"
    };
}

#endif