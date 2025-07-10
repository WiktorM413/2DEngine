#include <SFML/Window.hpp>

#include "../include/Log.h"
#include "../include/Settings.h"
#include "../include/EventHandler.h"

using namespace std;

int main()
{   
    Settings settings;
    EventHandler eventHandler;

    sf::Window window(sf::VideoMode({settings.GetWidth(), settings.GetHeight()}), settings.GetTitle());
    FMT::info("Window created\n");
    
    eventHandler.AddEventListener<sf::Event::Closed>([&window](const sf::Event::Closed&)
    {
        FMT::info("Closing window\n");
        window.close();
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
        
        window.display();
    }
}
