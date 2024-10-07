#include "UpdateableObject.h"
#include "Scene.h"

UpdateableObject::UpdateableObject()
{
	Scene::currentScene->addUpdateable(this);
}
