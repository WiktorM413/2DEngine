#include "../include/SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
    texture = new sf::Texture();
    position = new sf::Vector2f();
    scale = new sf::Vector2f();
    rotation = new sf::Angle();
}

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

sf::Sprite* SpriteComponent::GetDrawable()
{
    sf::Sprite* sprite = new sf::Sprite(*texture);
    sprite->setPosition(*position);
    sprite->setScale(*scale);
    sprite->setRotation(*rotation);

    return sprite;
}
