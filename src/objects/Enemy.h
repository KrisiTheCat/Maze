#pragma once

#include "Entity.h"
#include "Player.h"
#include "interfaces/Triggerable.h"

class Level;

class Enemy : public Entity, public Triggerable {
    static int smokedFor;
public:
    Enemy(int startX, int startY);
    virtual ~Enemy() = default;

    virtual void move(Player* player, const Level& level) = 0;

    static void smoke(int time);
    static bool isSmoked();
};
