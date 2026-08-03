#include <cstddef>
#include <cstring>

namespace PHX {

void SafeCopyMemory(void* dest, const void* src, size_t size) {
    if (dest && src && size > 0) {
        std::memcpy(dest, src, size);
    }
}

void SafeSetMemory(void* dest, int value, size_t size) {
    if (dest && size > 0) {
        std::memset(dest, value, size);
    }
}

} // namespace PHX
