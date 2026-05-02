#pragma once

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

static const int SPRITE_ROWS = 6;
static const int SPRITE_COLS = 6;
static const int LEVEL_W = 18;
static const int LEVEL_H = 15;
static const int VIEW_W = LEVEL_W * SPRITE_COLS;
static const int VIEW_H = LEVEL_H * SPRITE_ROWS;

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

struct SpriteData {
    WORD attr;
    unsigned char sym;
};

inline std::string getSpritePath(SpriteID id) {
    switch (id) {
        case SP_EMPTY:  return "sprites/empty.txt";
        case SP_WALL:   return "sprites/wall.txt";
        case SP_PLAYER: return "sprites/player.txt";
        case SP_ENEMY:  return "sprites/enemy.txt";
        case SP_SLIME:  return "sprites/slime.txt";
        case SP_PORTAL: return "sprites/portal.txt";
        case SP_KEY:    return "sprites/key.txt";
        case SP_SMOKE:  return "sprites/smoke.txt";
        default:        return "sprites/empty.txt";
    }
}