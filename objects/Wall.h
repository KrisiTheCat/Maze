#pragma once

#include "Object.h"
#include "interfaces/Collidable.h"

class Wall : public Object, public Collidable {
public:
    Wall() : Object(SP_WALL) {}
    bool blocksPlayer() const override { return true; }
};
