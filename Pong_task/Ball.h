#pragma once
#include "Paddle.h"
#include "Rectangle.h"
#include "UpdateableObject.h"
#include "Definitions.h"

sf::Vector2f normalize(const sf::Vector2f& vector);

class Ball : public Rectangle, public UpdateableObject {
	bool leftHit = false;
	bool rightHit = false;
	bool upperWallHit = false;
	bool lowerWallHit = false;

	sf::Vector2f directions[4] = {
		normalize({1, 1}) * BALL_SPEED,
		normalize({1, -1}) * BALL_SPEED,
		normalize({-1, -1}) * BALL_SPEED,
		normalize({-1, 1}) * BALL_SPEED
	};

	sf::Vector2f ballDirection = directions[int(rand() % 4)];

	void moveBall();

	void setWallAfterHitEffect() {
		upperWallHit = false;
		lowerWallHit = false;
		ballDirection.y = -ballDirection.y;
	}

	bool checkPaddleHit(Paddle* paddle, const float& condition1, const float& condition2);
	
	void applyPaddleAfterHitEffect(Paddle* paddle);

public:
	Paddle* leftPaddle = nullptr;
	Paddle* rightPaddle = nullptr;

	Ball()
		:Rectangle({ WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f }, { BALL_SIZE, BALL_SIZE }, true)
	{ 
		
	}

	void linkPaddles(Paddle* lp, Paddle* rp) {
		leftPaddle = lp;
		rightPaddle = rp;
	}

	void setDirection() {
		ballDirection = directions[int(rand() % 4)];
	}

	void setToNoHits() {
		leftHit = rightHit = upperWallHit = lowerWallHit = false;
	}

	void update() override {
		moveBall();
	}
};

