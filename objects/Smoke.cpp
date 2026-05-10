#include "Smoke.h"

#include "Enemy.h"
#include "Player.h"

void Smoke::onTrigger(Player& player) {
    Enemy::smoke(3);
}