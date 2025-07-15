#pragma once

#include <list>
#include "../include/components/TransformComponent.h"

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
    void SetDamping(float newDamping) { damping = newDamping; }
    float GetDamping() { return damping; }
    void SetGravity(sf::Vector2f newGravity) { gravity = newGravity; }
    sf::Vector2f GetGravity() { return gravity; }
    void Update(TransformComponent* component, float deltaTime);
};
