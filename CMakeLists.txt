cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        src/main.cpp
        src/config.h
        src/Pixel.h
        src/Sprite.h
        src/Sprite.cpp
        src/SpriteManager.h
        src/SpriteManager.cpp
        src/Level.h
        src/Level.cpp
        src/GameState.h
        src/GameState.cpp
        src/display/Renderer.h
        src/display/Renderer.cpp
        src/objects/Object.h
        src/objects/Object.cpp
        src/objects/Empty.h
        src/objects/Wall.h
        src/objects/Portal.h
        src/objects/Portal.cpp
        src/objects/Key.h
        src/objects/Smoke.h
        src/objects/Smoke.cpp
        src/objects/Entity.h
        src/objects/Entity.cpp
        src/objects/Player.h
        src/objects/Player.cpp
        src/objects/Enemy.h
        src/objects/Enemy.cpp
        src/objects/Chaser.h
        src/objects/Chaser.cpp
        src/objects/Slime.h
        src/objects/Slime.cpp
        src/LevelManager.h
        src/LevelManager.cpp
        src/objects/interfaces/Collidable.h
        src/objects/interfaces/Triggerable.h
        src/objects/interfaces/Movable.h
        src/objects/interfaces/Pickable.h
        src/GameController.h
        src/exceptions/UnexpectedCommand.h
        src/display/Logger.cpp
        src/display/Logger.h
        src/display/Header.cpp
        src/display/Header.h
        src/display/HeaderStyle.h
)

file(COPY resources/sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY resources/levels DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
