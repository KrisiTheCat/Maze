#include "Portal.h"
#include "Key.h"
#include "../display/Logger.h"

bool Portal::blocksPlayer() const {
    if (checkKeys && *checkKeys) {
        return !(*checkKeys)();
    }
    return true;
}

bool Portal::shouldTrigger() const {
    if (checkKeys && *checkKeys) {
        return (*checkKeys)();
    }
    return true;
}