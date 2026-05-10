#pragma once

#include <string>
#include "config.h"
#include "Pixel.h"

class Sprite {
public:
    Pixel data[SPRITE_ROWS][SPRITE_COLS];

    Sprite();

    void loadFromFile(const std::string& filename);
};