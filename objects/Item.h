#pragma once

#include "Object.h"
#include "Interfaces.h"

class Item : public Object, public Pickable, public Triggerable {
public:
    explicit Item(SpriteID id) : Object(id) {}
    virtual ~Item() = default;
};
