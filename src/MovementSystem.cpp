#include "../include/MovementSystem.h"

MovementSystem::MovementSystem()
{
    gravity = {0.f, 0.f};
    damping = 1.f;
}

MovementSystem::MovementSystem(sf::Vector2f newGravity)
{
    gravity = newGravity;
    damping = 1.f;
}

MovementSystem::MovementSystem(float newDamping)
{
    gravity = {0.f, 0.f};
    damping = newDamping;
}

MovementSystem::MovementSystem(sf::Vector2f newGravity, float newDamping)
{
    gravity = newGravity;
    damping = newDamping;
}

void MovementSystem::Update(TransformComponent* component, float deltaTime)
{
    //uncomment for gravity to work
    //component.SetVelocity(component.GetVelocity() + (gravity * deltatime));
    sf::Vector2f displacement = component->GetVelocity() * deltaTime;
    component->SetPosition(component->GetPosition() + displacement);
    component->SetVelocity(component->GetVelocity() * damping);
}
