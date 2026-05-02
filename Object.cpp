#include "Object.h"

Object::Object(SpriteID id) : id(id) {}

Object::~Object() = default;

SpriteID Object::getID() const {
    return id;
}

EmptyObject::EmptyObject() : Object(SP_EMPTY) {}
WallObject::WallObject() : Object(SP_WALL) {}
PlayerObject::PlayerObject() : Object(SP_PLAYER) {}
EnemyObject::EnemyObject() : Object(SP_ENEMY) {}
PortalObject::PortalObject() : Object(SP_PORTAL) {}