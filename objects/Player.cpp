#include "Player.h"
#include "Empty.h"
#include "Interfaces.h"
#include "Item.h"
#include "../Level.h"

Player::Player(int startX, int startY) : Entity(SP_PLAYER, startX, startY), smokeScreens(0) {}

bool Player::move(int dx, int dy, Level& level) {
    if (!checkMove(dx, dy, level)) return false;

    Object* target = level.get(x + dx, y + dy);

    if (auto triggerable = dynamic_cast<Triggerable*>(target)) {
        triggerable->onTrigger(*this);

        if (dynamic_cast<Pickable*>(target)) {
            level.set(x + dx, y + dy, std::make_unique<Empty>());
        }
    }

    Entity::move(dx, dy);
    return true;
}
