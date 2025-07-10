#pragma once

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <cstddef>
#include <vector>

namespace Shapes
{
    struct Circle {};
    struct Convex {};
    struct Rectangle {};
};

class Renderer
{
private:
    std::vector<sf::Texture> textures;

public:
    sf::Sprite* RenderSprite(const sf::Texture& texture);
    sf::Sprite* RenderSprite(const char* path);
    sf::Sprite* RenderSprite(const std::filesystem::path& filename);
    sf::Shape* RenderShape(const Shapes::Circle&, float radius = 50, std::size_t pointCount = 30);
    sf::Shape* RenderShape(const Shapes::Convex&, std::size_t pointCount = 50);
    sf::Shape* RenderShape(const Shapes::Rectangle&);
    sf::Shape* RenderShape(const Shapes::Rectangle&, sf::Vector2f size);
    sf::Shape* RenderShape(const Shapes::Rectangle&, float width, float height = 50);
};
