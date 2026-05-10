#include "Level.h"
#include <fstream>
#include <string>
#include "objects/Wall.h"
#include "objects/Empty.h"
#include "objects/Key.h"
#include "objects/Smoke.h"
#include "objects/Portal.h"

Level::Level() : tiles(LEVEL_H) {
    for (int i = 0; i < LEVEL_H; ++i) {
        tiles[i].resize(LEVEL_W);
    }
}

void Level::init(const char* layout[LEVEL_H]) {
    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            switch (layout[r][c]) {
                case '1': tiles[r][c] = std::make_unique<Wall>();   break;
                case 'K': tiles[r][c] = std::make_unique<Key>();    break;
                case 'M': tiles[r][c] = std::make_unique<Smoke>();  break;
                case 'X': tiles[r][c] = std::make_unique<Portal>(); break;
                default:  tiles[r][c] = std::make_unique<Empty>();  break;
            }
        }
    }
}

bool Level::load(const std::string& filename, std::vector<EntityData>& entities) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    entities.clear();
    std::string line;
    for (int r = 0; r < LEVEL_H; ++r) {
        if (!std::getline(file, line)) break;
        for (int c = 0; c < LEVEL_W && c < (int)line.length(); ++c) {
            char ch = line[c];
            switch (ch) {
                case '1': tiles[r][c] = std::make_unique<Wall>();   break;
                case 'K': tiles[r][c] = std::make_unique<Key>();    break;
                case 'M': tiles[r][c] = std::make_unique<Smoke>();  break;
                case 'X': tiles[r][c] = std::make_unique<Portal>(); break;
                case 'P':
                case 'E':
                case 'H':
                case 'V':
                    entities.push_back({ch, c, r});
                    tiles[r][c] = std::make_unique<Empty>();
                    break;
                case '0':
                case ' ':
                default:  tiles[r][c] = std::make_unique<Empty>();  break;
            }
        }
    }
    return true;
}

bool Level::write(const std::string& filename, const std::vector<EntityData>& entities) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    std::vector<std::string> layout(LEVEL_H, std::string(LEVEL_W, '0'));

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            SpriteID id = tiles[r][c]->getID();
            switch (id) {
                case SP_WALL:   layout[r][c] = '1'; break;
                case SP_KEY:    layout[r][c] = 'K'; break;
                case SP_SMOKE:  layout[r][c] = 'M'; break;
                case SP_PORTAL: layout[r][c] = 'X'; break;
                default:        layout[r][c] = '0'; break;
            }
        }
    }

    for (const auto& entity : entities) {
        if (entity.y >= 0 && entity.y < LEVEL_H && entity.x >= 0 && entity.x < LEVEL_W) {
            layout[entity.y][entity.x] = entity.type;
        }
    }

    for (const auto& line : layout) {
        file << line << '\n';
    }
    return true;
}

void Level::set(int x, int y, std::unique_ptr<Object> obj) {
    if (y >= 0 && y < (int)tiles.size() && x >= 0 && x < (int)tiles[0].size()) {
        tiles[y][x] = std::move(obj);
    }
}

Object* Level::get(int x, int y) const {
    if (y >= 0 && y < (int)tiles.size() && x >= 0 && x < (int)tiles[0].size()) {
        return tiles[y][x].get();
    }
    return nullptr;
}
