#include "LevelManager.h"
#include <algorithm>

#include "Level.h"
#include "display/Logger.h"
#include "exceptions/LevelValidationExceptions.h"

using namespace std;

namespace fs = filesystem;

void LevelManager::discoverLevels() {
    levelFiles.clear();
    if (!fs::exists(levelsDir)) {
        fs::create_directory(levelsDir);
        return;
    }

    for (const auto& entry : fs::directory_iterator(levelsDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            string filename = entry.path().filename().string();
            string fullPath = getLevelPath(filename);
            try {
                Level::validate(fullPath);
                levelFiles.push_back(filename);
            } catch (const LevelValidationException& e) {
                Logger::warn("Validation failed", e);
            } catch (const exception& e) {
                Logger::error("Unexpected error validating " + filename, e);
            }
        }
    }

    Logger::info(format("Discovered {} valid level(s)", levelFiles.size()));

    sort(levelFiles.begin(), levelFiles.end());
}

const vector<string>& LevelManager::getLevels() const {
    return levelFiles;
}

string LevelManager::getLevelPath(const string& filename) const {
    return levelsDir + "/" + filename;
}

string LevelManager::getDisplayName(const string& filename) const {
    size_t dotPos = filename.find_last_of('.');
    string name = (dotPos != string::npos) ? filename.substr(0, dotPos) : filename;
    replace(name.begin(), name.end(), '_', ' ');
    return name;
}
