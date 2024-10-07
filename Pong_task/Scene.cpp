#include "Scene.h"
#include "UpdateableObject.h"
#include "DrawableObject.h"

Scene* Scene::currentScene = nullptr;
std::vector<Scene*> Scene::scenes;

Scene::Scene()
{
	scenes.push_back(this);
	currentScene = this;
}

void Scene::setCurrent(unsigned int sceneId)
{
	if (!(currentScene = scenes[sceneId])) {
		std::cerr << "wrong scene id\n";
	}
}

void Scene::addDrawable(DrawableObject* object)
{
	drawables.push_back(object);
}

void Scene::addUpdateable(UpdateableObject* object)
{
	updateables.push_back(object);
}

void Scene::runCurrent() {
	for (UpdateableObject* obj : Scene::currentScene->updateables) { obj->update(); }
	for (DrawableObject* obj : Scene::currentScene->drawables) { obj->draw(); }
}
