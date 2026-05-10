#include "Portal.h"
#include "Key.h"

Portal::Portal() : Object(SP_PORTAL), controller(nullptr), effect(nullptr) {}

bool Portal::blocksPlayer() const {
    return !Key::areKeysEnough();
}

void Portal::onTrigger(Player& player) {
    if (controller && effect) {
        effect->apply(*controller);
    }
}