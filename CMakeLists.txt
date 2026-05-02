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
        Object.h
        Object.cpp
        Renderer.h
        Renderer.cpp
)

# Use file(COPY ...) to ensure any changes in the text files are always synced
# over to the cmake-build-debug output directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
