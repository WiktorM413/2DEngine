#include "../include/SpriteComponent.h"

#include <iostream>


SpriteComponent::SpriteComponent(sf::Texture* newTexture)
{
    texture = newTexture;
    sprite = new sf::RectangleShape();
    sprite->setSize({(float)texture->getSize().x, (float)texture->getSize().y});
    sprite->setTexture(texture);
    transform = nullptr;
    physicsBody = nullptr;
    size = new sf::Vector2f(texture->getSize());
}

SpriteComponent::SpriteComponent(sf::Sprite& newSprite)
{
    texture = new sf::Texture(newSprite.getTexture());
    sprite = new sf::RectangleShape();
    sprite->setSize({(float)texture->getSize().x, (float)texture->getSize().y});
    sprite->setTexture(texture);

    transform = nullptr;
    physicsBody = nullptr;
    size = new sf::Vector2f(texture->getSize());
}

SpriteComponent::SpriteComponent(sf::Shape& newShape)
{
    sf::RenderTexture renderTexture;
    renderTexture.clear(sf::Color::Transparent);
    renderTexture.draw(newShape);
    
    texture = new sf::Texture(renderTexture.getTexture());
    sprite->setSize({(float)texture->getSize().x, (float)texture->getSize().y});
    sprite->setTexture(texture);
    
    transform = nullptr;
    physicsBody = nullptr;
    size = new sf::Vector2f(texture->getSize());
}

SpriteComponent::~SpriteComponent()
{
    delete sprite;
    delete texture;
    delete size;
}

void SpriteComponent::SetSize(sf::Vector2f newSize)
{
    *size = newSize;
    
}

void SpriteComponent::SetTexture(sf::Texture* newTexture)
{
    texture = newTexture;
    if (sprite != nullptr)
    {
        sprite->setSize({(float)texture->getSize().x, (float)texture->getSize().y});
        sprite->setTexture(texture);
    }
    else
    {
        sprite = new sf::RectangleShape();
        sprite->setSize({(float)texture->getSize().x, (float)texture->getSize().y});
        sprite->setTexture(texture);
    }
}

void SpriteComponent::SetPosition(sf::Vector2f newPosition)
{
    position = newPosition;
    sprite->setPosition(position);
}

sf::Vector2f* SpriteComponent::GetPosition()
{
    return &position;
}

void SpriteComponent::SetScale(float targetWidth, float targetHeight)
{
    sf::Vector2 textureSize = texture->getSize();

    float scaleX = targetWidth / textureSize.x;
    float scaleY = targetHeight / textureSize.y;

    float newScale = std::min(scaleX, scaleY);

    sprite->setScale({newScale, newScale});
}

void SpriteComponent::SpriteComponent::Move(sf::Vector2f movePoint)
{
    position += movePoint;
    transform->SetPosition(position);

}

sf::RectangleShape* SpriteComponent::GetDrawable()
{
    return sprite;
}
