#include "engine/world/World.hpp"
#include "engine/entity/Player.hpp"

namespace Labyrinth {
    World::World() {
        addEntity(static_cast<std::unique_ptr<Entity>>(new Player(Entity::Definition{10, 10, 10, 10})));
    }

    World::~World() {
    }

    void World::addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }

    void World::handleEvents() const {
        for (auto &entity: entities) {
            entity->handleEvent();
        }
    }

    void World::update(const float deltaTime, const double totalTime) const {
        for (auto &entity: entities) {
            entity->update(deltaTime, totalTime);
        }
    }

    void World::draw(sf::RenderWindow &window) const {
        for (auto &entity: entities) {
            entity->draw(window);
        }
    }

    const std::vector<std::unique_ptr<Entity> > &World::getEntities() const {
        return entities;
    }
}
