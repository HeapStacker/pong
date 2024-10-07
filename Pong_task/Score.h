#pragma once
#include "Text.h"
#include "UpdateableObject.h"
#include "Ball.h"
#include "Definitions.h"
#include <functional>

class Score : public Text, public UpdateableObject {
	unsigned int score = 0;


	std::function<bool()> winningCondition;
public:
	Ball* ball = nullptr;

	Score(float&& posX, sf::Font& font, std::function<bool()>&& winningCondition) :Text("0", font, { posX, 80.f }) {
		this->winningCondition = winningCondition;
	}

	void update() override {
		if (winningCondition()) {
			ball->shape->setPosition({ WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f });
			ball->setDirection();
			ball->setToNoHits();
			ball->leftPaddle->shape->setPosition({ PADDLE_OFFSET, WINDOW_HEIGHT / 2.f });
			ball->rightPaddle->shape->setPosition({ WINDOW_WIDTH - PADDLE_OFFSET, WINDOW_HEIGHT / 2.f });

			score++;
			setString(std::to_string(score));

		}
	}
};

