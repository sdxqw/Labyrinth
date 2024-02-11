#include <engine/graphics/Renderer.hpp>

namespace Labyrinth {
    void Renderer::draw(sf::RenderWindow &window, const World &world) {
        window.clear();
        world.draw(window);
        window.display();
    }
}
