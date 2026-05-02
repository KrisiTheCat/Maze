#include <iostream>
#include <vector>
#include <windows.h>
#include "config.h"
#include "objects/Object.h"
#include "objects/Empty.h"
#include "objects/Wall.h"
#include "objects/Portal.h"
#include "objects/Key.h"
#include "objects/Smoke.h"
#include "objects/Player.h"
#include "objects/Enemy.h"
#include "objects/Chaser.h"
#include "objects/Slime.h"
#include "SpriteManager.h"
#include "Renderer.h"

int main() {
    SetConsoleOutputCP(437);

    SpriteManager spriteManager;

    try {
        spriteManager.loadAllSprites();
    } catch (const std::exception& e) {
        std::cerr << "Initialization Error: " << e.what() << "\n";
        return 1;
    }

    Player player(1, 1);
    std::vector<Enemy*> enemies;

    std::vector<std::vector<Object*>> world(LEVEL_H, std::vector<Object*>(LEVEL_W));

    const char* mazeLayout[LEVEL_H] = {
        "111111111111111111",
        "1P0K010001000000E1",
        "111101010101111101",
        "100000010001000001",
        "101111111111011111",
        "101000H00000010001",
        "101011111111110101",
        "10101000V000010101",
        "101010111111010101",
        "100010100M01010101",
        "111110101101010101",
        "100000101001010001",
        "101111101111011111",
        "1K0000000E000000X1",
        "111111111111111111"
    };

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            char tile = mazeLayout[r][c];
            switch (tile) {
                case '1': world[r][c] = new Wall(); break;
                case 'P': world[r][c] = &player; player.x = c; player.y = r; break;
                case 'E': {
                    auto* chaser = new Chaser(c, r);
                    enemies.push_back(chaser);
                    world[r][c] = chaser;
                    break;
                }
                case 'H': {
                    auto* slime = new Slime(c, r, 1, 0);
                    enemies.push_back(slime);
                    world[r][c] = slime;
                    break;
                }
                case 'V': {
                    auto* slime = new Slime(c, r, 0, 1);
                    enemies.push_back(slime);
                    world[r][c] = slime;
                    break;
                }
                case 'K': world[r][c] = new Key(); break;
                case 'M': world[r][c] = new Smoke(); break;
                case 'X': world[r][c] = new Portal(); break;
                default:  world[r][c] = new Empty(); break;
            }
        }
    }

    Renderer engine(spriteManager);
    engine.render(world);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    std::cin.get();

    for (auto& row : world) {
        for (auto* obj : row) {
            if (obj != &player) {
                delete obj;
            }
        }
    }

    return 0;
}