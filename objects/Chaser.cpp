#include "Chaser.h"

Chaser::Chaser(int startX, int startY) : Enemy(startX, startY) {}

void Chaser::move(const std::vector<std::vector<Object*>>& grid, Player* player) {
    if(isSmoked()) return;

    if (player->x > x && !grid[y][x+1]->isSolid()) x++;
    else if (player->x < x && !grid[y][x-1]->isSolid()) x--;
    else if (player->y > y && !grid[y+1][x]->isSolid()) y++;
    else if (player->y < y && !grid[y-1][x]->isSolid()) y--;
}