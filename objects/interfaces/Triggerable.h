#pragma once

class Player;

class Triggerable {
    CallbackPtr callback;
public:
    virtual ~Triggerable() = default;
    virtual bool shouldTrigger() const {
        return true;
    }
    void onTrigger() const{
        if (callback && shouldTrigger()) (*callback)();
    }
    void setCallback(const Callback& c) { callback = std::make_shared<Callback>(c); }
};
