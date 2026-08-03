#include "Game/MemoryMap.hpp"

namespace PHX {

MemoryMap& MemoryMap::Instance() {
    static MemoryMap instance;
    return instance;
}

void MemoryMap::Refresh() {
    m_entries = ProcMapsReader::Read();
}

} // namespace PHX
