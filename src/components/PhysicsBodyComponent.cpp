#include "../../include/components/PhysicsBodyComponent.h"
#include "../../include/SpriteComponent.h"

PhysicsBodyComponent::PhysicsBodyComponent(SpriteComponent* newOwner)
{
    owner = newOwner;
}

PhysicsBodyComponent::~PhysicsBodyComponent() {}

sf::Vector2f PhysicsBodyComponent::GetSize()
{
    return owner->GetSize();
}
void PhysicsBodyComponent::SetSize(sf::Vector2f newSize)
{
    owner->SetSize(newSize);
}
