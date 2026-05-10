#include "Slime.h"
#include "../Level.h"

Slime::Slime(int startX, int startY, int dirX, int dirY)
    : Enemy(startX, startY), directionX(dirX), directionY(dirY)
{
    id = SP_SLIME;
}

void Slime::move(Player* player, const Level& level) {
    if (isSmoked()) return;

    if (!tryMove(directionX, directionY, level)) {
        directionX *= -1;
        directionY *= -1;
        tryMove(directionX, directionY, level);
    }
}
