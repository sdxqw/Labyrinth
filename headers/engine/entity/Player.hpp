#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Entity.hpp"

namespace Labyrinth {
    class Player final : public Entity {
    public:
        explicit Player(const Definition &definition);

        ~Player() override;

        void draw(sf::RenderWindow &window) const override;

        void handleEvent() override;

        void update(float deltaTime, double totalTime) override;

        void cleanup() override;

    private:
        sf::RectangleShape rectangle;
        const float speed = 100.0f;
    };
}
