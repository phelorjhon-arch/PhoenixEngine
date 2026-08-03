#include "Core/Logger.hpp"
#include <iostream>

#if defined(__ANDROID__)
#include <android/log.h>
#define LOG_TAG "PhoenixEngine"
#endif

namespace PHX {

void Logger::Log(LogLevel level, const std::string& message) {
#if defined(__ANDROID__)
    android_LogPriority priority = ANDROID_LOG_INFO;
    switch (level) {
        case LogLevel::Info:    priority = ANDROID_LOG_INFO; break;
        case LogLevel::Warning: priority = ANDROID_LOG_WARN; break;
        case LogLevel::Error:   priority = ANDROID_LOG_ERROR; break;
        case LogLevel::Debug:   priority = ANDROID_LOG_DEBUG; break;
    }
    __android_log_print(priority, LOG_TAG, "%s", message.c_str());
#else
    const char* prefix = "[INFO]";
    switch (level) {
        case LogLevel::Warning: prefix = "[WARN]"; break;
        case LogLevel::Error:   prefix = "[ERROR]"; break;
        case LogLevel::Debug:   prefix = "[DEBUG]"; break;
        default: break;
    }
    std::cout << prefix << " " << message << std::endl;
#endif
}

void Logger::Info(const std::string& message)  { Log(LogLevel::Info, message); }
void Logger::Warn(const std::string& message)  { Log(LogLevel::Warning, message); }
void Logger::Error(const std::string& message) { Log(LogLevel::Error, message); }
void Logger::Debug(const std::string& message) { Log(LogLevel::Debug, message); }

} // namespace PHX
