#include "../include/EventHandler.h"

void EventHandler::HandleEvents(sf::Window* window)
{
    window->handleEvents([this](const auto& eventVariant)
    {
        using T = std::decay_t<decltype(eventVariant)>;
        auto type = std::type_index(typeid(T));
        auto it = listeners.find(type);
        if (it != listeners.end())
        {
            it->second(eventVariant);
        }
        if constexpr (std::is_same_v<T, sf::Event::KeyPressed>)
        {
            for (auto& action : keyPressedEvents)
            {
                action.second(eventVariant);
            }
        }
        if constexpr (std::is_same_v<T, sf::Event::KeyReleased>)
        {
            for (auto& action : keyReleasedEvents)
            {
                action.second(eventVariant);
            }
        }
    });
}

void EventHandler::OnKeyPressed(sf::Keyboard::Scancode code, std::function<void()> action)
{
    std::function<void(const sf::Event::KeyPressed&)> wrapper = [action, code](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == code)
        {
            action();
        }
    };
    keyPressedEvents.push_back({code, wrapper});
}

void EventHandler::OnKeyReleased(sf::Keyboard::Scancode code, std::function<void()> action)
{ 
    std::function<void(const sf::Event::KeyReleased&)> wrapper = [action, code](const sf::Event::KeyReleased& keyReleased)
    {
        if (keyReleased.scancode == code)
        {
            action();
        }
    };
    keyReleasedEvents.push_back({code, wrapper});
}
