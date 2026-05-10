#include "Key.h"
#include "Player.h"
#include <iostream>

int Key::totalKeys = 0;
int Key::collectedKeys = 0;

Key::Key() : Item(SP_KEY) {
    totalKeys++;
}

Key::~Key() {
    totalKeys--;
}

void Key::onTrigger(Player& player) {
    collectedKeys++;
}

void Key::printKeyStatus() {
    std::cout << "KEYS: " << collectedKeys << "/" << totalKeys << "\n";
}

const bool Key::areKeysEnough() {
    return collectedKeys == totalKeys;
}