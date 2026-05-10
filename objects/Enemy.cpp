#include "Enemy.h"

int Enemy::smokedFor = 0;

Enemy::Enemy(int startX, int startY) : Entity(SP_ENEMY, startX, startY), controller(nullptr), effect(nullptr) {}

void Enemy::smoke(int time) {
    smokedFor += time;
}


bool Enemy::isSmoked() {
    return smokedFor > 0;
}

void Enemy::onTrigger(Player& player){
    if (controller && effect) {
        effect->apply(*controller);
    }
}