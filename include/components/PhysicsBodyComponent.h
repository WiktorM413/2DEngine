#pragma once

#include <SFML/System/Vector2.hpp>
#include "Component.h"

class SpriteComponent;

class PhysicsBodyComponent : public Component
{
private:
    SpriteComponent* owner;
    bool isStatic = false;
    bool isColliding = false;

public:
    PhysicsBodyComponent(SpriteComponent* newOwner);
    ~PhysicsBodyComponent();

    sf::Vector2f GetSize();
    void SetSize(sf::Vector2f newSize);
};
