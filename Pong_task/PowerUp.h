#pragma once
#include "Rectangle.h"
#include "Definitions.h"
#include <cstdlib>

class PowerUp: public Rectangle {
protected:
	bool hidden = true;

	sf::Color color = sf::Color::White;
	int hiddeDuration = rand() % (POWER_UP_HIDDEN_MAX_DURATION + 1);
	int lifeTime = POWER_UP_MAX_LIFETIME;

	void appear();

	void hide();

public:
	PowerUp(const sf::Color& color)
		:Rectangle({ -1000.f, -1000.f }, { BALL_SIZE * 4, BALL_SIZE * 4 }, true, color)
	{
		this->color = color;
		hide();
	}
};
