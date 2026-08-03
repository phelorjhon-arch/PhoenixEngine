#include "Game/GameVersion.hpp"
#include "Game/ProcMapsReader.hpp"

namespace PHX {

GTAVersion GameVersion::DetectVersion() {
    uintptr_t libGTASABase = ProcMapsReader::GetModuleBase("libGTASA.so");
    if (libGTASABase != 0) {
        return GTAVersion::GTA_SA_2_00;
    }
    return GTAVersion::Unknown;
}

std::string GameVersion::GetVersionName(GTAVersion version) {
    switch (version) {
        case GTAVersion::GTA_SA_2_00: return "GTA:SA v2.00";
        case GTAVersion::GTA_SA_2_10: return "GTA:SA v2.10";
        default: return "Unknown";
    }
}

} // namespace PHX
