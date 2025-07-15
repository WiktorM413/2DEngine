#include "../include/EventHandler.h"
#include "../include/components/PhysicsBodyComponent.h"

bool EventHandler::checkAABB(const sf::Vector2f& posA, const sf::Vector2f& sizeA,
               const sf::Vector2f& posB, const sf::Vector2f& sizeB) {
    return (
        posA.x < posB.x + sizeB.x &&
        posA.x + sizeA.x > posB.x &&
        posA.y < posB.y + sizeB.y &&
        posA.y + sizeA.y > posB.y
    );
}

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
    for (auto& event : collisionEvents)
    {
        event();
    }
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

void EventHandler::OnCollisionEnter(SpriteComponent* spriteA, SpriteComponent* spriteB, std::function<void()> action)
{
    std::function<void()> wrapper = [&spriteA, spriteB, action]()
    {
        PhysicsBodyComponent* physicsBodyA = spriteA->GetPhysicsBodyComponent();
        PhysicsBodyComponent* physicsBodyB = spriteB->GetPhysicsBodyComponent();

        if (checkAABB(*spriteA->GetPosition(), physicsBodyA->GetSize(), *spriteB->GetPosition(), physicsBodyB->GetSize()) && spriteA->GetZIndex() == spriteB->GetZIndex())
        {
            action();
        }
    };
}
