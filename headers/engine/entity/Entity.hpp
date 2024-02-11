#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

namespace Labyrinth {
    class Entity {
    public:
        struct Definition {
            float x;
            float y;
            float width;
            float height;
        };

        struct Directions {
            bool up;
            bool down;
            bool left;
            bool right;
        };

        explicit Entity(Definition definition);

        virtual ~Entity();

        virtual void draw(sf::RenderWindow &window) const = 0;

        virtual void handleEvent() = 0;

        virtual void update(float deltaTime, double totalTime) = 0;

        virtual void cleanup() = 0;

        [[nodiscard]] bool isDead() const;

    protected:
        Definition definition;
        Directions directions = {false, false, false, false};
        bool dead{false};
    };
}
