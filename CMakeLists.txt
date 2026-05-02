cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        main.cpp
        config.h
        Pixel.h
        Sprite.h
        Sprite.cpp
        SpriteManager.h
        SpriteManager.cpp
        Renderer.h
        Renderer.cpp
        objects/Object.h
        objects/Object.cpp
        objects/Empty.h
        objects/Empty.cpp
        objects/Wall.h
        objects/Wall.cpp
        objects/Portal.h
        objects/Portal.cpp
        objects/Pickable.h
        objects/Pickable.cpp
        objects/Key.h
        objects/Key.cpp
        objects/Smoke.h
        objects/Smoke.cpp
        objects/Character.h
        objects/Character.cpp
        objects/Player.h
        objects/Player.cpp
        objects/Enemy.h
        objects/Enemy.cpp
        objects/Chaser.h
        objects/Chaser.cpp
        objects/Slime.h
        objects/Slime.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
