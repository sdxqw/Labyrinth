#include "engine/entity/Spell.hpp"

namespace Labyrinth {
    Spell::Spell(const Definition &definition, const Directions &directions)
        : Entity(definition), direction(directions) {
        shape.setSize({definition.width, definition.height});
        shape.setPosition(definition.x, definition.y);
        shape.setFillColor(sf::Color::Green);
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

        if (direction.up && direction.right) {
            dx += 1 * deltaTime * speed;
            dy -= 1 * deltaTime * speed;
        } else if (direction.up && direction.left) {
            dx -= 1 * deltaTime * speed;
            dy -= 1 * deltaTime * speed;
        } else if (direction.down && direction.right) {
            dx += 1 * deltaTime * speed;
            dy += 1 * deltaTime * speed;
        } else if (direction.down && direction.left) {
            dx -= 1 * deltaTime * speed;
            dy += 1 * deltaTime * speed;
        } else if (direction.up) {
            dy -= 1 * deltaTime * speed;
        } else if (direction.down) {
            dy += 1 * deltaTime * speed;
        } else if (direction.left) {
            dx -= 1 * deltaTime * speed;
        } else if (direction.right) {
            dx += 1 * deltaTime * speed;
        }

        definition.x += dx;
        definition.y += dy;

        shape.move(dx, dy);

        if (isOutOfBounds()) {
            dead = true;
        }
    }

    bool Spell::isOutOfBounds() const {
        return definition.x > 800 || definition.x < 0 || definition.y > 600 || definition.y < 0;
    }
}
