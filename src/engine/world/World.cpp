#include "engine/world/World.hpp"
#include "engine/entity/Player.hpp"

namespace Labyrinth {
    World::World() {
        addEntity(std::make_unique<Player>(Entity::Definition{10, 10, 32, 32}, *this));
    }

    World::~World() {
        entities.clear();
    }

    void World::addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }

    void World::handleEvents() const {
        for (auto &entity: entities) {
            entity->handleEvent();
        }
    }

    void World::update(const float deltaTime, const double totalTime) {
        entities.erase(std::remove_if(entities.begin(), entities.end(),
                                      [](const std::unique_ptr<Entity> &entity) {
                                          return entity->isDead();
                                      }), entities.end());

        for (const auto &entity: entities) {
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
