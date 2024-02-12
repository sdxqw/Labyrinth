#pragma once

#include <engine/entity/Entity.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace Labyrinth {
    class Spell final : public Entity {
    public:
        explicit Spell(const Definition &definition, const Directions &directions);

        ~Spell() override;

        void draw(sf::RenderWindow &window) const override;

        void handleEvent() override;

        void update(float deltaTime, double totalTime) override;

        [[nodiscard]] bool isOutOfBounds() const;

    private:
        Directions direction;
        sf::RectangleShape shape;
        float speed = 100.0f;
    };
}
