#include "Ball.h"
#include <iostream>
#include <functional>
#include "Definitions.h"
#include "CollisionDetector.h"

sf::Vector2f normalize(const sf::Vector2f& vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	return { vector.x / length, vector.y / length };
}

void Ball::applyPaddleAfterHitEffect(Paddle* paddle) {
	ballDirection.x = -ballDirection.x;
	ballDirection.y = ((shape.getPosition().y - paddle->shape.getPosition().y) / ((PADDLE_HEIGHT + BALL_SIZE) / 2.f)) * BALL_SPEED + ballDirection.y;
	ballDirection = normalize(ballDirection) * BALL_SPEED;

	redAnimation = 0;
}

void Ball::setNormalSpeed()
{
	ballDirection = normalize(ballDirection) * BALL_SPEED;
}

void Ball::moveBall() {
	static unsigned int animationIncremen = 10;
	if (redAnimation + animationIncremen < 255) {
		redAnimation += animationIncremen;
		redAnimation %= 256;
		shape.setFillColor(sf::Color(255, redAnimation, redAnimation));
	}
	else {
		redAnimation = 255;
	}

	if (!upperWallHit) if (shape.getPosition().y - BALL_SIZE / 2.f <= WALL_WIDTH) setWallAfterHitEffect();
	
	if (!lowerWallHit) if (shape.getPosition().y + BALL_SIZE / 2.f >= WINDOW_HEIGHT - WALL_WIDTH) setWallAfterHitEffect(); 

	if (!leftHit) {
		if (CollisionDetector::checkCollision(&shape, &leftPaddle->shape)) {
			applyPaddleAfterHitEffect(leftPaddle);
			leftHit = true; rightHit = false;
		}
	}

	if (!rightHit) {
		if (CollisionDetector::checkCollision(&shape, &rightPaddle->shape)) {
			applyPaddleAfterHitEffect(rightPaddle);
			leftHit = false; rightHit = true;
		}
	}

	shape.move(ballDirection);
}