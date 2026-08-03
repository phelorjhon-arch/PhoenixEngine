#include "Core/BuildInfo.hpp"

namespace PHX {

static const char* g_version = "2.0.0-final";
static const char* g_buildDate = __DATE__ " " __TIME__;

#if defined(__ANDROID__)
static const char* g_platform = "Android OS";
#elif defined(__linux__)
static const char* g_platform = "Linux";
#else
static const char* g_platform = "Unknown Platform";
#endif

const char* BuildVersion() {
    return g_version;
}

BuildDetails GetBuildDetails() {
    return BuildDetails{ g_version, g_buildDate, g_platform };
}

} // namespace PHX
