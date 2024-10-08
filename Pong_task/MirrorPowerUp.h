#pragma once
#include "PowerUp.h"
#include "UpdateableObject.h"
#include "Ball.h"

class MirrorPowerUp : public PowerUp, public UpdateableObject {
	Ball* ball = nullptr;

public:
	MirrorPowerUp() :PowerUp(sf::Color::Blue) {}

	void update() override;

	void linkBall(Ball* ball) { this->ball = ball; }
};
