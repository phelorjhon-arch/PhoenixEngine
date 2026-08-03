#include "Core/Config.hpp"
#include <fstream>
#include <sstream>

namespace PHX {

Config& Config::Instance() {
    static Config instance;
    return instance;
}

static inline std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    auto end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

bool Config::LoadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;

    std::string line, currentSection = "Global";
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == ';' || line[0] == '#') continue;

        if (line.front() == '[' && line.back() == ']') {
            currentSection = trim(line.substr(1, line.size() - 2));
        } else {
            auto pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = trim(line.substr(0, pos));
                std::string val = trim(line.substr(pos + 1));
                m_data[currentSection][key] = val;
            }
        }
    }
    return true;
}

std::string Config::GetString(const std::string& section, const std::string& key, const std::string& defaultValue) const {
    auto secIt = m_data.find(section);
    if (secIt != m_data.end()) {
        auto keyIt = secIt->second.find(key);
        if (keyIt != secIt->second.end()) {
            return keyIt->second;
        }
    }
    return defaultValue;
}

int Config::GetInt(const std::string& section, const std::string& key, int defaultValue) const {
    std::string val = GetString(section, key);
    if (val.empty()) return defaultValue;
    try { return std::stoi(val); } catch (...) { return defaultValue; }
}

bool Config::GetBool(const std::string& section, const std::string& key, bool defaultValue) const {
    std::string val = GetString(section, key);
    if (val.empty()) return defaultValue;
    return (val == "1" || val == "true" || val == "TRUE" || val == "yes");
}

} // namespace PHX
