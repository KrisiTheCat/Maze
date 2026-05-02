#pragma once

#include "Pickable.h"

class Key : public Pickable {
private:
    static int totalKeys;
    static int collectedKeys;
public:

    Key();
    ~Key() override;

    void interact(Player* player) override;

    static void printKeyStatus();
    static const bool areKeysEnough();
};