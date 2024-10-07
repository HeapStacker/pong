#pragma once
#include "Rectangle.h"
#include "UpdateableObject.h"
#include "Definitions.h"

class Paddle : public Rectangle, public UpdateableObject {
    sf::Keyboard::Key keyUp;
    sf::Keyboard::Key keyDown;
public:
    Paddle(float xPos, sf::Keyboard::Key&& kexUp, sf::Keyboard::Key&& kexDown)
        :Rectangle({ xPos, WINDOW_HEIGHT / 2.f }, { PADDLE_WIDTH, PADDLE_HEIGHT }, true)
    {
        this->keyUp = kexUp;
        this->keyDown = kexDown;
    }

    void update() override {
        if (sf::Keyboard::isKeyPressed(keyUp) && shape->getPosition().y - PADDLE_HEIGHT / 2.f > WALL_WIDTH)
        {
            shape->move({ 0.f, -PADDLE_SPEED });
        }
        if (sf::Keyboard::isKeyPressed(keyDown) && shape->getPosition().y + PADDLE_HEIGHT / 2.f < WINDOW_HEIGHT - WALL_WIDTH)
        {
            shape->move({ 0.f, PADDLE_SPEED });
        }
    }
};