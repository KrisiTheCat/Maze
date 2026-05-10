
#include "Header.h"

#include <iomanip>
#include <iostream>

using namespace std;

Header::Header(std::function<std::pair<int, int>()> cb) 
    : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), style(HeaderStyle::KEYS), keyCallback(std::move(cb)) {}


void Header::clear() {
    COORD topLeft = { 0, 0 };
    SetConsoleCursorPosition(hConsole, topLeft);
    for (int i = 0; i <= HEADER_HEIGHT; ++i) {
        cout << string(HEADER_WIDTH+5, ' ') << endl;
    }
    SetConsoleCursorPosition(hConsole, topLeft);
}

void Header::display() {
    clear();
    switch (style) {
        case HeaderStyle::KEYS:
            displayKeys();
            break;
        case HeaderStyle::WIN:
            displayWin();
            break;
        case HeaderStyle::LOSE:
            displayLose();
            break;
    }
}
void Header::displayKeys() {
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    auto [collected, total] = keyCallback();
    float percentage = (total > 0) ? (static_cast<float>(collected) / total) * 100.0f : 0.0f;

    int labelWidth = 13;
    int barWidth = HEADER_WIDTH - labelWidth;
    int filledWidth = static_cast<int>((percentage / 100.0f) * barWidth);

    cout << (char)218;
    for (int i = 0; i < HEADER_WIDTH; ++i) cout << (char)196;
    cout << (char)191 << endl;

    cout << (char)179 << " ";
    for (int i = 0; i < barWidth; ++i) {
        if (i < filledWidth) cout << (char)219;
        else cout << (char)176;
    }
    cout << setw(3) << static_cast<int>(percentage) << "% COMPL. " << (char)179 << endl;

    string keys = "{ " + to_string(collected) + " / " + to_string(total) + " }";
    int leftDashes = 15;
    int rightDashes = HEADER_WIDTH - leftDashes - static_cast<int>(keys.length());

    cout << (char)192;
    for (int i = 0; i < leftDashes; ++i) cout << (char)196;
    cout << keys;
    for (int i = 0; i < rightDashes; ++i) cout << (char)196;
    cout << (char)217 << endl;
}

void Header::displayWin() {
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\nCONGRATULATIONS! YOU ESCAPED THE MAZE!\n";
    cout << "\tPress Q to exit.\n";
}

void Header::displayLose() {
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\nGAME OVER! YOU WERE CAUGHT!\n";
    cout << "\tPress Q to exit.\n";
}