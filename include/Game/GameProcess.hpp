#pragma once

#include <sys/types.h>

namespace PHX {

class GameProcess {
public:
    static pid_t GetCurrentPID();
    static bool IsAlive();
};

} // namespace PHX
