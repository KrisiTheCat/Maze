#pragma once

#include <map>
#include "Sprite.h"
#include "config.h"

class SpriteManager {
private:
    std::map<SpriteID, Sprite> sprites;
public:
    void loadAllSprites();
    const Sprite& getSprite(SpriteID id) const;
};