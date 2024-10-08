#include "MirrorPowerUp.h"
#include "CollisionDetector.h"
#include "Animate.h"

void MirrorPowerUp::update()
{
	static int animationIncrement = 5;
	if (!hidden) {
		Animate::color(&shape, 1, animationIncrement, 0, 255);

		if (CollisionDetector::checkCollision(&ball->shape, &this->shape)) {
			ball->mirrorDirrection();

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
}
