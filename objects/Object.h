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

    virtual bool isSolid() const { return false; }
    virtual bool isPickup() const { return false; }
    virtual bool isEnemy() const { return false; }
    virtual void interact(Player* player) {}
};