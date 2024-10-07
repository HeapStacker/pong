#pragma once
#include "DrawableObject.h"
#include <iostream>

class Line : public DrawableObject {
	sf::Vertex line[2];
public:

	Line(const sf::Vector2f& firstVertex, const sf::Vector2f& secondVertex, const sf::Color& color = { 255, 255, 255, 255 }) {
		this->line[0] = sf::Vertex(firstVertex, color);
		this->line[1] = sf::Vertex(secondVertex, color);
	}

	void draw() override {
		DrawableObject::getWindow()->draw(line, 2, sf::Lines);
	}

	// change line properties...

	void changeVertexPosition(unsigned int vertexId, const sf::Vector2f& position) {
		if (vertexId <= 1) {
			line[vertexId].position = position;
		}
		else {
			std::cerr << "wrong input (vertexId)\n";
		}
	}

	void changeColor(const sf::Color& color) {
		line[0].color = line[1].color = color;
	}
};

