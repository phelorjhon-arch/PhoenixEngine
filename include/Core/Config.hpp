#pragma once

#include <string>
#include <unordered_map>

namespace PHX {

class Config {
public:
    static Config& Instance();

    bool LoadFromFile(const std::string& filePath);
    std::string GetString(const std::string& section, const std::string& key, const std::string& defaultValue = "") const;
    int GetInt(const std::string& section, const std::string& key, int defaultValue = 0) const;
    bool GetBool(const std::string& section, const std::string& key, bool defaultValue = false) const;

private:
    Config() = default;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> m_data;
};

} // namespace PHX
