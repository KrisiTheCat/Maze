#pragma once

#include "Object.h"

class Character : public Object {
public:
    int x, y;
    explicit Character(SpriteID id, int startX, int startY);
};