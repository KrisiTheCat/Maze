#include <iostream>
#include <vector>
#include <windows.h>
#include "config.h"
#include "Object.h"
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

    std::vector<Object*> catalog;
    for(int i = 0; i < SP_COUNT; ++i) {
        catalog.push_back(new Object(static_cast<SpriteID>(i)));
    }

    std::vector<std::vector<Object*>> world(LEVEL_H, std::vector<Object*>(LEVEL_W, catalog[SP_EMPTY]));

    const char* mazeLayout[LEVEL_H] = {
        "111111111111111111",
        "1P00010001000000E1",
        "111101010101111101",
        "100000010001000001",
        "101111111111011111",
        "101000000000010001",
        "101011111111110101",
        "10101000S000010101",
        "101010111111010101",
        "100010100001010101",
        "111110101101010101",
        "100000101001010001",
        "101111101111011111",
        "100000000E000000X1",
        "111111111111111111"
    };

    for (int r = 0; r < LEVEL_H; ++r) {
        for (int c = 0; c < LEVEL_W; ++c) {
            char tile = mazeLayout[r][c];
            switch (tile) {
                case '1': world[r][c] = catalog[SP_WALL]; break;
                case '0': world[r][c] = catalog[SP_EMPTY]; break;
                case 'P': world[r][c] = catalog[SP_PLAYER]; break;
                case 'E': world[r][c] = catalog[SP_ENEMY]; break;
                case 'S': world[r][c] = catalog[SP_SLIME]; break;
                case 'X': world[r][c] = catalog[SP_PORTAL]; break;
                default:  world[r][c] = catalog[SP_EMPTY]; break;
            }
        }
    }

    Renderer engine(spriteManager);
    engine.render(world);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    std::cin.get();

    for(auto* obj : catalog) delete obj;
    return 0;
}