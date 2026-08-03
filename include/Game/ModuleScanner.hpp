#pragma once

#include <string>
#include <uintptr_t.h>

namespace PHX {

class ModuleScanner {
public:
    static uintptr_t ScanPattern(uintptr_t base, size_t size, const char* pattern, const char* mask);
};

} // namespace PHX
