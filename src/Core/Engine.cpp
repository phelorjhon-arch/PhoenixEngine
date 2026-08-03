#include "Core/Engine.hpp"
#include "Core/Logger.hpp"
#include "Hook/RenderHook.hpp"

namespace PHX {

static bool g_engineInitialized = false;

bool InitializeEngine() {
    if (g_engineInitialized) return true;

    Logger::Info("[Phoenix Engine] Initializing core modules...");

    if (!InstallRenderHooks()) {
        Logger::Error("[Phoenix Engine] Failed to install render hooks!");
        return false;
    }

    g_engineInitialized = true;
    Logger::Info("[Phoenix Engine] Engine core initialized successfully.");
    return true;
}

void ShutdownEngine() {
    if (!g_engineInitialized) return;
    Logger::Info("[Phoenix Engine] Shutting down engine core...");
    g_engineInitialized = false;
}

bool IsEngineInitialized() {
    return g_engineInitialized;
}

} // namespace PHX
