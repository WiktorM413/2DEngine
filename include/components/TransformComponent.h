#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"

class TransformComponent : public Component
{
private:
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    TransformComponent();
    TransformComponent(sf::Vector2f newPosition, sf::Vector2f newVelocity = {0.f, 0.f});
    ~TransformComponent();
    
    void SetVelocity(sf::Vector2f newVelocity) { velocity = newVelocity; }
    sf::Vector2f GetVelocity() { return velocity; }
    void SetPosition(sf::Vector2f newPosition) { position = newPosition; }
    sf::Vector2f GetPosition() { return position; }
};
