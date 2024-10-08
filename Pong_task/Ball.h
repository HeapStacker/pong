#pragma once
#include "Paddle.h"
#include "Rectangle.h"
#include "UpdateableObject.h"
#include "Definitions.h"

sf::Vector2f normalize(const sf::Vector2f& vector);

class Ball : public Rectangle, public UpdateableObject {
	int redAnimation = 255;

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
	
	void applyPaddleAfterHitEffect(Paddle* paddle);

public:
	Paddle* leftPaddle = nullptr;
	Paddle* rightPaddle = nullptr;

	bool leftHit = false;
	bool rightHit = false;

	Ball()
		:Rectangle({ WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f }, { BALL_SIZE, BALL_SIZE }, true, sf::Color::White) { }

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


	// for power-ups... 

	void setNormalSpeed();

	void setHigherSpeed() {
		ballDirection *= 2.f;
	}

	void mirrorDirrection() {
		ballDirection.x = -ballDirection.x;
		leftHit = rightHit = false;
	}

};

