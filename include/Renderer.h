#pragma once

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <cstddef>
#include <list>
#include <string>

#include "SpriteComponent.h"

namespace Shapes
{
    struct Circle {};
    struct Rectangle {};
};

class Renderer
{
private:
    std::list<SpriteComponent*> sprites;
    std::list<sf::Text*> texts;
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
    SpriteComponent* RenderShape(const Shapes::Circle&, float radius = 50, std::size_t pointCount = 30);
    SpriteComponent* RenderShape(const Shapes::Rectangle&, sf::Vector2f size);
    SpriteComponent* RenderShape(const Shapes::Rectangle&, float width = 50.f, float height = 50.f);
    sf::Text* RenderText(const sf::Font& font, std::string s, uint8_t fontSize = 24, sf::Color color = sf::Color::Black);

};
