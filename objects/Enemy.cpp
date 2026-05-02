#include "Enemy.h"

int Enemy::smokedFor = 0;

Enemy::Enemy(int startX, int startY) : Character(SP_ENEMY, startX, startY) {}

void Enemy::smoke(int time) {
    smokedFor += time;
}


bool Enemy::isSmoked() {
    return smokedFor > 0;
}