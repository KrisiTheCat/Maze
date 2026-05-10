#pragma once

#include <vector>
#include "objects/Object.h"
#include "objects/Player.h"
#include "objects/Enemy.h"
#include "config.h"

class World {
private:
    std::vector<std::vector<Object*>> grid;
    Player* player;
    std::vector<Enemy*> enemies;

    World();

public:
    static World& getInstance();

    World(const World&) = delete;
    World& operator=(const World&) = delete;

    void init();
    void set(int x, int y, Object* obj);
    Object* get(int x, int y);
    void cleanup();

    const std::vector<std::vector<Object*>>& getGrid() const;
    Player* getPlayer() const;
    const std::vector<Enemy*>& getEnemies() const;
};