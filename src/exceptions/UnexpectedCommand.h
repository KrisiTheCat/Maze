#pragma once

class UnexpectedCommand : public std::invalid_argument {
public:
    UnexpectedCommand() : invalid_argument("Unexpected command typed") {
    }
};