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
    
    eventHandler.AddEventListener<sf::Event::KeyPressed>([](const sf::Event::KeyPressed&)
    {
        FMT::info("A key has been pressed\n");
    });

    while (window.isOpen())
    {
        eventHandler.HandleEvents(&window);
        
        window.display();
    }
}
