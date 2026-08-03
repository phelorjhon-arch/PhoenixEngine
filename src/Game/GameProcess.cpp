#include "Game/GameProcess.hpp"
#include <unistd.h>

namespace PHX {

pid_t GameProcess::GetCurrentPID() {
    return getpid();
}

bool GameProcess::IsAlive() {
    return getpid() > 0;
}

} // namespace PHX
