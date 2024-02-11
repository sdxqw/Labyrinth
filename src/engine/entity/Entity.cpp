#include <engine/entity/Entity.hpp>

namespace Labyrinth {
    Entity::Entity(const Definition definition) : definition(definition) {
    }

    Entity::~Entity() = default;

    bool Entity::isDead() const {
        return dead;
    }
}
