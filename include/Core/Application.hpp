#pragma once

#include <string>
#include <memory>

namespace PHX {

class Application {
public:
    Application();
    ~Application();

    bool Initialize(const std::string& configPath);
    void Run();
    void Shutdown();

    bool IsRunning() const { return m_isRunning; }

private:
    bool m_isRunning{false};
    std::string m_configPath;
};

} // namespace PHX
