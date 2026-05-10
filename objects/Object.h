#pragma once

#include "../config.h"

class Player;

class Object {
protected:
    SpriteID id;
public:
    explicit Object(SpriteID id);
    virtual ~Object();

    SpriteID getID() const;
};