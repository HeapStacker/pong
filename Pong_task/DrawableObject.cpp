#include "DrawableObject.h"
#include "Scene.h"

sf::RenderWindow* DrawableObject::window = nullptr;

sf::RenderWindow* DrawableObject::getWindow() {
	return DrawableObject::window;
}

DrawableObject::DrawableObject()
{
	Scene::currentScene->addDrawable(this);
}

void DrawableObject::linkRenderWindow(sf::RenderWindow* window) {
	DrawableObject::window = window;
}
