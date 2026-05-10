#pragma once

#include "Entity.h"

class Level;

class Player : public Entity {
public:
    int smokeScreens;

    Player(int startX, int startY);
    bool move(int dx, int dy, Level& level);
};
