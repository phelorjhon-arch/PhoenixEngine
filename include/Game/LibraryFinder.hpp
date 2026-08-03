#pragma once

#include <string>
#include <uintptr_t.h>

namespace PHX {

class LibraryFinder {
public:
    static uintptr_t FindLibrary(const std::string& libName);
};

} // namespace PHX
