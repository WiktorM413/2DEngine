#include <SFML/Graphics.hpp>
#include "../include/SpriteComponent.h"

class Camera
{
private:
    sf::View* camera;
    SpriteComponent* focusedSprite;
public:
    Camera();
    Camera(const sf::Vector2f& center, const sf::Vector2f& size);
    Camera(SpriteComponent* focusedSprite, const sf::Vector2f& size);
    ~Camera();

    void SetCenter(sf::Vector2f center) { camera->setCenter(center); }
    sf::Vector2f GetCenter() { return camera->getCenter(); }
    void SetSize(sf::Vector2f size) { camera->setSize(size); }
    sf::Vector2f GetSize() { return camera->getSize(); }
    sf::View* GetView() { return camera; }
    void SetFocusedSprite(SpriteComponent* sprite) { focusedSprite = sprite; camera->setCenter(focusedSprite->GetPosition()); }
    void Update();
    void Move(sf::Vector2f move);
    void Zoom(float factor) { camera->zoom(factor); }
};
