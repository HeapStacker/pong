#include "Animate.h"

void Animate::color(sf::RectangleShape* shape, const unsigned int& color, int& increment, const unsigned int& lowerBound, const unsigned int& upperBound) {
	sf::Color color_ = shape->getFillColor();

	switch (color)
	{
	case 0:
		if (color_.r + increment > upperBound || color_.r + increment < lowerBound) {
			increment = -increment;
		}
		color_.r += increment;
		color_.r %= 256;
		break;
	case 1:
		if (color_.g + increment > upperBound || color_.g + increment < lowerBound) {
			increment = -increment;
		}
		color_.g += increment;
		color_.g %= 256;
		break;
	case 2:
		if (color_.b + increment > upperBound || color_.b + increment < lowerBound) {
			increment = -increment;
		}
		color_.b += increment;
		color_.b %= 256;
		break;
	case 3:
		if (color_.a + increment > upperBound || color_.a + increment < lowerBound) {
			increment = -increment;
		}
		color_.a += increment;
		color_.a %= 256;
		break;
	default:
		break;
	}

	shape->setFillColor(color_);
}
