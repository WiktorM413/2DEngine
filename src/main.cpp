#include <SFML/Window.hpp>

#include "../include/Log.h"
#include "../include/Settings.h"

using namespace std;

int main()
{   
    Settings::Initialize();

    sf::Window window(sf::VideoMode({Settings::GetWidth(), Settings::GetHeight()}), Settings::GetTitle());
    FMT::info("Window created\n");
    const auto onClose = [&window](const sf::Event::Closed&)
    {
        FMT::info("Closing window\n");
        window.close();
    };
    while (window.isOpen())
    {
        window.handleEvents(onClose);
        
        window.display();
    }
}
