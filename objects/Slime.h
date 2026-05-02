#pragma once

#include "Enemy.h"

class Slime : public Enemy {
    int directionX;
    int directionY;
public:
    Slime(int startX, int startY, int dirX, int dirY);
    void move(const std::vector<std::vector<Object*>>& grid, Player* player) override;
};