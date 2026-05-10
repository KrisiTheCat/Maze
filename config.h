#pragma once

#include <functional>
#include <memory>
#include <windows.h>
#include <string>

#define BK 0x00
#define WH (BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY)
#define DR (FOREGROUND_RED)
#define RD (FOREGROUND_RED|FOREGROUND_INTENSITY)
#define CY (FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY)
#define GN (FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define YL (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define MG (FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY)
#define PC (FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define GY (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)
#define DG (FOREGROUND_INTENSITY)
#define DB (FOREGROUND_BLUE)
#define DP (FOREGROUND_RED|FOREGROUND_BLUE)

using Callback = std::function<void()>;
using CallbackPtr = std::shared_ptr<std::function<void()>>;
using ConditionCallback = std::function<bool()>;
using ConditionPtr = std::shared_ptr<ConditionCallback>;

static const int SPRITE_ROWS = 6;
static const int SPRITE_COLS = 6;
static const int LEVEL_W = 18;
static const int LEVEL_H = 15;
static const int VIEW_W = LEVEL_W * SPRITE_COLS;
static const int VIEW_H = LEVEL_H * SPRITE_ROWS;

static const int HEADER_HEIGHT = 3;
static const int HEADER_WIDTH = SPRITE_COLS*LEVEL_W-2;

enum SpriteID {
    SP_EMPTY = 0,
    SP_WALL,
    SP_PLAYER,
    SP_ENEMY,
    SP_SLIME,
    SP_PORTAL,
    SP_KEY,
    SP_SMOKE,
    SP_COUNT
};

enum Command : char {
    GO_LEFT = 'a',
    GO_RIGHT = 'd',
    GO_UP = 'w',
    GO_DOWN = 's',
    QUIT = 'q'
};
