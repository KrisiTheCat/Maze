#pragma once

#include "Enemy.h"

class Chaser : public Enemy {
public:
    Chaser(int startX, int startY);
    void move(const std::vector<std::vector<Object*>>& grid, Player* player) override;
};