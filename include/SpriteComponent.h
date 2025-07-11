#pragma once

#include <SFML/Graphics.hpp>

class SpriteComponent
{
private:
    sf::Sprite* sprite;

    sf::Texture* texture;


public:
    SpriteComponent();
    SpriteComponent(sf::Texture* newTexture);
    SpriteComponent(sf::Sprite& newSprite);
    SpriteComponent(sf::Shape& newShape);
    ~SpriteComponent();

    void SetTexture(sf::Texture* newTexture);
    sf::Texture* GetTexture() { return texture; }
    void SetPosition(sf::Vector2f newPosition) { sprite->setPosition(newPosition); }
    sf::Vector2f GetPosition() { return sprite->getPosition(); }
    void SetScale(sf::Vector2f newScale) { sprite->setScale(newScale); }
    void SetScale(float targetWidth, float targetHeight);
    sf::Vector2f GetScale() { return sprite->getScale(); }
    void SetRotation(sf::Angle newRotation) { sprite->setRotation(newRotation); }
    sf::Angle GetRotation() { return sprite->getRotation(); }
    void SetColor(sf::Color newColor) { sprite->setColor(newColor); }
    sf::Color GetColor() { return sprite->getColor(); }

    sf::Sprite* GetDrawable();
};
