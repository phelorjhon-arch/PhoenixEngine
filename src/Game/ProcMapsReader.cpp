#include "Game/ProcMapsReader.hpp"
#include <fstream>
#include <sstream>

namespace PHX {

std::vector<MapEntry> ProcMapsReader::Read() {
    std::vector<MapEntry> entries;
    std::ifstream mapsFile("/proc/self/maps");
    if (!mapsFile.is_open()) return entries;

    std::string line;
    while (std::getline(mapsFile, line)) {
        std::istringstream iss(line);
        std::string addrRange, perms, offset, dev, inode, path;
        
        if (iss >> addrRange >> perms >> offset >> dev >> inode) {
            iss >> path; // Path bisa kosong
            
            auto dashPos = addrRange.find('-');
            if (dashPos != std::string::npos) {
                uintptr_t start = std::stoull(addrRange.substr(0, dashPos), nullptr, 16);
                uintptr_t end = std::stoull(addrRange.substr(dashPos + 1), nullptr, 16);
                entries.push_back({ start, end, perms, path });
            }
        }
    }
    return entries;
}

uintptr_t ProcMapsReader::GetModuleBase(const std::string& moduleName) {
    auto entries = Read();
    for (const auto& entry : entries) {
        if (!entry.path.empty() && entry.path.find(moduleName) != std::string::npos) {
            return entry.startAddress;
        }
    }
    return 0;
}

} // namespace PHX
