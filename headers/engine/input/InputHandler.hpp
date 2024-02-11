#pragma once
#include <SFML/Window/Keyboard.hpp>

namespace Labyrinth {
    class InputHandler {
    public:
        static bool isKeyPressed(const sf::Keyboard::Key key) {
            return sf::Keyboard::isKeyPressed(key);
        }
    };
}
