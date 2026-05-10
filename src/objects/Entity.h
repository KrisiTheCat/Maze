#pragma once

#include "Object.h"
#include "interfaces/Movable.h"

class Level;

class Entity : public Object, public Movable {
protected:
    int x, y;
    bool checkMove(int dx, int dy, const Level& level) const;
public:
    explicit Entity(SpriteID id, int startX, int startY);
    virtual ~Entity() = default;

    int getX() const override;
    int getY() const override;
    void move(int dx, int dy) override;

    bool tryMove(int dx, int dy, const Level& level);
    void randomMove(const Level& level);
};
