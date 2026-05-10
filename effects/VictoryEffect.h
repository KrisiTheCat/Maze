#pragma once

#include "InteractionEffect.h"

class VictoryEffect : public InteractionEffect {
public:
    void apply(GameController& controller) override {
        controller.win();
    }
};
