#include "Key.h"
#include "Player.h"
#include <iostream>

int Key::totalKeys = 0;
int Key::collectedKeys = 0;

Key::Key() : Pickable(SP_KEY) {
    totalKeys++;
}

Key::~Key() {
    totalKeys--;
}

void Key::interact(Player* player) {
    if(player) collectedKeys++;
}

void Key::printKeyStatus() {
    std::cout << "KEYS: " << collectedKeys << "/" << totalKeys << "\n";
}

const bool Key::areKeysEnough() {
    return collectedKeys == totalKeys;
}