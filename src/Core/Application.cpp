#include "Core/Application.hpp"
#include "Core/Logger.hpp"
#include "Core/Config.hpp"
#include "Core/Engine.hpp"

namespace PHX {

Application::Application() = default;
Application::~Application() {
    Shutdown();
}

bool Application::Initialize(const std::string& configPath) {
    m_configPath = configPath;
    Logger::Info("Initializing Phoenix Application with config: " + configPath);

    if (!Config::Instance().LoadFromFile(configPath)) {
        Logger::Warn("Failed to load config file, falling back to default settings.");
    }

    if (!InitializeEngine()) {
        Logger::Error("Failed to initialize Phoenix Engine core.");
        return false;
    }

    m_isRunning = true;
    return true;
}

void Application::Run() {
    Logger::Info("Phoenix Application loop started.");
}

void Application::Shutdown() {
    if (m_isRunning) {
        ShutdownEngine();
        m_isRunning = false;
        Logger::Info("Phoenix Application shut down successfully.");
    }
}

} // namespace PHX
