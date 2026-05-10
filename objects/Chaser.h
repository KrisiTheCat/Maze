#pragma once

#include "Enemy.h"

class Chaser : public Enemy {
public:
    Chaser(int startX, int startY);
    void move(Player* player, const Level& level) override;
};
