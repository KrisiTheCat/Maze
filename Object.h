#pragma once

#include "config.h"

class Object {
protected:
    SpriteID id;
public:
    explicit Object(SpriteID id);
    virtual ~Object();

    SpriteID getID() const;
};

class EmptyObject : public Object { public: EmptyObject(); };
class WallObject : public Object { public: WallObject(); };
class PlayerObject : public Object { public: PlayerObject(); };
class EnemyObject : public Object { public: EnemyObject(); };
class PortalObject : public Object { public: PortalObject(); };