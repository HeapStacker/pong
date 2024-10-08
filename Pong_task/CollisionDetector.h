#pragma once
#include <SFML/Graphics.hpp>

class CollisionDetector {
public:
    static bool checkCollision(sf::RectangleShape* rect1, sf::RectangleShape* rect2) {
        return rect1->getGlobalBounds().intersects(rect2->getGlobalBounds());
    }
};