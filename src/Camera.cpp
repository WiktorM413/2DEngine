#include "../include/Camera.h"

Camera::Camera()
{
    camera = new sf::View();
    camera->setCenter({0.f, 0.f});
    camera->setSize({500, 500});
}

Camera::Camera(const sf::Vector2f& center, const sf::Vector2f& size)
{
    camera = new sf::View();
    camera->setCenter(center);
    camera->setSize(size);
}

Camera::Camera(SpriteComponent* focusedSprite, const sf::Vector2f& size)
{
    this->focusedSprite = focusedSprite;

    camera = new sf::View();
    camera->setCenter(*focusedSprite->GetPosition());
    camera->setSize(size);
}

Camera::~Camera()
{
    delete camera;
}

void Camera::Update()
{
    if (focusedSprite)
    {
        camera->setCenter(*focusedSprite->GetPosition());
    }
}

void Camera::Move(sf::Vector2f move)
{
    camera->setCenter(camera->getCenter() + move);

}
