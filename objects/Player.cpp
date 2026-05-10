#include "Player.h"
#include "Empty.h"
#include "../Level.h"
#include "interfaces/Pickable.h"
#include "interfaces/Triggerable.h"

Player::Player(int startX, int startY) : Entity(SP_PLAYER, startX, startY), smokeScreens(0) {}

bool Player::move(int dx, int dy, Level& level) {
    if (!checkMove(dx, dy, level)) return false;

    Object* target = level.get(x + dx, y + dy);

    if (auto triggerable = dynamic_cast<Triggerable*>(target)) {
        triggerable->onTrigger();
    }

    if (auto pickable = dynamic_cast<Pickable*>(target)) {
        pickable->onPick();
    }

    Entity::move(dx, dy);
    return true;
}
