#include "GameState.h"
#include "objects/Chaser.h"
#include "objects/Slime.h"
#include "objects/Portal.h"
#include "effects/VictoryEffect.h"
#include "effects/GameOverEffect.h"
#include <iostream>

#include "exceptions/UnexpectedCommand.h"

static const char* mazeLayout[LEVEL_H] = {
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
    std::cout << "\nCONGRATULATIONS! YOU ESCAPED THE MAZE!\n";
    running = false;
}

void GameState::lose() {
    std::cout << "\nGAME OVER! YOU WERE CAUGHT!\n";
    running = false;
}

GameState::GameState() : running(true) {
    std::vector<EntityData> entities;
    level.init(mazeLayout);

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            entities.push_back({mazeLayout[r][c], c, r});
        }
    }

    for (const auto& entity : entities) {
        if (entity.type == 'P') player = std::make_unique<Player>(entity.x, entity.y);
        else if (entity.type == 'E' || entity.type == 'H' || entity.type == 'V') {
            std::unique_ptr<Enemy> enemy;
            if (entity.type == 'E') enemy = std::make_unique<Chaser>(entity.x, entity.y);
            else if (entity.type == 'H') enemy = std::make_unique<Slime>(entity.x, entity.y, 1, 0);
            else if (entity.type == 'V') enemy = std::make_unique<Slime>(entity.x, entity.y, 0, 1);
            
            enemy->setController(this);
            enemy->setEffect(std::make_unique<GameOverEffect>());
            enemies.push_back(std::move(enemy));
        }
    }


    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            if (auto portal = dynamic_cast<Portal*>(level.get(c, r))) {
                portal->setController(this);
                portal->setEffect(std::make_unique<VictoryEffect>());
            }
        }
    }
}

bool GameState::loadLevel(const std::string& filename) {
    std::vector<EntityData> entities;
    if (level.load(filename, entities)) {
        enemies.clear();
        for (const auto& entity : entities) {
            if (entity.type == 'P') player = std::make_unique<Player>(entity.x, entity.y);
            else if (entity.type == 'E' || entity.type == 'H' || entity.type == 'V') {
                std::unique_ptr<Enemy> enemy;
                if (entity.type == 'E') enemy = std::make_unique<Chaser>(entity.x, entity.y);
                else if (entity.type == 'H') enemy = std::make_unique<Slime>(entity.x, entity.y, 1, 0);
                else if (entity.type == 'V') enemy = std::make_unique<Slime>(entity.x, entity.y, 0, 1);
                
                enemy->setController(this);
                enemy->setEffect(std::make_unique<GameOverEffect>());
                enemies.push_back(std::move(enemy));
            }
        }

        for (int r = 0; r < LEVEL_H; ++r) {
            for (int c = 0; c < LEVEL_W; ++c) {
                if (auto portal = dynamic_cast<Portal*>(level.get(c, r))) {
                    portal->setController(this);
                    portal->setEffect(std::make_unique<VictoryEffect>());
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
        case QUIT:     running = false; return;
        case GO_LEFT:  dx = -1; break;
        case GO_RIGHT: dx =  1; break;
        case GO_UP:    dy = -1; break;
        case GO_DOWN:  dy =  1; break;
        default: throw UnexpectedCommand();
    }

    if (!player->move(dx, dy, level)) return;

    if (Enemy::isSmoked()) Enemy::smoke(-1);

    for (auto& enemy : enemies) {
        enemy->move(player.get(), level);
        if (enemy->getX() == player->getX() && enemy->getY() == player->getY()) {
            enemy->onTrigger(*player);
        }
    }
}

bool GameState::isRunning() const { return running; }
Level& GameState::getLevel() { return level; }
const Level& GameState::getLevel() const { return level; }
const Player& GameState::getPlayer() const { return *player; }
const std::vector<std::unique_ptr<Enemy>>& GameState::getEnemies() const { return enemies; }
