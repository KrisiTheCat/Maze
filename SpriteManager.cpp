#include "SpriteManager.h"

const char* SpriteManager::filePath = "resources/sprites/";

inline std::string getSpritePath(SpriteID id) {
    switch (id) {
        case SP_EMPTY:  return "empty.txt";
        case SP_WALL:   return "wall.txt";
        case SP_PLAYER: return "player.txt";
        case SP_ENEMY:  return "enemy.txt";
        case SP_SLIME:  return "slime.txt";
        case SP_PORTAL: return "portal.txt";
        case SP_KEY:    return "key.txt";
        case SP_SMOKE:  return "smoke.txt";
        default:        return "empty.txt";
    }
}

void SpriteManager::loadAllSprites() {
    for (int i = 0; i < SP_COUNT; ++i) {
        SpriteID id = (SpriteID)i;
        Sprite sprite;
        sprite.loadFromFile(filePath+getSpritePath(id));
        sprites[id] = sprite;
    }
}

const Sprite& SpriteManager::getSprite(SpriteID id) const {
    return sprites.at(id);
}