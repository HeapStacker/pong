#include "SpeedPowerUp.h"
#include "CollisionDetector.h"
#include "Animate.h"

void SpeedPowerUp::update()
{
	static int counter = 0;
	static int animationIncrement = 5;

	if (!hidden) {
		Animate::color(&shape, 0, animationIncrement);

		if (CollisionDetector::checkCollision(&ball->shape, &this->shape)) {
			ball->setHigherSpeed();
			counter = POWER_UP_DURATION;

			hide();
		}
		if (--lifeTime <= 0) {
			appear();
		}
	}
	else {
		if (--hiddeDuration <= 0) {
			appear();
		}
	}

	if (counter) {
		if (--counter <= 0)  ball->setNormalSpeed();
	}
}
