#pragma once

#include <memory>
#include "Object.h"
#include "interfaces/Collidable.h"
#include "interfaces/Triggerable.h"

class Portal : public Object, public Collidable, public Triggerable {
    ConditionPtr checkKeys;

public:
    Portal() : Object(SP_PORTAL), checkKeys(nullptr) {}

    void setCheckKeysCallback(ConditionCallback callback) {checkKeys = std::make_shared<ConditionCallback>(callback);}

    bool blocksPlayer() const override;

    bool shouldTrigger() const override;
};
