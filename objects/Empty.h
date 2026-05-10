#pragma once

#include "Object.h"

class Empty : public Object {
public:
    Empty() : Object(SP_EMPTY) {}
};