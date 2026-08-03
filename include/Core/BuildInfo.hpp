#pragma once

namespace PHX {

struct BuildDetails {
    const char* version;
    const char* buildDate;
    const char* targetPlatform;
};

const char* BuildVersion();
BuildDetails GetBuildDetails();

} // namespace PHX
