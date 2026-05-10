#pragma once

class Movable {
public:
    virtual ~Movable() = default;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual void move(int dx, int dy) = 0;
};
