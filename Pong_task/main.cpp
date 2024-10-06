#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>

static float windowWidth = 800;
static float windowHeight = 600;
static float paddleSpeed = 8.f;
static float ballSpeed = 10.f;

static float paddleWidth = 20.f, paddleHeight = 130.f, paddleOffset = 40.f;
static float wallWidth = 30.f;

static float ballSize = 20.f;

sf::Vector2f normalize(const sf::Vector2f& vector) {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    return { vector.x / length, vector.y / length };
}

sf::Vector2f directions[] = {
    normalize({1, 1}) * ballSpeed,
    normalize({1, -1}) * ballSpeed,
    normalize({-1, -1}) * ballSpeed,
    normalize({-1, 1}) * ballSpeed
};
static sf::Vector2f ballDirection = directions[0];

static sf::RectangleShape ball({ ballSize, ballSize });

void reflect(sf::Vector2f& incident, sf::Vector2f&& normal) {
    incident = normalize(incident - 2.f * (incident.x * normal.x + incident.y * normal.y) * normal) * ballSpeed;
}

float lerp(float minAngle, float maxAngle, float scale) {
    return minAngle + scale * (maxAngle - minAngle);
}

static sf::RectangleShape leftPaddle({ paddleWidth, paddleHeight });
static sf::RectangleShape rightPaddle({ paddleWidth, paddleHeight });
unsigned int leftScore = 0, rightScore = 0;
sf::Text rightScoreText, leftScoreText;
static bool leftHit = false, rightHit = false, upperWallHit = false, lowerWallHit = false;
void setScore() {
    if (ball.getPosition().x < paddleWidth) {
        ball.setPosition({ windowWidth / 2.f, windowHeight / 2.f });
        ballDirection = directions[int(rand() % 4)];
        rightScore++;
        rightScoreText.setString(std::to_string(rightScore));
        rightScoreText.setOrigin({ 0.f, 15.f });
        rightScoreText.setPosition({ windowWidth / 2.f + 20.f, 80.f });

        leftPaddle.setPosition({ paddleOffset, windowHeight / 2.f });
        rightPaddle.setPosition({ windowWidth - paddleOffset, windowHeight / 2.f });

        leftHit = rightHit = false;
    }
    if (ball.getPosition().x > windowWidth - paddleWidth) {
        ball.setPosition({ windowWidth / 2.f, windowHeight / 2.f });
        ballDirection = directions[int(rand() % 4)];
        leftScore++;
        leftScoreText.setString(std::to_string(leftScore));
        leftScoreText.setOrigin({ leftScoreText.getLocalBounds().left + leftScoreText.getLocalBounds().width, 15.f });
        leftScoreText.setPosition({ windowWidth / 2.f - 25.f, 80.f });

        leftPaddle.setPosition({ paddleOffset, windowHeight / 2.f });
        rightPaddle.setPosition({ windowWidth - paddleOffset, windowHeight / 2.f });

        leftHit = rightHit = upperWallHit = lowerWallHit = false;
    }
}

void moveBall() {
    if (ball.getPosition().y - ballSize / 2.f <= wallWidth && !upperWallHit) {
        ballDirection.y = -ballDirection.y;
        upperWallHit = true;
        lowerWallHit = false;
    }
    if (ball.getPosition().y + ballSize / 2.f >= windowHeight - wallWidth && !lowerWallHit) {
        ballDirection.y = -ballDirection.y;
        upperWallHit = false;
        lowerWallHit = true;
    }

    // bounce from left paddle
    if (!leftHit) {
        if (ball.getPosition().x <= paddleOffset + paddleWidth) {
            if (ball.getPosition().x >= paddleOffset + paddleWidth - ballSpeed) {
                if (ball.getPosition().y + ballSize / 2.f > leftPaddle.getPosition().y - paddleHeight / 2.f) {
                    if (ball.getPosition().y - ballSize / 2.f < leftPaddle.getPosition().y + paddleHeight / 2.f) {
                        ballDirection.x = -ballDirection.x;
                        ballDirection.y = lerp(ballDirection.y / 1.2f, ballDirection.y + 3.f, std::abs((ball.getPosition().y - leftPaddle.getPosition().y) / ((paddleHeight + ballSize) / 2.f)));
                        ballDirection = normalize(ballDirection) * ballSpeed;
                        leftHit = true;
                        rightHit = false;
                    }
                }
            }
        }
    }

    // bounce from right paddle
    if (!rightHit) {
        if (ball.getPosition().x >= windowWidth - paddleOffset - paddleWidth) {
            if (ball.getPosition().x <= windowWidth - paddleOffset - paddleWidth + ballSpeed) {
                if (ball.getPosition().y + ballSize / 2.f > rightPaddle.getPosition().y - paddleHeight / 2.f) {
                    if (ball.getPosition().y - ballSize / 2.f < rightPaddle.getPosition().y + paddleHeight / 2.f) {
                        ballDirection.x = -ballDirection.x;
                        ballDirection.y = lerp(ballDirection.y / 1.2f, ballDirection.y + 3.f, std::abs((ball.getPosition().y - rightPaddle.getPosition().y) / ((paddleHeight + ballSize) / 2.f)));
                        ballDirection = normalize(ballDirection) * ballSpeed;
                        leftHit = false;
                        rightHit = true;
                    }
                }
            }
        }
    }

    setScore();

    ball.move(ballDirection);
}


