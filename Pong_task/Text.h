#pragma once
#include "DrawableObject.h"
#include <string>

class Text : public DrawableObject {
	sf::Text text;
public:
	Text(std::string string, sf::Font& font, const sf::Vector2f& position, unsigned int pxFontSize = 40) {
		text.setFont(font);

		text.setString(string);
		text.setCharacterSize(pxFontSize);


		text.setPosition(position);
	}

	void customise(unsigned int pxFontSize = 40, const sf::Color& textColor = { 255, 255, 255, 255 }) {

		text.setCharacterSize(pxFontSize);

		text.setFillColor(textColor);
	}

	void setString(std::string string) {
		text.setString(string);
	}

	void setPosition(const sf::Vector2f& position) {
		text.setPosition(position);
	}

	void draw() override {
		DrawableObject::getWindow()->draw(this->text);
	}
};

