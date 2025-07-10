#pragma once

#include <SFML/Graphics.hpp>


class SpriteComponent
{
private:
    sf::Texture* texture;
    sf::Vector2f* position;
    sf::Vector2f* scale; 
    sf::Angle* rotation;

public:
    SpriteComponent();
    SpriteComponent(sf::Texture& newTexture);
    SpriteComponent(sf::Sprite& newSprite);
    SpriteComponent(sf::Shape& newShape);
    ~SpriteComponent();

    void SetTexture(sf::Texture newTexture) { *texture = newTexture; }
    sf::Texture GetTexture() { return *texture; }
    void SetPosition(sf::Vector2f& newPosition) { *position = newPosition; }
    sf::Vector2f GetPosition() { return *position; }
    void SetScale(sf::Vector2f& newScale) { *scale = newScale; }
    sf::Vector2f GetScale() { return *scale; }
    void SetRotation(sf::Angle& newRotation) { *rotation = newRotation; }
    sf::Angle GetRotation() { return *rotation; }

    sf::Sprite* GetDrawable();
};
