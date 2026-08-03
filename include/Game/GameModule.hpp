#pragma once

#include <string>
#include <uintptr_t.h>

namespace PHX {

class GameModule {
public:
    GameModule(std::string name);
    
    bool Load();
    uintptr_t GetBaseAddress() const { return m_baseAddress; }
    const std::string& GetName() const { return m_name; }

private:
    std::string m_name;
    uintptr_t m_baseAddress{0};
};

} // namespace PHX
