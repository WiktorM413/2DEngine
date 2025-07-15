#include <SFML/Window.hpp>

#include "../include/Log.h"
#include "../include/Settings.h"
#include "../include/EventHandler.h"
#include "../include/Renderer.h"
#include "../include/MovementSystem.h" 
#include "../include/SpriteComponent.h" // TransformComponent included here
#include "../include/Camera.h"

#include <iostream>

using namespace std;

int main()
{  
    Settings settings;
    EventHandler eventHandler;
    Renderer* renderer = new Renderer();
    Camera* camera = new Camera();
    MovementSystem movementSystem;
    sf::Clock clock;
    
    settings.SetWidth(1920);
    settings.SetHeight(1080);
    sf::RenderWindow window(sf::VideoMode({settings.GetWidth(), settings.GetHeight()}), settings.GetTitle());
    window.setFramerateLimit(60);

    renderer->RenderBackground("../img/forest.jpg");
    renderer->SetWindow(&window);
    
    movementSystem.SetDamping(0.98f);

    eventHandler.AddEventListener<sf::Event::Closed>([&window, &renderer, &camera](const sf::Event::Closed&)
    {
        delete camera;
        delete renderer;
        FMT::info("Closing window\n");
        window.close();
        exit(0);
    });

    eventHandler.OnKeyPressed(sf::Keyboard::Scancode::Q, [&camera]()
    {
        camera->Zoom(2.f);
    });
    eventHandler.OnKeyPressed(sf::Keyboard::Scancode::E, [&camera]()
    {
        camera->Zoom(0.5f);
    });
     
    SpriteComponent* rectangle1 = renderer->RenderShape(Shapes::Rectangle{});
    rectangle1->SetScale(100.f, 100.f);
    rectangle1->SetPosition({50.f, 50.f});
    rectangle1->SetZIndex(3);
    rectangle1->SetColor(sf::Color::Red);
    //TODO Add another rectangle and check whether collision works

    rectangle1->SetTransformComponent(renderer->RenderTransformComponent(*rectangle1->GetPosition(), {50.f, 0.f}));

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

        float deltaTime = clock.restart().asSeconds();
        
        std::list<SpriteComponent*>* sprites = renderer->GetAllSprites();

        for (auto& sprite : *sprites)
        {
            TransformComponent* transform = sprite->GetTransformComponent();
            if (sprite->GetTransformComponent() != nullptr)
            {
                movementSystem.Update(transform, deltaTime);
                sprite->SetPosition(transform->GetPosition());
            }
        }

        camera->Update();
        window.setView(*camera->GetView());

        renderer->draw();
    }
}
