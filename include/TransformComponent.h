#pragma once

#include <SFML/Graphics.hpp>

class TransformComponent
{
private:
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    TransformComponent();
    TransformComponent(sf::Vector2f newPosition, sf::Vector2f newVelocity = {0.f, 0.f});
    
    void SetVelocity(sf::Vector2f newVelocity) { velocity = newVelocity; }
    sf::Vector2f GetVelocity() { return velocity; }
    void SetPosition(sf::Vector2f newPosition) { position = newPosition; }
    sf::Vector2f GetPosition() { return position; }
};
