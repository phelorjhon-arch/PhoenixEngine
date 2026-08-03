#pragma once

#include <string>
#include <vector>
#include <uintptr_t.h>

namespace PHX {

struct MapEntry {
    uintptr_t startAddress;
    uintptr_t endAddress;
    std::string permissions;
    std::string path;
};

class ProcMapsReader {
public:
    static std::vector<MapEntry> Read();
    static uintptr_t GetModuleBase(const std::string& moduleName);
};

} // namespace PHX
