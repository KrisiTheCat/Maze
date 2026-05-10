#pragma once

#include <windows.h>
#include <functional>
#include <utility>

#include "HeaderStyle.h"
#include "../config.h"

enum class HeaderStyle;

class Header {
    HANDLE hConsole;
    HeaderStyle style;
    std::function<std::pair<int, int>()> keyCallback;

    void clear();

    void displayKeys();
    void displayWin();
    void displayLose();
public:
    explicit Header(std::function<std::pair<int, int>()> cb);
    void display();
    void setWin() { style = HeaderStyle::WIN; display(); }
    void setLose() { style = HeaderStyle::LOSE; display();}
};
