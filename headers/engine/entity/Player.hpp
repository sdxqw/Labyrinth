#pragma once
#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Entity.hpp"
#include "Spell.hpp"
#include "engine/world/World.hpp"


namespace Labyrinth {
    class Player final : public Entity {
    public:
        explicit Player(const Definition &definition, World &world);

        ~Player() override;

        void draw(sf::RenderWindow &window) const override;

        void handleEvent() override;

        void update(float deltaTime, double totalTime) override;

        void addSpell(std::unique_ptr<Spell>&& spell);

    private:
        sf::RectangleShape rectangle;
        std::vector<std::unique_ptr<Spell> > spells;
        World &world;
        const float speed = 100.0f;
    };
}
