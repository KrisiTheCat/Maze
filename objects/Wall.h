#pragma once

#include "Object.h"

class Wall : public Object {
public:
    Wall();
    bool isSolid() const override { return true; }
};