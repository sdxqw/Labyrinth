#include "engine/entity/Player.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "engine/input/InputHandler.hpp"
#include "engine/world/World.hpp"

namespace Labyrinth {
    Player::Player(const Definition &definition, World &world): Entity(definition), world(world) {
        rectangle.setSize(sf::Vector2f(definition.width, definition.height));
        rectangle.setPosition(definition.x, definition.y);
        rectangle.setFillColor(sf::Color::Red);
    }

    Player::~Player() = default;

    void Player::draw(sf::RenderWindow &window) const {
        window.draw(rectangle);
    }

    void Player::handleEvent() {
        directions.right = InputHandler::isKeyPressed(sf::Keyboard::D);
        directions.left = InputHandler::isKeyPressed(sf::Keyboard::A);
        directions.up = InputHandler::isKeyPressed(sf::Keyboard::W);
        directions.down = InputHandler::isKeyPressed(sf::Keyboard::S);
        if (InputHandler::isKeyJustPressed(sf::Keyboard::Space)) {
            addSpell(std::make_unique<Spell>(definition, directions));
        }
    }

    void Player::update(const float deltaTime, const double totalTime) {
        float dx = 0;
        float dy = 0;
        directions.right ? dx += 1 : dx += 0;
        directions.left ? dx -= 1 : dx += 0;
        directions.up ? dy -= 1 : dy += 0;
        directions.down ? dy += 1 : dy += 0;
        definition.x += dx * deltaTime * speed;
        definition.y += dy * deltaTime * speed;
        rectangle.move(dx * deltaTime * speed, dy * deltaTime * speed);

        if (!spells.empty()) {
            for (std::unique_ptr<Spell> &spell: spells) {
                if (spell != nullptr)
                    world.addEntity(std::move(spell));
            }
        }
    }

    void Player::addSpell(std::unique_ptr<Spell> &&spell) {
        spells.push_back(std::move(spell));
    }
}
