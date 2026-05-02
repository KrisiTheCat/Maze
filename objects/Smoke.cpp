#include "Smoke.h"

#include "Enemy.h"
#include "Player.h"

Smoke::Smoke() : Pickable(SP_SMOKE) {}

void Smoke::interact(Player* player) {
    if(player) Enemy::smoke(3);
}