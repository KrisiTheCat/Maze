#include "Object.h"

Object::Object(SpriteID id) : id(id) {}

Object::~Object() = default;

SpriteID Object::getID() const {
    return id;
}