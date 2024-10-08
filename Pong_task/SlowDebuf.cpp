#include "SlowDebuf.h"
#include "CollisionDetector.h"
#include "Animate.h"

#include <iostream>

void SlowDebuf::update()
{
	static int counter = 0;
	static int animationIncrement = 5;

	if (!hidden) {
		Animate::color(&shape, 3, animationIncrement);

		if (CollisionDetector::checkCollision(&ball->shape, &this->shape)) {
			if (ball->leftHit) ball->leftPaddle->slow = true;
			if (ball->rightHit) ball->rightPaddle->slow = true;

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
		if (--counter <= 0) {

			// this is bad but it will work for now
			ball->leftPaddle->slow = false;
			ball->rightPaddle->slow = false;
		}
	}
}
