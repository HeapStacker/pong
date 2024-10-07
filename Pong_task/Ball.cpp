#include "Ball.h"
#include <iostream>
#include <functional>
#include "Definitions.h"

sf::Vector2f normalize(const sf::Vector2f& vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	return { vector.x / length, vector.y / length };
}

bool Ball::checkPaddleHit(Paddle* paddle, const float& condition1, const float& condition2) {
	if (shape->getPosition().x >= condition1 && shape->getPosition().x <= condition2) {
		if (shape->getPosition().y + BALL_SIZE / 2.f > paddle->shape->getPosition().y - PADDLE_HEIGHT / 2.f) {
			if (shape->getPosition().y - BALL_SIZE / 2.f < paddle->shape->getPosition().y + PADDLE_HEIGHT / 2.f) {
				return true;
			}
		}
	}
	return false;
}

void Ball::applyPaddleAfterHitEffect(Paddle* paddle) {
	ballDirection.x = -ballDirection.x;
	ballDirection.y = ((shape->getPosition().y - paddle->shape->getPosition().y) / ((PADDLE_HEIGHT + BALL_SIZE) / 2.f)) * BALL_SPEED + ballDirection.y;
	ballDirection = normalize(ballDirection) * BALL_SPEED;
}

void Ball::moveBall() {
	if (!upperWallHit) if (shape->getPosition().y - BALL_SIZE / 2.f <= WALL_WIDTH) { setWallAfterHitEffect(); upperWallHit = false; }
	
	if (!lowerWallHit) if (shape->getPosition().y + BALL_SIZE / 2.f >= WINDOW_HEIGHT - WALL_WIDTH) { setWallAfterHitEffect(); }

	if (!leftHit) {
		if (checkPaddleHit(leftPaddle, PADDLE_OFFSET + PADDLE_WIDTH - BALL_SPEED, PADDLE_OFFSET + PADDLE_WIDTH)) {
			applyPaddleAfterHitEffect(leftPaddle);
			leftHit = true; rightHit = false;
		}
	}

	if (!rightHit) {
		if (checkPaddleHit(rightPaddle, WINDOW_WIDTH - PADDLE_OFFSET - PADDLE_WIDTH, WINDOW_WIDTH - PADDLE_OFFSET - PADDLE_WIDTH + BALL_SPEED)) {
			applyPaddleAfterHitEffect(rightPaddle);
			leftHit = false; rightHit = true;
		}
	}

	shape->move(ballDirection);
}