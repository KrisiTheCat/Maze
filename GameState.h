#pragma once

#include <memory>
#include <vector>
#include "Level.h"
#include "config.h"
#include "objects/Player.h"
#include "objects/Enemy.h"

#include "GameController.h"

class GameState : public GameController {
    Level level;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies;
    bool running;

public:
    GameState();

    void tick(Command cmd);
    bool loadLevel(const std::string& filename);

    void win() override;
    void lose() override;

    bool isRunning() const;
    Level& getLevel();
    const Level& getLevel() const;
    const Player& getPlayer() const;
    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const;
};
