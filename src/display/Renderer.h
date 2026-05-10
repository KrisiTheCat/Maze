#pragma once

#include <windows.h>
#include "../config.h"
#include "sprites/SpriteManager.h"

class GameState;

class Renderer {
    HANDLE hConsole;
    const SpriteManager& spriteManager;
public:
    explicit Renderer(const SpriteManager& manager);
    void render(const GameState& state);
};
