#pragma once

#include "Object.h"

class Pickable : public Object {
public:
    explicit Pickable(SpriteID id);
    virtual ~Pickable() = default;

    bool isPickup() const override { return true; }
};