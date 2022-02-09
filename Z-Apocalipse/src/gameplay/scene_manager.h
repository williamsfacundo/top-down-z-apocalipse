#ifndef SCENE_MANAGER
#define SCENE_MANAGER

namespace Z_APOCALIPSE 
{
	enum class Scenes { gameplay };

	class SceneManager
	{
	private:
		Scenes currentScene;

	public:
		SceneManager(Scenes startingScene);		

		void setCurrentScene(Scenes currentScene);
		Scenes getCurrentScene();
	};
}

#endif