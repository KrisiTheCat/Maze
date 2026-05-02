#include "SpriteManager.h"

void SpriteManager::loadAllSprites() {
    for (int i = 0; i < SP_COUNT; ++i) {
        SpriteID id = (SpriteID)i;
        Sprite sprite;
        sprite.loadFromFile(getSpritePath(id));
        sprites[id] = sprite;
    }
}

const Sprite& SpriteManager::getSprite(SpriteID id) const {
    return sprites.at(id);
}