#include "Game/LibraryFinder.hpp"
#include "Game/ProcMapsReader.hpp"

namespace PHX {

uintptr_t LibraryFinder::FindLibrary(const std::string& libName) {
    return ProcMapsReader::GetModuleBase(libName);
}

} // namespace PHX
