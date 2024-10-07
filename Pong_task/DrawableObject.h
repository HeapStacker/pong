#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class DrawableObject {
	sf::Vector2f origin;
	sf::Vector2f position;

	static sf::RenderWindow* window;
protected:

	static sf::RenderWindow* getWindow();

public:
	DrawableObject();

	virtual void draw() = 0;

	static void linkRenderWindow(sf::RenderWindow* window);

};

