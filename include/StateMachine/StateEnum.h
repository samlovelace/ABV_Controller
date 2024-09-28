#ifndef STATEENUM_H
#define STATEENUM_H
#include <string>


namespace MainStates
{
    enum class State
    {
        INITIALIZING,
        WAITING_FOR_MODE
    };

    inline const char* names[] =
    {
        "Initializing",
        "WaitingForMode"
    };
}

namespace PoseControllerStates
{
    enum class State
    {
        WAITING_FOR_POSE_COMMAND,
        EXECUTING_POSE_COMMAND
    };
}

#endif