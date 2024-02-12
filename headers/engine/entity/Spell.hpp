#pragma once
#include <SFML/Graphics/ConvexShape.hpp>

#include <engine/entity/Entity.hpp>

namespace Labyrinth {
    class Spell final : public Entity {
    public:
        explicit Spell(const Definition &definition);

        ~Spell() override;

        void draw(sf::RenderWindow &window) const override;

        void handleEvent() override;

        void update(float deltaTime, double totalTime) override;

        [[nodiscard]]bool isOutOfBounds() const;

    private:
        sf::ConvexShape shape;
        float speed = 100.0f;
    };
}
