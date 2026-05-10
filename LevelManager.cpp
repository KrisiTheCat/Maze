#include "LevelManager.h"
#include <algorithm>

#include "display/Logger.h"

namespace fs = std::filesystem;

void LevelManager::discoverLevels() {
    levelFiles.clear();
    if (!fs::exists(levelsDir)) {
        fs::create_directory(levelsDir);
        return;
    }

    for (const auto& entry : fs::directory_iterator(levelsDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            levelFiles.push_back(entry.path().filename().string());
        }
    }

    Logger::info(std::format("Discovered {} level(s)", levelFiles.size()));

    std::sort(levelFiles.begin(), levelFiles.end());
}

const std::vector<std::string>& LevelManager::getLevels() const {
    return levelFiles;
}

std::string LevelManager::getLevelPath(const std::string& filename) const {
    return levelsDir + "/" + filename;
}

std::string LevelManager::getDisplayName(const std::string& filename) const {
    size_t dotPos = filename.find_last_of('.');
    if (dotPos != std::string::npos) {
        return filename.substr(0, dotPos);
    }
    return filename;
}
