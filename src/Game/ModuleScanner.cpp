#include "Game/ModuleScanner.hpp"
#include <cstring>

namespace PHX {

uintptr_t ModuleScanner::ScanPattern(uintptr_t base, size_t size, const char* pattern, const char* mask) {
    size_t patternLen = std::strlen(mask);
    for (size_t i = 0; i < size - patternLen; ++i) {
        bool found = true;
        for (size_t j = 0; j < patternLen; ++j) {
            if (mask[j] != '?' && reinterpret_cast<const char*>(base + i)[j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return base + i;
        }
    }
    return 0;
}

} // namespace PHX
