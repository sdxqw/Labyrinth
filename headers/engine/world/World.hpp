#pragma once

#include <vector>
#include <memory>

#include "engine/entity/Entity.hpp"

namespace Labyrinth {
    class World {
    public:
        World();

        ~World();

        void addEntity(std::unique_ptr<Entity> entity);

        void handleEvents() const;

        void update(float deltaTime, double totalTime) const;

        void draw(sf::RenderWindow &window) const;

        [[nodiscard]] const std::vector<std::unique_ptr<Entity> > &getEntities() const; // Return a const reference

    private:
        std::vector<std::unique_ptr<Entity> > entities;
    };
}
