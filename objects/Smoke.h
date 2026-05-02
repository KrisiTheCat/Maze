#pragma once

#include "Pickable.h"

class Smoke : public Pickable {
public:
    Smoke();
    void interact(Player* player) override;
};