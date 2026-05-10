#pragma once

#include <memory>
#include <vector>
#include <string>
#include "../config.h"
#include "../objects/Object.h"

struct EntityData {
    char type;
    int x, y;
};

class Level {
    std::vector<std::vector<std::unique_ptr<Object>>> tiles;
public:
    Level();
    void init(const char* layout[LEVEL_H]);
    bool load(const std::string& filename, std::vector<EntityData>& entities);
    static void validate(const std::string& filename);
    bool write(const std::string& filename, const std::vector<EntityData>& entities) const;
    void set(int x, int y, std::unique_ptr<Object> obj);
    Object* get(int x, int y) const;
};
