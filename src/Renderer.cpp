#include "../include/Renderer.h"

#include <filesystem>
#include <string>

sf::Sprite* Renderer::RenderSprite(const sf::Texture& texture)
{
    textures.emplace_back(texture);
    sf::Sprite* sprite = new sf::Sprite(texture);
    return sprite;
}

sf::Sprite* Renderer::RenderSprite(const char* path)
{
    const std::string s = path;
    const std::filesystem::path filename(s);
    sf::Texture texture;
    
    if (texture.loadFromFile(filename))
    {
        textures.emplace_back(texture);
    }
     
    sf::Sprite* sprite = new sf::Sprite(texture);
    return sprite;
}

sf::Sprite* Renderer::RenderSprite(const std::filesystem::path& filename)
{
    sf::Texture texture;
    
    if (texture.loadFromFile(filename))
    {
        textures.emplace_back(texture);
    }
    
    sf::Sprite* sprite = new sf::Sprite(texture);
    return sprite;
}

sf::Shape* Renderer::RenderShape(const Shapes::Circle&, float radius, std::size_t pointCount)
{
    sf::CircleShape* shape = new sf::CircleShape(radius, pointCount);
    return shape;
}

sf::Shape* Renderer::RenderShape(const Shapes::Convex&, std::size_t pointCount)
{
    sf::ConvexShape* shape = new sf::ConvexShape(pointCount);
    return shape;
}

sf::Shape* Renderer::RenderShape(const Shapes::Rectangle&)
{
    sf::RectangleShape* shape = new sf::RectangleShape({120, 50});
    return shape;
}

sf::Shape* Renderer::RenderShape(const Shapes::Rectangle&, sf::Vector2f size)
{
    sf::RectangleShape* shape = new sf::RectangleShape(size);
    return shape;
}

sf::Shape* Renderer::RenderShape(const Shapes::Rectangle&, float width, float height)
{
    sf::RectangleShape* shape = new sf::RectangleShape({width, height});
    return shape;
}
