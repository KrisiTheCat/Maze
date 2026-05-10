#include "Entity.h"
#include "../levels/Level.h"
#include "interfaces/Collidable.h"

Entity::Entity(SpriteID id, int startX, int startY) : Object(id), x(startX), y(startY) {}

int Entity::getX() const { return x; }
int Entity::getY() const { return y; }

bool Entity::checkMove(int dx, int dy, const Level& level) const {
    Object* target = level.get(x + dx, y + dy);
    if (!target) return false;
    
    if (auto collidable = dynamic_cast<Collidable*>(target)) {
        return !collidable->blocksPlayer();
    }
    return true;
}

void Entity::move(int dx, int dy) {
    x += dx;
    y += dy;
}

bool Entity::tryMove(int dx, int dy, const Level& level) {
    if (!checkMove(dx, dy, level)) return false;
    move(dx, dy);
    return true;
}

void Entity::randomMove(const Level& level) {
    if (tryMove( 1,  0, level)) return;
    if (tryMove(-1,  0, level)) return;
    if (tryMove( 0,  1, level)) return;
    tryMove(0, -1, level);
}
