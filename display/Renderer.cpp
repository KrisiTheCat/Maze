#include "Renderer.h"
#include "../GameState.h"
#include "../objects/Key.h"
#include "../objects/Enemy.h"
#include <iostream>
#include <vector>

Renderer::Renderer(const SpriteManager& manager)
    : spriteManager(manager), hConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {}

void Renderer::render(const GameState& state) {
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coord);

    const Level& level = state.getLevel();
    const Player& player = state.getPlayer();
    const auto& enemies = state.getEnemies();

    std::vector<std::vector<Object*>> viewBuffer(LEVEL_H, std::vector<Object*>(LEVEL_W));

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            viewBuffer[r][c] = level.get(c, r);
        }
    }

    viewBuffer[player.getY()][player.getX()] = const_cast<Player*>(&player);
    for (const auto& enemy : enemies) {
        viewBuffer[enemy->getY()][enemy->getX()] = enemy.get();
    }

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int pr = 0; pr < SPRITE_ROWS; ++pr) {
            for (int c = 0; c < LEVEL_W; ++c) {
                Object* obj = viewBuffer[r][c];
                if (!obj) continue;

                const Sprite& s = spriteManager.getSprite(obj->getID());

                bool dimmed = false;
                if (dynamic_cast<Enemy*>(obj) && Enemy::isSmoked()) {
                    dimmed = true;
                }

                for (int pc = 0; pc < SPRITE_COLS; ++pc) {
                    WORD attribute = s.data[pr][pc].attribute;
                    if (dimmed) {
                        attribute = GY;
                    }
                    
                    SetConsoleTextAttribute(hConsole, attribute);
                    DWORD written;
                    WriteConsoleA(hConsole, &s.data[pr][pc].symbol, 1, &written, NULL);
                }
            }
            std::cout << '\n';
        }
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << '\n';
    Key::printKeyStatus();
}
