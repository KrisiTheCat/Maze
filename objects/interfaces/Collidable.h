#pragma once

class Collidable {
public:
    virtual ~Collidable() = default;
    virtual bool blocksPlayer() const = 0;
};