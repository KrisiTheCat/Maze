#pragma once

#include <memory>
#include <vector>
#include "levels/Level.h"
#include "config.h"
#include "objects/Player.h"
#include "objects/Enemy.h"

#include <functional>
#include "GameController.h"

class GameState : public GameController {
    Level level;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies;

    int totalKeys;
    int collectedKeys;

    bool running;
    std::function<void(bool)> gameOverCallback;

public:
    GameState();

    void tick(Command cmd);
    bool loadLevel(const std::string& filename);

    void win() override;
    void lose() override;

    void setGameOverCallback(std::function<void(bool)> cb) { gameOverCallback = std::move(cb); }

    bool isRunning() const;
    Level& getLevel();
    const Level& getLevel() const;
    const Player& getPlayer() const;
    const int getKeysCollected() const;
    const int getKeysTotal() const;
    const bool areKeysEnough() const;
    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const;
};
