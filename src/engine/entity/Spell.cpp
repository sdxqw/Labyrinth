#include "engine/entity/Spell.hpp"

namespace Labyrinth {
    Spell::Spell(const Definition &definition)
        : Entity(definition) {
        shape.setPointCount(3);
        shape.setPoint(0, sf::Vector2f(definition.x, definition.y));
        shape.setPoint(1, sf::Vector2f(definition.x + definition.width / 2, definition.y + definition.height));
        shape.setPoint(2, sf::Vector2f(definition.x + definition.width, definition.y));
    }

    Spell::~Spell() = default;

    void Spell::draw(sf::RenderWindow &window) const {
        window.draw(shape);
    }

    void Spell::handleEvent() {
    }

    void Spell::update(const float deltaTime, double totalTime) {
        float dx = 0;
        float dy = 0;

        dx += 1 * deltaTime * speed;
        dy += 1 * deltaTime * speed;
        shape.setPosition(dx, dy);

        if (isOutOfBounds()) dead = true;
    }

    bool Spell::isOutOfBounds() const {
        return definition.x > 800 || definition.x < 0 || definition.y > 600 || definition.y < 0;
    }
}
