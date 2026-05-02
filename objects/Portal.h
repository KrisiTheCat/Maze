#pragma once

#include "Object.h"

class Portal : public Object {
public:
    Portal();
    bool isSolid() const override;
};