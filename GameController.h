#pragma once

class GameController {
public:
    virtual ~GameController() = default;
    virtual void win() = 0;
    virtual void lose() = 0;
};