int main() {


    srand(time(nullptr));
    ballDirection = directions[int(rand() % 4)];
    ball.setOrigin({ ballSize / 2.f, ballSize / 2.f });
    ball.setPosition({ windowWidth / 2.f, windowHeight / 2.f });

    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);

    sf::Image icon;
    if (!icon.loadFromFile("res/images/ico.jpg")) return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Font font;
    if (!font.loadFromFile("res/fonts/LCD.ttf")) return EXIT_FAILURE;
    rightScoreText.setFont(font);
    rightScoreText.setCharacterSize(40);
    rightScoreText.setOrigin({ 0.f, 15.f });
    rightScoreText.setPosition({ windowWidth / 2.f + 20.f, 80.f });
    rightScoreText.setString("0");
    leftScoreText.setFont(font);
    leftScoreText.setCharacterSize(40);
    leftScoreText.setString("0");
    leftScoreText.setOrigin({ leftScoreText.getLocalBounds().left + leftScoreText.getLocalBounds().width, 15.f });
    leftScoreText.setPosition({ windowWidth / 2.f - 25.f, 80.f });

    sf::Music music;
    if (!music.openFromFile("res/audio/song.mp3")) return EXIT_FAILURE;

    leftPaddle.setOrigin({ paddleWidth / 2.f, paddleHeight / 2.f });
    leftPaddle.setPosition({ paddleOffset, windowHeight / 2.f });

    rightPaddle.setOrigin({ paddleWidth / 2.f, paddleHeight / 2.f });
    rightPaddle.setPosition({ windowWidth - paddleOffset, windowHeight / 2.f });

    sf::RectangleShape upperWall({ windowWidth, wallWidth });
    upperWall.setPosition({ 0.f, 0.f });

    sf::RectangleShape lowerWall({ windowWidth / 1.f, wallWidth });
    lowerWall.setPosition({ 0.f, windowHeight - wallWidth });

    static sf::Vertex line[] = { sf::Vertex(sf::Vector2f(windowWidth / 2.f, 0.f)), sf::Vertex(sf::Vector2f(windowWidth / 2.f, windowHeight)) };


    //music.play();
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::Resized) {
                windowWidth = event.size.width;
                windowHeight = event.size.height;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y - paddleHeight / 2.f > wallWidth)
        {
            leftPaddle.move({ 0.f, -paddleSpeed });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y + paddleHeight / 2.f < windowHeight - wallWidth)
        {
            leftPaddle.move({ 0.f, paddleSpeed });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y - paddleHeight / 2.f > wallWidth)
        {
            rightPaddle.move({ 0.f, -paddleSpeed });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y + paddleHeight / 2.f < windowHeight - wallWidth)
        {
            rightPaddle.move({ 0.f, paddleSpeed });
        }

        moveBall();

        window.clear();
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(upperWall);
        window.draw(lowerWall);


        window.draw(line, 2, sf::Lines);
        window.draw(leftScoreText);
        window.draw(rightScoreText);
        window.draw(ball);

        window.display();
    }

    return EXIT_SUCCESS;
}