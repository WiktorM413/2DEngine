#include "../include/SpriteComponent.h"

#include <iostream>

SpriteComponent::SpriteComponent()
{
    sprite = nullptr;
    texture = new sf::Texture();
}

SpriteComponent::SpriteComponent(sf::Texture* newTexture)
{
    texture = newTexture;
    sprite = new sf::Sprite(*texture);
}

SpriteComponent::SpriteComponent(sf::Sprite& newSprite)
{
    sprite = new sf::Sprite(newSprite);
    texture = new sf::Texture(sprite->getTexture());
}

SpriteComponent::SpriteComponent(sf::Shape& newShape)
{
    sf::RenderTexture renderTexture;
    renderTexture.clear(sf::Color::Transparent);
    renderTexture.draw(newShape);
    
    sprite = new sf::Sprite(renderTexture.getTexture());
    texture = new sf::Texture(sprite->getTexture());
}

SpriteComponent::~SpriteComponent()
{
    delete sprite;
    delete texture;
}

void SpriteComponent::SetTexture(sf::Texture* newTexture)
{
    texture = newTexture;
    if (sprite != nullptr)
    {
        sprite->setTexture(*texture);
    }
    else
    {
        sprite = new sf::Sprite(*texture);
    }
}

void SpriteComponent::SetScale(float targetWidth, float targetHeight)
{
    sf::Vector2 textureSize = texture->getSize();

    float scaleX = targetWidth / textureSize.x;
    float scaleY = targetHeight / textureSize.y;

    float newScale = std::min(scaleX, scaleY);

    sprite->setScale({newScale, newScale});
}

sf::Sprite* SpriteComponent::GetDrawable()
{
    return sprite;
}
