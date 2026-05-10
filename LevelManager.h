#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "Level.h"

class LevelManager {
    std::vector<std::string> levelFiles;
    std::string levelsDir = "resources/levels";

public:
    void discoverLevels();
    const std::vector<std::string>& getLevels() const;
    std::string getLevelPath(const std::string& filename) const;
    std::string getDisplayName(const std::string& filename) const;
};
