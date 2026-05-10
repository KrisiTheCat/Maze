#include "Chaser.h"
#include "../Level.h"

Chaser::Chaser(int startX, int startY) : Enemy(startX, startY) {}

void Chaser::move(Player* player, const Level& level) {
    if (isSmoked()) return;

   // onTrigger(*player);
    if (player->getX() > getX() && tryMove( 1,  0, level)) return;
    if (player->getX() < getX() && tryMove(-1,  0, level)) return;
    if (player->getY() > getY() && tryMove( 0,  1, level)) return;
    if (player->getY() < getY() && tryMove( 0, -1, level)) return;
    randomMove(level);
}
