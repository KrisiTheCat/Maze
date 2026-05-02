#pragma once

#include <vector>
#include "Character.h"
#include "Player.h"

class Enemy : public Character {
private:
    static int smokedFor;
public:

    Enemy(int startX, int startY);
    virtual ~Enemy() = default;

    virtual void move(const std::vector<std::vector<Object*>>& grid, Player* player) = 0;

    static void smoke(int time);
    static bool isSmoked();

    bool isEnemy() const override { return true; }
};