#include <SFML/Window.hpp>

#include "../include/Log.h"
#include "../include/Settings.h"
#include "../include/EventHandler.h"
#include "../include/Renderer.h"
#include "../include/SpriteComponent.h"
#include "../include/Camera.h"

#include <iostream>

using namespace std;

int main()
{  
    Settings settings;
    EventHandler eventHandler;
    Renderer* renderer = new Renderer();
    Camera* camera = new Camera();
    settings.SetWidth(1920);
    settings.SetHeight(1080);
    sf::RenderWindow window(sf::VideoMode({settings.GetWidth(), settings.GetHeight()}), settings.GetTitle());
    

    eventHandler.AddEventListener<sf::Event::Closed>([&window, &renderer, &camera](const sf::Event::Closed&)
    {
        delete camera;
        delete renderer;
        FMT::info("Closing window\n");
        window.close();
        exit(0);
    });
    eventHandler.AddEventListener<sf::Event::KeyPressed>([&settings](const sf::Event::KeyPressed& key)
    {
        if (key.scancode == sf::Keyboard::Scancode::D)
        {
            FMT::info("D key is pressed - event 1");
        }
    });
    eventHandler.AddEventListener<sf::Event::KeyPressed>([](const sf::Event::KeyPressed& key)
    {
        if (key.scancode == sf::Keyboard::Scancode::D)
        {
            FMT::info("D key is pressed - event 2");
        }
    });

    eventHandler.OnKeyReleased(sf::Keyboard::Scancode::Enter, []()
    {
        FMT::info("enter key released - event 1");
    });
    eventHandler.OnKeyReleased(sf::Keyboard::Scancode::Enter, []()
    {
        FMT::info("enter key released - event 2");
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
    rectangle1->SetScale(100, 100);
    rectangle1->SetPosition({50, 50});
    rectangle1->SetZIndex(3);
    rectangle1->SetColor(sf::Color::Red);

    eventHandler.AddEventListener<sf::Event::KeyPressed>([&rectangle1](const sf::Event::KeyPressed& key)
    {
        if (key.scancode == sf::Keyboard::Scancode::Right)
        {
            rectangle1->Move({10, 0});
        }
        if (key.scancode == sf::Keyboard::Scancode::Left)
        {
            rectangle1->Move({-10, 0});
        }
        if (key.scancode == sf::Keyboard::Scancode::Up)
        {
            rectangle1->Move({0, -10});
        }
        if (key.scancode == sf::Keyboard::Scancode::Down)
        {
            rectangle1->Move({0, 10});
        }
    });

    camera->SetFocusedSprite(rectangle1);

    while (window.isOpen())
    {
        eventHandler.HandleEvents(&window);

        camera->Update();
        window.setView(*camera->GetView());

        renderer->draw();
    }
}
