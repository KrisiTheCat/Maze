#pragma once

#include <memory>
#include "Object.h"
#include "Interfaces.h"
#include "../effects/InteractionEffect.h"

class Portal : public Object, public Collidable, public Triggerable {
    GameController* controller;
    std::unique_ptr<InteractionEffect> effect;
public:
    Portal();
    void setController(GameController* ctrl) { controller = ctrl; }
    void setEffect(std::unique_ptr<InteractionEffect> eff) { effect = std::move(eff); }

    bool blocksPlayer() const override;
    void onTrigger(Player& player) override;
};