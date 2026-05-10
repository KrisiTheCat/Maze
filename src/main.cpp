#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "config.h"
#include "display/sprites/SpriteManager.h"
#include "display/Renderer.h"
#include "GameState.h"
#include "levels/LevelManager.h"
#include "display/Header.h"
#include "exceptions/UnexpectedCommand.h"
#include "display/Logger.h"

bool askUser(const std::string& question) {
    std::cout << "\n" << question << " (Y/N): ";
    std::string response;
    std::cin >> response;
    std::transform(response.begin(), response.end(), response.begin(), ::tolower);
    return response == "y" || response == "yes";
}

void setCursorPosition(int x, int y) {
    static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, coord);
}

void setTextColor(WORD color) {
    static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    Logger::init();
  //  return 0;
    SpriteManager spriteManager;
    LevelManager levelManager;
    try {
        spriteManager.loadAllSprites();
        levelManager.discoverLevels();
    } catch (const std::exception& e) {
        Logger::error("Initialization Error", e);
       // return 1;
    }
    Logger::info("Initialization success");

    GameState state;

    Header header([&state]() {
        return std::make_pair(state.getKeysCollected(), state.getKeysTotal());
    });

    state.setGameOverCallback([&header](bool win) {
        if (win) header.setWin();
        else header.setLose();
    });

    const std::vector<std::string>& levelFiles = levelManager.getLevels();
    if (levelFiles.empty()) {
        std::cerr << "No levels found in levels/ directory!\n";
        return 1;
    }

    int selection = 0;
    bool choosing = true;

    
    while (choosing) {
        setCursorPosition(0, 0);
        std::cout << "--- SELECT LEVEL ---\n\n";
        
        for (int i = 0; i < (int)levelFiles.size(); ++i) {
            std::string displayName = levelManager.getDisplayName(levelFiles[i]);

            if (i == selection) {
                setTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << " > " << displayName << "   \n";
                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset
            } else {
                std::cout << "   " << displayName << "   \n";
            }
        }
        
        std::cout << "\n(Use W/S or Arrow Keys, Enter to Select)\n";

        int ch = _getch();
        if (ch == 0 || ch == 224) {
            ch = _getch();
            if (ch == 72) { // Up
                selection = (selection - 1 + levelFiles.size()) % levelFiles.size();
            } else if (ch == 80) { // Down
                selection = (selection + 1) % levelFiles.size();
            }
        } else {
            ch = tolower(ch);
            if (ch == 'w') {
                selection = (selection - 1 + levelFiles.size()) % levelFiles.size();
            } else if (ch == 's') {
                selection = (selection + 1) % levelFiles.size();
            } else if (ch == 13) { // Enter
                choosing = false;
            }
        }
    }

    std::string selectedFile = levelFiles[selection];
    std::string selectedPath = levelManager.getLevelPath(selectedFile);
    
    if (state.loadLevel(selectedPath)) {
        Logger::info("Level loaded successfully.");
    } else {
        Logger::warn("Failed to load " + selectedPath + ", using default layout.");
    }

    Renderer renderer(spriteManager);

    boolean shouldRerender = true;

    while (state.isRunning()) {
        if (shouldRerender) {
            header.display();
            renderer.render(state);
        }
        shouldRerender = true;

        int ch;
        ch = _getch();
        ch = tolower(ch);

        try {
            state.tick(static_cast<Command>(ch));
        } catch (const UnexpectedCommand& e) {
            Logger::warn("User input", e);
            shouldRerender = false;
        }
    }

    header.display();
    renderer.render(state);

    int ch;

    ch = _getch();
    ch = tolower(ch);
    while (ch != 'q') {
        ch = _getch();
        ch = tolower(ch);
    }

    return 0;
}
