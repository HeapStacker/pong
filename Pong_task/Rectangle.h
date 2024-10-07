#pragma once
#include "DrawableObject.h"

class Rectangle : public DrawableObject {
public:
	sf::RectangleShape* shape = nullptr;

	Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, bool centerOrigin = false, const sf::Color& color = { 255, 255, 255, 255 }) {
		shape = new sf::RectangleShape(size);

		if (centerOrigin) {
			shape->setOrigin(size / 2.f);
		}

		shape->setPosition(position);

		shape->setFillColor(color);
	}

	void draw() override {
		DrawableObject::getWindow()->draw(*shape);
	}

	~Rectangle() {
		delete shape;
	}
};

