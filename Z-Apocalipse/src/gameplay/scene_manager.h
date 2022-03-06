#ifndef SCENE_MANAGER
#define SCENE_MANAGER

namespace Z_APOCALIPSE 
{
	enum class Scenes { GAMEPLAY, MAIN_MENU, CREDITS, EXIT, UPGRADER, TUTORIAL, END_GAME, PAUSE_MENU, RESTART_GAMEPLAY, MAIN_MENU_RESTART_GAMEPLAY, OPTIONS_MENU };

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
