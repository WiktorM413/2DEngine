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
            for (std::function<void(const sf::Event&)> event : it->second)
            {
                event(eventVariant);
            } 
        }
        if constexpr (std::is_same_v<T, sf::Event::KeyPressed>)
        {
            for (auto& actions : keyPressedEvents)
            {
                for (auto& action : actions.second)
                {
                    action(eventVariant);
                }
            }
        }
        if constexpr (std::is_same_v<T, sf::Event::KeyReleased>)
        {
            for (auto& actions : keyReleasedEvents)
            {
                for (auto& action: actions.second)
                {
                    action(eventVariant);
                }
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
    keyPressedEvents[code].push_back(wrapper);
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
    keyReleasedEvents[code].push_back(wrapper);
}
