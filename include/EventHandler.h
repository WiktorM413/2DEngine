#pragma once

#include <SFML/Window.hpp>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <functional>
#include <list>
#include <utility>
class EventHandler
{
private:
    std::unordered_map<std::type_index, std::function<void(const sf::Event&)>> listeners;
    std::list<std::pair<sf::Keyboard::Scancode, std::function<void(const sf::Event::KeyPressed&)>>> keyPressedEvents;
    std::list<std::pair<sf::Keyboard::Scancode, std::function<void(const sf::Event::KeyReleased&)>>> keyReleasedEvents;
public:
    template<typename EventType>
    void AddEventListener(std::function<void(const EventType&)> listener)
    {
        std::type_index type = std::type_index(typeid(EventType));
        std::function<void(const sf::Event&)> wrapper = [listener](const sf::Event& baseEvent)
        {
            listener(reinterpret_cast<const EventType&>(baseEvent));
        };
        listeners[type] = wrapper;
    }
    void HandleEvents(sf::Window* window);
    void OnKeyPressed(sf::Keyboard::Scancode code, std::function<void()> action);
    void OnKeyReleased(sf::Keyboard::Scancode code, std::function<void()> action);
};
