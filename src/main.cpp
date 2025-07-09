#include <SFML/Window.hpp>
#include "../include/Log.h"
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

#include <fstream>
#include <iostream>

using namespace std;
using namespace rapidjson;

int main()
{
    Document doc;
    ifstream ifs("../options.json");
    if (!ifs.is_open())
    {
        FMT::error("Could not open options.json for reading\nExiting...\n");
    }

    IStreamWrapper isw(ifs);
    doc.ParseStream(isw);
    if (doc.HasParseError())
    {
        FMT::error("Error parsing json\nExiting...\n");
    }

    uint16_t width = doc["window-size"]["width"].GetInt();
    uint16_t height = doc["window-size"]["height"].GetInt();
    string title = doc["title"].GetString();

    sf::Window window(sf::VideoMode({width, height}), title);
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
