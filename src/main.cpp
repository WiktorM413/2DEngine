#include <SFML/Window.hpp>

#include "../include/Log.h"
#include "../include/Settings.h"
#include "../include/EventHandler.h"
#include "../include/Renderer.h"
#include "../include/SpriteComponent.h"

#include <iostream>

using namespace std;

int main()
{  
    Settings settings;
    EventHandler eventHandler;
    Renderer* renderer = new Renderer();

    sf::RenderWindow window(sf::VideoMode({settings.GetWidth(), settings.GetHeight()}), settings.GetTitle());
    

    eventHandler.AddEventListener<sf::Event::Closed>([&window, &renderer](const sf::Event::Closed&)
    {
        delete renderer;
        FMT::info("Closing window\n");
        window.close();
        exit(0);
    });
    eventHandler.AddEventListener<sf::Event::KeyPressed>([](const sf::Event::KeyPressed& key)
    {
        if (key.scancode == sf::Keyboard::Scancode::D)
        {
            FMT::info("D key is pressed");
        }
    });
    eventHandler.OnKeyReleased(sf::Keyboard::Scancode::Enter, []()
    {
        FMT::info("enter key released");
    });
    eventHandler.OnKeyPressed(sf::Keyboard::Scancode::Enter, []()
    {
        FMT::info("enter key pressed");
    });

    

    sf::Font font;

    if (!font.openFromFile("../img/font.ttf"))
    {
        FMT::warn("Could not open font");
    }

    sf::Text* text = renderer->RenderText(font, "Example text");
    text->setFillColor(sf::Color::White);
    renderer->SetWindow(&window);
    
    SpriteComponent* rectangle1 = renderer->RenderShape(Shapes::Rectangle{});
    rectangle1->SetScale(50, 50);
    rectangle1->SetZIndex(3);
    rectangle1->SetColor(sf::Color::Red);

    while (window.isOpen())
    {

        eventHandler.HandleEvents(&window);
        renderer->draw();
    }
}
