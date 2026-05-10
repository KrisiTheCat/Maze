#pragma once

#include "../GameController.h"

class InteractionEffect {
public:
    virtual ~InteractionEffect() = default;
    virtual void apply(GameController& controller) = 0;
};
