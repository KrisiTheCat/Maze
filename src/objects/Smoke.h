#pragma once

#include "Object.h"
#include "interfaces/Pickable.h"
#include "interfaces/Triggerable.h"

class Smoke : public Object, public Pickable, public Triggerable {
public:
    Smoke() : Object(SP_SMOKE) {}
};
