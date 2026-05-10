#include "Logger.h"
#include <iostream>
#include "../config.h"

using namespace std;

short Logger::maxLine = 500;
short Logger::offset = 120;
short Logger::currLine = 0;
HANDLE Logger::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Logger::init() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;

    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 10;

    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    wcscpy_s(cfi.FaceName, L"Terminal");

    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    short bufW = 250;
    short bufH = 1000;
    COORD bSize = { bufW, bufH };
    SetConsoleScreenBufferSize(hConsole, bSize);

    short winWidth = bufW - 1;
    short winHeight = 95;
    SMALL_RECT windowSize = { 0, 0, winWidth, winHeight };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    COORD origin = { offset, 0 };
    SetConsoleCursorPosition(hConsole, origin);

    cout << "------------------------LOGS-------------------------\n";
    currLine++;
}

void Logger::log(const string& level, const WORD color, const string& message) {
    COORD coord = { offset, currLine };
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, color);
    cout << "["<<level<<"] ";
    SetConsoleTextAttribute(hConsole, 15);
    cout << message << endl;

    currLine++;
    if (currLine >= maxLine) {
        currLine = 1;
    }
}


void Logger::info(const string& message) {
    log("INFO", DB, message);
}
void Logger::warn(const string& message) {
    log("WARN", YL, message);
}
void Logger::warn(const string& message, const exception& e) {
    log("WARN", YL, format("{}: {}", message, e.what()));
}
void Logger::error(const string& message, const exception& e) {
    log("ERROR", DR, format("{}: {}", message, e.what()));
}