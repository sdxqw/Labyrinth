cmake_minimum_required(VERSION 3.27)
project(Labyrinth)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR} headers)

add_executable(Labyrinth
        src/main.cpp
        src/engine/Engine.cpp
        src/engine/graphics/Renderer.cpp
        headers/engine/entity/Entity.hpp
        src/engine/entity/Player.cpp
        headers/engine/entity/Player.hpp
        src/engine/entity/Entity.cpp
        headers/engine/world/World.hpp
        src/engine/world/World.cpp
        headers/engine/input/InputHandler.hpp
)

target_link_libraries(Labyrinth
        sfml-graphics
        sfml-window
        sfml-system
)
