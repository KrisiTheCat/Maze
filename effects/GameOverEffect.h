#pragma once

#include "InteractionEffect.h"

class GameOverEffect : public InteractionEffect {
public:
    void apply(GameController& controller) override {
        controller.lose();
    }
};
