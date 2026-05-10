#include "GameState.h"
#include "objects/Chaser.h"
#include "objects/Slime.h"
#include "objects/Portal.h"
#include <iostream>

#include "display/Logger.h"
#include "exceptions/UnexpectedCommand.h"
#include "objects/Key.h"
#include "objects/Smoke.h"
#include "objects/Empty.h"

static const char *mazeLayout[LEVEL_H] = {
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

void GameState::win() {
    if (gameOverCallback) gameOverCallback(true);
    running = false;
}

void GameState::lose() {
    if (gameOverCallback) gameOverCallback(false);
    running = false;
}

GameState::GameState() : running(true), collectedKeys(0), totalKeys(0) {
    std::vector<EntityData> entities;
    level.init(mazeLayout);
}

bool GameState::loadLevel(const std::string &filename) {
    std::vector<EntityData> entities;
    if (level.load(filename, entities)) {
        enemies.clear();
        for (const auto &entity: entities) {
            if (entity.type == 'P') player = std::make_unique<Player>(entity.x, entity.y);
            else if (entity.type == 'E' || entity.type == 'H' || entity.type == 'V') {
                std::unique_ptr<Enemy> enemy;
                if (entity.type == 'E') enemy = std::make_unique<Chaser>(entity.x, entity.y);
                else if (entity.type == 'H') enemy = std::make_unique<Slime>(entity.x, entity.y, 1, 0);
                else if (entity.type == 'V') enemy = std::make_unique<Slime>(entity.x, entity.y, 0, 1);

                enemy->setCallback([this]() { this->lose(); });
                enemies.push_back(std::move(enemy));
            }
        }

        for (int r = 0; r < LEVEL_H; ++r) {
            for (int c = 0; c < LEVEL_W; ++c) {
                if (auto portal = dynamic_cast<Portal *>(level.get(c, r))) {
                    portal->setCallback([this]() { this->win(); });
                    portal->setCheckKeysCallback([this]() { return this->areKeysEnough(); });
                }
                if (auto key = dynamic_cast<Key *>(level.get(c, r))) {
                    totalKeys++;
                    key->setCallback([this]() {
                        Logger::info("Key collected! Total: " + std::to_string(this->collectedKeys + 1) + "/" + std::to_string(this->totalKeys));
                        this->collectedKeys++;
                    });
                }
                if (auto smoke = dynamic_cast<Smoke *>(level.get(c, r))) {
                    smoke->setCallback([this]() {
                        Logger::info("Smoke screen activated! Enemies will be smoked for 5 turns.");
                        Enemy::smoke(5);
                    });
                }
                if (auto pickable = dynamic_cast<Pickable *>(level.get(c, r))) {
                    pickable->setCollectedCallback([this, c, r]() {
                        Logger::info("Object collected at (" + std::to_string(c) + ", " + std::to_string(r) + ")");
                        this->level.set(c, r, std::make_unique<Empty>());
                    });
                }
            }
        }
        return true;
    }
    return false;
}

void GameState::tick(const Command cmd) {
    int dx = 0, dy = 0;
    switch (cmd) {
        case QUIT: running = false;
            return;
        case GO_LEFT: dx = -1;
            break;
        case GO_RIGHT: dx = 1;
            break;
        case GO_UP: dy = -1;
            break;
        case GO_DOWN: dy = 1;
            break;
        default: throw UnexpectedCommand();
    }

    if (!player->move(dx, dy, level)) return;

    if (Enemy::isSmoked()) Enemy::smoke(-1);

    for (auto &enemy: enemies) {
        enemy->move(player.get(), level);
        if (enemy->getX() == player->getX() && enemy->getY() == player->getY()) {
            enemy->onTrigger();
        }
    }
}

bool GameState::isRunning() const { return running; }
Level &GameState::getLevel() { return level; }
const Level &GameState::getLevel() const { return level; }
const Player &GameState::getPlayer() const { return *player; }
const int GameState::getKeysCollected() const {return collectedKeys;}
const int GameState::getKeysTotal() const {return totalKeys;}
const bool GameState::areKeysEnough() const {return collectedKeys == totalKeys;}
const std::vector<std::unique_ptr<Enemy> > &GameState::getEnemies() const { return enemies; }
