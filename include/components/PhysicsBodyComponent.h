#pragma once

#include <SFML/System/Vector2.hpp>
#include "Component.h"

class PhysicsBodyComponent : public Component
{
private:
    sf::Vector2f size;
    bool isStatic = false;
    bool isColliding = false;

public:
    PhysicsBodyComponent(sf::Vector2f newSize);
    ~PhysicsBodyComponent();

    sf::Vector2f GetSize() { return size; }
    void SetSize(sf::Vector2f newSize) { size = newSize; }
};
