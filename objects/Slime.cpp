#include "Slime.h"

Slime::Slime(int startX, int startY, int dirX, int dirY) : Enemy(startX, startY), directionX(dirX), directionY(dirY) {
    id = SP_SLIME;
}

void Slime::move(const std::vector<std::vector<Object*>>& grid, Player* player) {
    if(isSmoked()) return;
    if (grid[y + directionY][x + directionX]->isSolid()) {
        directionX *= -1;
        directionY *= -1;
    }
    x += directionX;
    y += directionY;
}