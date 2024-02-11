#pragma once

#include <SFML/Graphics.hpp>

#include "engine/world/World.hpp"

namespace Labyrinth {
    class Renderer final {
    public:
        static void draw(sf::RenderWindow &window, const World &world);
    };
}
