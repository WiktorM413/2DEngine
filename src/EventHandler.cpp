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
    });
}
