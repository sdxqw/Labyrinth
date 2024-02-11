
#include "engine/Engine.hpp"

#include "engine/graphics/Renderer.hpp"

int main() {
    const Labyrinth::Engine engine;

    double t = 0.0f;
    constexpr double dt = 1.0f / 60.0f;

    const sf::Clock clock;
    double currentTime = clock.getElapsedTime().asSeconds();
    while (engine.isWindowOpen()) {
        const double newTime = clock.getElapsedTime().asSeconds();
        double frameTime = newTime - currentTime;
        currentTime = newTime;
        while (frameTime > 0.0f) {
            const auto deltaTime = static_cast<float>(std::min(frameTime, dt));
            engine.update(deltaTime, t);
            frameTime -= deltaTime;
            t += deltaTime;
        }
        engine.handleEvents();
        Labyrinth::Renderer::draw(engine.getWindow(), engine.getWorld());
    }

    engine.cleanup();

    return 0;
}
