#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "world/World.hpp"

namespace Labyrinth {
    class Engine {
    public:
        Engine();

        void handleEvents() const;

        void update(float deltaTime, double totalTime) const;

        void cleanup() const;

        [[nodiscard]] bool isWindowOpen() const;

        [[nodiscard]] sf::RenderWindow &getWindow() const;

        [[nodiscard]] World &getWorld() const;

    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<World> world;
    };
}
