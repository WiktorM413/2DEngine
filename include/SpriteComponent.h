#pragma once

#include <SFML/Graphics.hpp>

#include "../include/components/TransformComponent.h"
#include "../include/components/PhysicsBodyComponent.h"

class SpriteComponent
{
private:
    TransformComponent* transform;
    PhysicsBodyComponent* physicsBody; //TODO size of sprites doesnt change. after fixing it link it to this
    sf::Sprite* sprite;
    sf::Texture* texture;
    sf::Vector2f position;
    int zIndex = 0;

public:
    SpriteComponent();
    SpriteComponent(sf::Texture* newTexture);
    SpriteComponent(sf::Sprite& newSprite);
    SpriteComponent(sf::Shape& newShape);
    SpriteComponent(TransformComponent* component);
    SpriteComponent(PhysicsBodyComponent* component);
    ~SpriteComponent();

    void SetTexture(sf::Texture* newTexture);
    sf::Texture* GetTexture() const { return texture; }
    void SetPosition(sf::Vector2f newPosition);
    sf::Vector2f* GetPosition();
    void SetScale(sf::Vector2f newScale) { sprite->setScale(newScale); }
    void SetScale(float targetWidth, float targetHeight);
    sf::Vector2f GetScale() const { return sprite->getScale(); }
    void SetRotation(sf::Angle newRotation) { sprite->setRotation(newRotation); }
    sf::Angle GetRotation() const { return sprite->getRotation(); }
    void SetColor(sf::Color newColor) { sprite->setColor(newColor); }
    sf::Color GetColor() const { return sprite->getColor(); }
    void SetZIndex(int newZIndex) { zIndex = newZIndex; }
    int GetZIndex() const { return zIndex; }
    void SetTransformComponent(TransformComponent* t) { transform = t; }
    TransformComponent* GetTransformComponent() { return transform; }
    void SetPhysicsBodyComponent(PhysicsBodyComponent* p) { physicsBody = p; }
    PhysicsBodyComponent* GetPhysicsBodyComponent() { return physicsBody; }
    void Move(sf::Vector2f movePoint);

    sf::Sprite* GetDrawable();
};
