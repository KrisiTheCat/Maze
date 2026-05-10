#include "../World.h"
#include "objects/Player.h"
#include "objects/Enemy.h"
#include "objects/Wall.h"
#include "objects/Empty.h"
#include "objects/Key.h"
#include "objects/Smoke.h"
#include "objects/Portal.h"
#include "objects/Chaser.h"
#include "objects/Slime.h"

World::World() : grid(LEVEL_H, std::vector<Object*>(LEVEL_W)), player(nullptr) {}

World& World::getInstance() {
    static World instance;
    return instance;
}

void World::init() {
    const char* mazeLayout[LEVEL_H] = {
        "111111111111111111",
        "1P0KM10001000000E1",
        "111101010101111101",
        "100000010001000001",
        "101111111111011111",
        "101000H00000010001",
        "101011111111110101",
        "10101000V000010101",
        "101010111111010101",
        "100010100M01010101",
        "111110101101010101",
        "100000101001010001",
        "101111101111011111",
        "1K0000000E000000X1",
        "111111111111111111"
    };

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            char tile = mazeLayout[r][c];
            switch (tile) {
                case '1': grid[r][c] = new Wall(); break;
                case 'P': player = new Player(c, r); grid[r][c] = player; break;
                case 'E': {
                    auto* chaser = new Chaser(c, r);
                    enemies.push_back(chaser);
                    grid[r][c] = chaser;
                    break;
                }
                case 'H': {
                    auto* slime = new Slime(c, r, 1, 0);
                    enemies.push_back(slime);
                    grid[r][c] = slime;
                    break;
                }
                case 'V': {
                    auto* slime = new Slime(c, r, 0, 1);
                    enemies.push_back(slime);
                    grid[r][c] = slime;
                    break;
                }
                case 'K': grid[r][c] = new Key(); break;
                case 'M': grid[r][c] = new Smoke(); break;
                case 'X': grid[r][c] = new Portal(); break;
                default:  grid[r][c] = new Empty(); break;
            }
        }
    }
}

void World::set(int x, int y, Object* obj) {
    if (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size()) {
        grid[y][x] = obj;
    }
}

Object* World::get(int x, int y) {
    if (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size()) {
        return grid[y][x];
    }
    return nullptr;
}

void World::cleanup() {
    for (auto& row : grid) {
        for (auto* obj : row) {
            delete obj;
        }
    }
}

const std::vector<std::vector<Object*>>& World::getGrid() const {
    return grid;
}

Player* World::getPlayer() const {
    return player;
}

const std::vector<Enemy*>& World::getEnemies() const {
    return enemies;
}