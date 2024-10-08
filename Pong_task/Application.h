#pragma once
#include "Scene.h"
#include "Definitions.h"
#include "Setup.h"

#include <SFML/Graphics.hpp>
#include "DrawableObject.h"

class Application
{
	sf::RenderWindow* window = nullptr;
public:
	Application(std::string name, sf::Image& icon, unsigned int windowWidth, unsigned int windowHeight) {
		window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), name);
		window->setFramerateLimit(FPS);

		DrawableObject::linkRenderWindow(window);
		window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

		loadObjects();
	}

	void run() {
		while (window->isOpen()) {

			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window->close();
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.scancode == sf::Keyboard::Scan::Escape) {
						window->close();
					}
				}
			}

			window->clear();
			Scene::runCurrent();
			window->display();
		}
	}

	~Application() {
		delete window;
	}
};
