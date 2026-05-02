#include "Renderer.h"
#include <iostream>
#include "objects/Key.h"
#include "objects/Enemy.h"

Renderer::Renderer(const SpriteManager& manager) : spriteManager(manager) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Renderer::render(const std::vector<std::vector<Object*>>& grid) {
    system("cls");

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int pr = 0; pr < SPRITE_ROWS; ++pr) {
            for (int c = 0; c < LEVEL_W; ++c) {
                const Sprite& s = spriteManager.getSprite(grid[r][c]->getID());
                for (int pc = 0; pc < SPRITE_COLS; ++pc) {
                    WORD attribute = s.data[pr][pc].attribute;
                    if (grid[r][c]->isEnemy() && Enemy::isSmoked()) {
                        attribute = GY;
                    }
                    SetConsoleTextAttribute(hConsole, attribute);
                    DWORD written;
                    WriteConsoleA(hConsole, &s.data[pr][pc].symbol, 1, &written, NULL);
                }
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << '\n';
        }
    }

    std::cout << '\n';
    Key::printKeyStatus();
}