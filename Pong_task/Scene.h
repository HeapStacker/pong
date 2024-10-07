#include <iostream>
#include <vector>

class DrawableObject;
class UpdateableObject;

class Scene {
	std::vector<DrawableObject*> drawables;
	std::vector<UpdateableObject*> updateables;

	static std::vector<Scene*> scenes;
public:
	static Scene* currentScene;

	Scene();

	void setCurrent(unsigned int sceneId);

	void addDrawable(DrawableObject* object);
	void addUpdateable(UpdateableObject* object);

	static void runCurrent();

};