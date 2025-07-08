#include <SFML/Window.hpp>
#include "../include/Log.h"
int main()
{
    sf::Window window(sf::VideoMode({800, 600}), "My window");
    FMT::info("Window created\n");
    const auto onClose = [&window](const sf::Event::Closed&)
    {
        FMT::info("Closing window\n");
        window.close();
    };
    while (window.isOpen())
    {
        window.handleEvents(onClose);
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.display();
    }
}
