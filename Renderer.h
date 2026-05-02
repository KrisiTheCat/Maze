#pragma once

#include <windows.h>
#include <vector>
#include "config.h"
#include "objects/Object.h"
#include "SpriteManager.h"

class Renderer {
    HANDLE hConsole;
    const SpriteManager& spriteManager;
public:
    Renderer(const SpriteManager& manager);
    void render(const std::vector<std::vector<Object*>>& grid);
};