#pragma once

#include <memory>
#include "Entity.h"
#include "Player.h"
#include "../effects/InteractionEffect.h"

class Level;

class Enemy : public Entity, public Triggerable {
    static int smokedFor;
    GameController* controller;
    std::unique_ptr<InteractionEffect> effect;
public:
    Enemy(int startX, int startY);
    virtual ~Enemy() = default;

    void setController(GameController* ctrl) { controller = ctrl; }
    void setEffect(std::unique_ptr<InteractionEffect> eff) { effect = std::move(eff); }

    virtual void move(Player* player, const Level& level) = 0;

    void onTrigger(Player& player) override;

    static void smoke(int time);
    static bool isSmoked();
};
