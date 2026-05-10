#pragma once
#include <windows.h>
#include <string>

class Logger {
    static short currLine;
    static short maxLine;
    static short offset;
    static HANDLE hConsole;
    static void log(const std::string& level, const WORD color, const std::string& message);
public:
    static void init();
    static void info(const std::string& message);
    static void warn(const std::string& message);
    static void warn(const std::string& message, const std::exception& e) ;
    static void error(const std::string& message, const std::exception& e) ;
};
