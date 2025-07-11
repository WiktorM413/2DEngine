#pragma once

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <cstddef>
#include <list>

#include "SpriteComponent.h"

namespace Shapes
{
    struct Circle {};
    struct Convex {};
    struct Rectangle {};
};

class Renderer
{
private:
    std::list<SpriteComponent*> sprites;
    std::list<sf::Shape*> shapes;
    sf::RenderWindow* w;
    sf::Color clearColor;

public:
    Renderer(sf::RenderWindow* newW = nullptr, sf::Color newClearColor = sf::Color::Transparent);
    ~Renderer();
    
    void draw();
    void draw(sf::RenderWindow* w);

    void SetWindow(sf::RenderWindow* newW) { w = newW; }
    sf::RenderWindow* GetWindow() { return w; }
    SpriteComponent* RenderSprite(sf::Texture* texture);
    SpriteComponent* RenderSprite(const char* path);
    SpriteComponent* RenderSprite(const std::filesystem::path& filename);
    sf::Shape* RenderShape(const Shapes::Circle&, float radius = 50, std::size_t pointCount = 30);
    sf::Shape* RenderShape(const Shapes::Convex&, std::size_t pointCount = 50);
    sf::Shape* RenderShape(const Shapes::Rectangle&);
    sf::Shape* RenderShape(const Shapes::Rectangle&, sf::Vector2f size);
    sf::Shape* RenderShape(const Shapes::Rectangle&, float width, float height = 50);
};
