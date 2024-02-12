namespace Labyrinth {
    class InputHandler {
    public:
        static bool isKeyPressed(const sf::Keyboard::Key key) {
            return sf::Keyboard::isKeyPressed(key);
        }

        static bool isKeyJustPressed(const sf::Keyboard::Key key) {
            return isKeyPressed(key) && !wasKeyPressed(key);
        }

        static bool wasKeyPressed(const sf::Keyboard::Key key) {
            static bool keys[256];
            const auto index = static_cast<int>(key);
            const auto wasPressed = keys[index];
            keys[index] = isKeyPressed(key);
            if (wasPressed) {
                keys[index] = false;
            }
            return wasPressed;
        }
    };
}
