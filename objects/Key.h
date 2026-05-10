#pragma once
#include "interfaces/Pickable.h"
#include "interfaces/Triggerable.h"

class Key : public Object, public Pickable, public Triggerable {
public:

    Key(): Object(SP_KEY) {}
    ~Key() {}
};
