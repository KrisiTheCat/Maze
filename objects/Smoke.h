#pragma once

#include "Item.h"

class Smoke : public Item {
public:
    Smoke() : Item(SP_SMOKE) {}
    void onTrigger(Player& player) override;
};