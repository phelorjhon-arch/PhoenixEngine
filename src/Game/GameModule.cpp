#include "Game/GameModule.hpp"
#include "Game/ProcMapsReader.hpp"

namespace PHX {

GameModule::GameModule(std::string name) : m_name(std::move(name)) {}

bool GameModule::Load() {
    m_baseAddress = ProcMapsReader::GetModuleBase(m_name);
    return m_baseAddress != 0;
}

} // namespace PHX
