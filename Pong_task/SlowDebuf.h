#pragma once
#include "PowerUp.h"
#include "UpdateableObject.h"
#include "Ball.h"

class SlowDebuf : public PowerUp, public UpdateableObject {
	Ball* ball = nullptr;

public:
	SlowDebuf() :PowerUp(sf::Color::Red) { }

	void update() override;

	void linkBall(Ball* ball) { this->ball = ball; }
};
