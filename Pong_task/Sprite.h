#pragma once
#include "DrawableObject.h"
#include <iostream>

class Sprite : public DrawableObject {
	sf::Texture texture;
public:
	sf::Sprite sprite;

	Sprite(const sf::Vector2f& position, std::string texturePath, bool centerOrigin = false) {
		if (!texture.loadFromFile(texturePath)) {
			std::cerr << "texture can't be loaded\n";
			throw 1;
		}

		sprite.setTexture(texture);

		if (centerOrigin) {
			sf::FloatRect bounds = sprite.getGlobalBounds();
			sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f); // Postavlja origin u sredinu
		}

		sprite.setPosition(position);
	}

	void setAbsoluteSize(const sf::Vector2f& size) {
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setScale(size.x / bounds.width, size.y / bounds.height);
	}

	void setColor(const sf::Color& color = { 255, 255, 255, 255 }) {
		sprite.setColor(color);
	}

	void draw() override {
		DrawableObject::getWindow()->draw(sprite);
	}
};
