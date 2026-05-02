#include "Portal.h"
#include "Key.h"

Portal::Portal() : Object(SP_PORTAL) {}

bool Portal::isSolid() const {
    if (Key::areKeysEnough()) {
        return true;
    }
    return false;
}