#pragma once
#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Entity.hpp"
#include "Spell.hpp"


namespace Labyrinth {
    class World;
    class Player final : public Entity {

    public:
        explicit Player(const Definition &definition, World &world);

        ~Player() override;

        void draw(sf::RenderWindow &window) const override;

        void handleEvent() override;

        void update(float deltaTime, double totalTime) override;

        std::unique_ptr<Spell> castSpell() const;

    private:
        sf::RectangleShape rectangle;
        World &world;
        const float speed = 100.0f;
    };
}
