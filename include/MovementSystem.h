#pragma once

#include <list>
#include "../include/TransformComponent.h"

class MovementSystem
{
private:
    sf::Vector2f gravity;
    float damping;

public:
    MovementSystem();
    MovementSystem(sf::Vector2f newGravity);
    MovementSystem(float newDamping);
    MovementSystem(sf::Vector2f newGravity, float enwDamping);
    void Update(std::list<TransformComponent>& entities, float deltaTime);
};
