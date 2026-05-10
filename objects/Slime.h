#pragma once

#include "Enemy.h"

class Slime : public Enemy {
    int directionX;
    int directionY;
public:
    Slime(int startX, int startY, int dirX, int dirY);
    void move(Player* player, const Level& level) override;
};
