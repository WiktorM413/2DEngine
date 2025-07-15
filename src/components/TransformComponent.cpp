#include "../../include/components/TransformComponent.h"
TransformComponent::TransformComponent()
{
    position = {0.f, 0.f};
    velocity = {0.f, 0.f};
}

TransformComponent::TransformComponent(sf::Vector2f newPosition, sf::Vector2f newVelocity)
{
    position = newPosition;
    velocity = newVelocity;
}

TransformComponent::~TransformComponent() {}
