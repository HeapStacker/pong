#pragma once
#include <SFML/Graphics.hpp>

static class Animate {
public:

	// pass startTime and endTime as seconds
	// pass counter as a frame count refrence
	// color: 0 (to animate red component), 1 (green), 2 (blue), 3 (alpha)
	static void color(sf::RectangleShape* shape, const unsigned int& color, int& increment, const unsigned int& lowerBound = 150, const unsigned int& upperBound = 255);
};