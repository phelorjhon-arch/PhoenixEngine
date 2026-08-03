#pragma once

#include "Game/ProcMapsReader.hpp"
#include <vector>

namespace PHX {

class MemoryMap {
public:
    static MemoryMap& Instance();
    void Refresh();
    const std::vector<MapEntry>& GetEntries() const { return m_entries; }

private:
    MemoryMap() = default;
    std::vector<MapEntry> m_entries;
};

} // namespace PHX
