#include <SFML/Window.hpp>

#include "../include/Log.h"
#include "../include/Settings.h"
#include "../include/EventHandler.h"
#include "../include/Renderer.h"

using namespace std;

int main()
{   
    Settings settings;
    EventHandler eventHandler;
    Renderer renderer;

    sf::RenderWindow window(sf::VideoMode({settings.GetWidth(), settings.GetHeight()}), settings.GetTitle());
    
    sf::Shape* shape = renderer.RenderShape(Shapes::Rectangle{});

    eventHandler.AddEventListener<sf::Event::Closed>([&window, &shape](const sf::Event::Closed&)
    {
        delete shape;
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
    while (window.isOpen())
    {
        eventHandler.HandleEvents(&window);
        
        window.clear(sf::Color::Black);

        window.draw(*shape);

        window.display();
    }
}
