#pragma once

#include "Item.h"

class Key : public Item {
private:
    static int totalKeys;
    static int collectedKeys;
public:

    Key();
    ~Key() override;

    void onTrigger(Player& player) override;

    static void printKeyStatus();
    static const bool areKeysEnough();
};