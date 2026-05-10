#pragma once

class Player;

class Triggerable {
public:
    virtual ~Triggerable() = default;
    virtual void onTrigger(Player& player) = 0;
};
