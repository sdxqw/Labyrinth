#include <engine/Engine.hpp>

#include "engine/entity/Player.hpp"

namespace Labyrinth {
    Engine::Engine() {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Labyrinth");
        world = std::make_unique<World>();
    }

    void Engine::cleanup() const {
        window->close();
    }

    void Engine::handleEvents() const {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                cleanup();
            }
            world->handleEvents();
        }
    }

    void Engine::update(const float deltaTime, const double totalTime) const {
        world->update(deltaTime, totalTime);
    }

    bool Engine::isWindowOpen() const {
        return window && window->isOpen();
    }

    sf::RenderWindow &Engine::getWindow() const {
        if (!window) {
            throw std::logic_error("Window is not initialized");
        }
        return *window;
    }

    World &Engine::getWorld() const {
        if (!world) {
            throw std::logic_error("World is not initialized");
        }
        return *world;
    }
}
