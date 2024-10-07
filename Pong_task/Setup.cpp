#include "Setup.h"
#include "Application.h"
#include <SFML/System/Vector2.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "Score.h"

void loadObjects() {
	static sf::Font font;
	if (!font.loadFromFile(FONT_PATH)) {
		std::cerr << "font not found\n";
		throw 1;
	}

	// game scene 
	static Scene gameScene;

	static Ball ball;

	static Paddle leftPaddle(PADDLE_OFFSET, sf::Keyboard::W, sf::Keyboard::S);

	static Paddle rightPaddle(WINDOW_WIDTH - PADDLE_OFFSET, sf::Keyboard::Up, sf::Keyboard::Down);

	ball.linkPaddles(&leftPaddle, &rightPaddle);

	static Score leftScore(WINDOW_WIDTH / 2.f - 100.f, font, []() -> bool { return ball.shape->getPosition().x > WINDOW_WIDTH - PADDLE_WIDTH; });

	static Score rightScore(WINDOW_WIDTH / 2.f + 50.f, font, []() -> bool { return ball.shape->getPosition().x < PADDLE_WIDTH; });

	leftScore.ball = rightScore.ball = &ball;

	static Rectangle upperWall({ 0.f, 0.f }, { WINDOW_WIDTH, WALL_WIDTH });

	static Rectangle lowerWall({ 0.f, WINDOW_HEIGHT - WALL_WIDTH }, { WINDOW_WIDTH / 1.f, WALL_WIDTH });

	static Line line({ WINDOW_WIDTH / 2.f, 0.f }, { WINDOW_WIDTH / 2.f, WINDOW_HEIGHT });
}
