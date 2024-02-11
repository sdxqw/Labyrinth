#include "engine/entity/Player.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "engine/input/InputHandler.hpp"

namespace Labyrinth {
    Player::Player(const Definition &definition): Entity(definition) {
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
    }

    void Player::update(const float deltaTime, const double totalTime) {
        float dx = 0;
        float dy = 0;
        directions.right ? dx += 1 : dx += 0;
        directions.left ? dx -= 1 : dx += 0;
        directions.up ? dy -= 1 : dy += 0;
        directions.down ? dy += 1 : dy += 0;
        rectangle.move(dx * deltaTime * speed, dy * deltaTime * speed);
    }

    void Player::cleanup() {
    }
}
