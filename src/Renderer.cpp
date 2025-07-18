#include "../include/Renderer.h"

#include "../include/Log.h"
#include "../include/Settings.h"
#include <filesystem>
#include <string>
#include <cmath>
#include <limits.h>

Renderer::Renderer(sf::RenderWindow* newW, sf::Color newClearColor)
{
    w = newW;
    clearColor = newClearColor;
}

Renderer::~Renderer()
{
    for (SpriteComponent* sprite : sprites)
    {
        delete sprite;
    }
    for (Component* component : components)
    {
        delete component;
    }
}

void Renderer::draw()
{
    if (w == nullptr)
    {
        FMT::warn("Warning - null reference in Renderer");
        return;
    }
    w->clear();

    sprites.sort([](const SpriteComponent* a, const SpriteComponent* b)
    {
       return a->GetZIndex() < b->GetZIndex(); 
    });
    for (SpriteComponent* sprite : sprites)
    {
        w->draw(*(sprite->GetDrawable()));
    }

    for (sf::Text* text : texts)
    {
        w->draw(*text);
    }

    w->display();
}
void Renderer::draw(sf::RenderWindow* w)
{
    if (w == nullptr)
    {
        FMT::warn("Warning - null reference in Renderer");
        return;
    }
    w->clear();

    sprites.sort([](const SpriteComponent* a, const SpriteComponent* b)
    {
       return a->GetZIndex() < b->GetZIndex(); 
    });
    for (SpriteComponent* sprite : sprites)
    {
        w->draw(*(sprite->GetDrawable()));
    }

    for (sf::Text* text : texts)
    {
        w->draw(*text);
    }

    w->display();
}

SpriteComponent* Renderer::RenderSprite(sf::Texture* texture)
{
    SpriteComponent* sprite = new SpriteComponent(texture);
    sprites.push_back(sprite);
    return sprite;
}

SpriteComponent* Renderer::RenderSprite(const char* path)
{
    const std::string s = path;
    const std::filesystem::path filename(s);
    sf::Texture* texture = new sf::Texture();
    
    if (texture->loadFromFile(filename))
    {
        SpriteComponent* sprite = new SpriteComponent(texture);
        sprites.push_back(sprite);
        return sprite;
    }
     
    FMT::warn("Failed to loead texture from file: " + filename.string());
    return nullptr;
}

SpriteComponent* Renderer::RenderSprite(const std::filesystem::path& filename)
{
    sf::Texture* texture = new sf::Texture();
    
    if (texture->loadFromFile(filename))
    {
        SpriteComponent* newSprite = new SpriteComponent(texture);
        sprites.push_back(newSprite);
    }
    
    SpriteComponent* sprite = new SpriteComponent(texture);
    return sprite;
}

SpriteComponent* Renderer::RenderShape(const Shapes::Circle&, float radius, std::size_t pointCount)
{
    sf::CircleShape shape(radius, pointCount);

    unsigned int size = static_cast<unsigned int>(std::ceil(radius * 2));
    sf::RenderTexture renderTexture({size, size});
    renderTexture.clear();
    renderTexture.draw(shape);
    renderTexture.display();

    sf::Texture* texture = new sf::Texture(renderTexture.getTexture());
    SpriteComponent* sprite = new SpriteComponent(texture);

    sprites.push_back(sprite);

    return sprite;
}

SpriteComponent* Renderer::RenderShape(const Shapes::Rectangle&, sf::Vector2f size)
{
    sf::RectangleShape shape(size);
    
    sf::RenderTexture renderTexture({static_cast<unsigned int>(std::ceil(size.x)), static_cast<unsigned int>(std::ceil(size.y))});
    renderTexture.clear();
    renderTexture.draw(shape);
    renderTexture.display();

    sf::Texture* texture = new sf::Texture(renderTexture.getTexture());

    SpriteComponent* sprite = new SpriteComponent(texture);

    sprites.push_back(sprite);

    return sprite;
}

SpriteComponent* Renderer::RenderShape(const Shapes::Rectangle&, float width, float height)
{
    sf::RectangleShape shape({width, height});
    
    sf::RenderTexture renderTexture({static_cast<unsigned int>(std::ceil(width)), static_cast<unsigned int>(std::ceil(height))});
    renderTexture.clear();
    renderTexture.draw(shape);
    renderTexture.display();

    sf::Texture* texture = new sf::Texture(renderTexture.getTexture());

    SpriteComponent* sprite = new SpriteComponent(texture);

    sprites.push_back(sprite);

    return sprite;
}

sf::Text* Renderer::RenderText(const sf::Font& font, std::string s, uint8_t fontSize, sf::Color color)
{
    sf::Text* text = new sf::Text(font);
    text->setString(s);
    text->setCharacterSize(24);
    text->setFillColor(color);
    text->setStyle(sf::Text::Bold | sf::Text::Underlined);

    texts.push_back(text);

    return text;
}

void Renderer::RenderBackground(sf::Texture* texture)
{
    SpriteComponent* background = new SpriteComponent(texture);
    background->SetZIndex(INT_MIN);
    sprites.push_back(background);
}

void Renderer::RenderBackground(const char* path)
{
    const std::string s = path;
    const std::filesystem::path filename(s);
    sf::Texture* texture = new sf::Texture();
    
    if (texture->loadFromFile(filename))
    {
        SpriteComponent* background = new SpriteComponent(texture);
        sprites.push_back(background);
        Settings settings;
        sf::Vector2u size = background->GetTexture()->getSize();
        background->SetScale({settings.GetWidth() / (float)size.x, settings.GetHeight() / (float)size.y});
        return;
    }
     
    FMT::warn("Failed to loead texture from file: " + filename.string());
}

void Renderer::RenderBackground(std::filesystem::path& filename)
{
    sf::Texture* texture = new sf::Texture();
    
    if (texture->loadFromFile(filename))
    {
        SpriteComponent* background = new SpriteComponent(texture);
        sprites.push_back(background);
    }
     
    FMT::warn("Failed to loead texture from file: " + filename.string());
}

TransformComponent* Renderer::RenderTransformComponent(sf::Vector2f newPosition, sf::Vector2f newVelocity)
{
    TransformComponent* transformComponent = new TransformComponent(newPosition, newVelocity);
    components.push_back(transformComponent);

    return transformComponent;
}

PhysicsBodyComponent* Renderer::RenderPhysicsBodyComponent(SpriteComponent* owner)
{
    PhysicsBodyComponent* p = new PhysicsBodyComponent(owner);
    components.push_back(p);

    return p;
}
