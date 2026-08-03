#pragma once

#include <string>

namespace PHX {

enum class LogLevel {
    Info,
    Warning,
    Error,
    Debug
};

class Logger {
public:
    static void Log(LogLevel level, const std::string& message);
    static void Info(const std::string& message);
    static void Warn(const std::string& message);
    static void Error(const std::string& message);
    static void Debug(const std::string& message);
};

} // namespace PHX
