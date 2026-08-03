#pragma once

#include <string>

namespace PHX {

enum class GTAVersion {
    Unknown,
    GTA_SA_2_00,
    GTA_SA_2_10
};

class GameVersion {
public:
    static GTAVersion DetectVersion();
    static std::string GetVersionName(GTAVersion version);
};

} // namespace PHX
