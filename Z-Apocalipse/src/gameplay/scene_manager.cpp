#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	SceneManager::SceneManager(Scenes startingScene)
	{
		setCurrentScene(startingScene);
	}	

	void SceneManager::setCurrentScene(Scenes currentScene)
	{
		this->currentScene = currentScene;
	}
	
	Scenes SceneManager::getCurrentScene() 
	{
		return currentScene;
	}
}