#include "../include/SpriteComponent.h"

SpriteComponent::SpriteComponent(sf::Texture& newTexture)
{
    texture = new sf::Texture(newTexture);
    position = new sf::Vector2f();
    scale = new sf::Vector2f();
    rotation = new sf::Angle();
}

SpriteComponent::SpriteComponent(sf::Sprite& newSprite)
{
    texture = new sf::Texture(newSprite.getTexture());
    position = new sf::Vector2f();
    scale = new sf::Vector2f();
    rotation = new sf::Angle();
}

SpriteComponent::SpriteComponent(sf::Shape& newShape)
{
    sf::RenderTexture renderTexture;
    renderTexture.clear(sf::Color::Transparent);
    renderTexture.draw(newShape);
    
    texture = new sf::Texture(renderTexture.getTexture());
    position = new sf::Vector2f();
    scale = new sf::Vector2f();
    rotation = new sf::Angle();
}

SpriteComponent::~SpriteComponent()
{
    delete texture;
    delete position;
    delete scale;
    delete rotation;
}
