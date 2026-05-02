#include "Sprite.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

WORD stringToColor(const std::string& str) {
    if (str == "BK") return BK;
    if (str == "WH") return WH;
    if (str == "RD") return RD;
    if (str == "DR") return DR;
    if (str == "CY") return CY;
    if (str == "GN") return GN;
    if (str == "YL") return YL;
    if (str == "MG") return MG;
    if (str == "PC") return PC;
    if (str == "GY") return GY;
    if (str == "DG") return DG;
    if (str == "DB") return DB;
    if (str == "DP") return DP;
    throw std::runtime_error("Invalid color macro: " + str);
}

Sprite::Sprite() {
    for (int r = 0; r < SPRITE_ROWS; ++r) {
        for (int c = 0; c < SPRITE_COLS; ++c) {
            data[r][c] = { BK, ' ' };
        }
    }
}

void Sprite::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open sprite file: " + filename);
    }

    for (int r = 0; r < SPRITE_ROWS; ++r) {
        for (int c = 0; c < SPRITE_COLS; ++c) {
            std::string colorStr;
            int asciiCode;

            if (!(file >> colorStr >> asciiCode)) {
                throw std::runtime_error("Invalid file format or missing data in: " + filename + " at Row " + std::to_string(r) + " Col " + std::to_string(c));
            }

            if (asciiCode < 0 || asciiCode > 255) {
                throw std::runtime_error("Invalid ASCII code in: " + filename + " Code: " + std::to_string(asciiCode));
            }

            data[r][c].attribute = stringToColor(colorStr);
            data[r][c].symbol = (unsigned char)asciiCode;
        }
    }

    std::string extra;
    if (file >> extra) {
        throw std::runtime_error("Sprite file has too many elements (expected " +
                                 std::to_string(SPRITE_ROWS * SPRITE_COLS) + "): " + filename + " (Found extra: " + extra + ")");
    }
}