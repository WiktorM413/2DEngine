#pragma once

#include <SFML/Window.hpp>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <functional>
#include <list>
#include <utility>
#include "SpriteComponent.h"
class EventHandler
{
private:
    std::unordered_map<std::type_index, std::list<std::function<void(const sf::Event&)>>> listeners;
    std::unordered_map<sf::Keyboard::Scancode, std::list<std::function<void(const sf::Event::KeyPressed&)>>> keyPressedEvents;
    std::unordered_map<sf::Keyboard::Scancode, std::list<std::function<void(const sf::Event::KeyReleased&)>>> keyReleasedEvents;
    std::list<std::function<void()>> collisionEvents;
    static bool checkAABB(const sf::Vector2f& posA, const sf::Vector2f& sizeA, const sf::Vector2f& posB, const sf::Vector2f& sizeB);

public:
    template<typename EventType>
    void AddEventListener(std::function<void(const EventType&)> listener)
    {
        std::type_index type = std::type_index(typeid(EventType));
        std::function<void(const sf::Event&)> wrapper = [listener](const sf::Event& baseEvent)
        {
            listener(reinterpret_cast<const EventType&>(baseEvent));
        };
        listeners[type].push_back(wrapper);
    }
    void HandleEvents(sf::Window* window);
    void OnKeyPressed(sf::Keyboard::Scancode code, std::function<void()> action);
    void OnKeyReleased(sf::Keyboard::Scancode code, std::function<void()> action);
    void OnCollisionEnter(SpriteComponent* spriteA, SpriteComponent* spriteB, std::function<void()> action);
    std::list<std::function<void()>>* GetCollisionEvents() { return &collisionEvents; }
};
