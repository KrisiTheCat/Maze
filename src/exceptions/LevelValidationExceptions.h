#pragma once
#include <stdexcept>
#include <string>

class LevelValidationException : public std::runtime_error {
public:
    explicit LevelValidationException(const std::string& message) : std::runtime_error(message) {}
};

class InvalidLevelSize : public LevelValidationException {
public:
    explicit InvalidLevelSize(const std::string& filename) 
        : LevelValidationException("Level file '" + filename + "' has invalid dimensions.") {}
};

class MissingPlayer : public LevelValidationException {
public:
    explicit MissingPlayer(const std::string& filename) 
        : LevelValidationException("Level file '" + filename + "' is missing a player start ('P').") {}
};

class MissingPortal : public LevelValidationException {
public:
    explicit MissingPortal(const std::string& filename) 
        : LevelValidationException("Level file '" + filename + "' is missing a portal ('X').") {}
};

class InvalidCharacter : public LevelValidationException {
public:
    explicit InvalidCharacter(const std::string& filename, char ch) 
        : LevelValidationException("Level file '" + filename + "' contains invalid character: '" + std::string(1, ch) + "'.") {}
};
