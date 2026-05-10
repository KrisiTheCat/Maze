#pragma once

#include "../../config.h"

class Pickable {
protected:
    CallbackPtr collectedCallback;
public:
    virtual ~Pickable() = default;
    void setCollectedCallback(const Callback& c) { collectedCallback = std::make_shared<Callback>(c); }
    void onPick() const { if (collectedCallback) (*collectedCallback)(); }
};
