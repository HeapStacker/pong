#include "PowerUp.h"

void PowerUp::appear()
{
	hidden = false;
	color.a = 255;
	shape.setFillColor(color);

	float randomX = rand() % int(WINDOW_WIDTH + 1);
	float randomY = WALL_WIDTH + BALL_SIZE + rand() % (WINDOW_HEIGHT - 2 * int(BALL_SIZE + WALL_WIDTH) + 1);
	shape.setPosition(randomX, randomY);

	lifeTime = POWER_UP_MIN_LIFETIME + rand() % (POWER_UP_MAX_LIFETIME - POWER_UP_MIN_LIFETIME + 1);
}

void PowerUp::hide()
{
	color.a = 0;
	hidden = true;
	shape.setFillColor(color);
	hiddeDuration = rand() % (POWER_UP_HIDDEN_MAX_DURATION + 1);
}
