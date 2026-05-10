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
        Level.h
        Level.cpp
        GameState.h
        GameState.cpp
        display/Renderer.h
        display/Renderer.cpp
        objects/Object.h
        objects/Object.cpp
        objects/Empty.h
        objects/Wall.h
        objects/Portal.h
        objects/Portal.cpp
        objects/Key.h
        objects/Key.cpp
        objects/Smoke.h
        objects/Smoke.cpp
        objects/Entity.h
        objects/Entity.cpp
        objects/Player.h
        objects/Player.cpp
        objects/Enemy.h
        objects/Enemy.cpp
        objects/Chaser.h
        objects/Chaser.cpp
        objects/Slime.h
        objects/Slime.cpp
        LevelManager.h
        LevelManager.cpp
        objects/Item.h
        objects/interfaces/Collidable.h
        objects/interfaces/Triggerable.h
        objects/interfaces/Movable.h
        objects/interfaces/Pickable.h
        GameController.h
        effects/InteractionEffect.h
        effects/VictoryEffect.h
        effects/GameOverEffect.h
        exceptions/UnexpectedCommand.h
        display/Logger.cpp
        display/Logger.h
)

file(COPY resources/sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY resources/levels DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
