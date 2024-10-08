#pragma once
#include "PowerUp.h"
#include "UpdateableObject.h"
#include "Ball.h"

class SpeedPowerUp: public PowerUp, public UpdateableObject {
	Ball* ball = nullptr;

public:
	SpeedPowerUp() :PowerUp(sf::Color::Green) { }

	void update() override;

	void linkBall(Ball* ball) { this->ball = ball; }
};
