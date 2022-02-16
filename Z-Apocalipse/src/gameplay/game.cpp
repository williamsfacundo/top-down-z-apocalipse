#include "game.h"

#include <raylib.h>

namespace Z_APOCALIPSE
{
	Game::Game(int screenWidth, int screenHeight)
	{
		setScreenWidth(screenWidth);
		setScreenHeight(screenHeight);

		init();
	}

	Game::~Game()
	{
		deinit();
	}

	void Game::setScreenWidth(int screenWidth)
	{
		this->screenWidth = screenWidth;
	}

	void Game::setScreenHeight(int screenHeight)
	{
		this->screenHeight = screenHeight;
	}

	void Game::setMainMenuChangeScenes() 
	{
		mainMenuChangeScenes[0] = Scenes::GAMEPLAY;
		mainMenuChangeScenes[1] = Scenes::OPTIONS;
		mainMenuChangeScenes[2] = Scenes::CREDITS;
		mainMenuChangeScenes[3] = Scenes::EXIT;
	}

	void Game::setRunning(bool running) 
	{
		this->running = running;
	}

	bool Game::getRunning() 
	{
		return running;
	}

	void Game::init()
	{
		InitWindow(screenWidth, screenHeight, title);

		SetTargetFPS(fps);

		sceneManager = new SceneManager(initialScene);
		gameplay = new Gameplay();
		mainMenu = new MainMenu(mainMenuTexts);

		setRunning(true);
		setMainMenuChangeScenes();
	}	

	void Game::deinit()
	{
		CloseWindow();

		delete sceneManager;
		delete gameplay;
		delete mainMenu;
	}

	void Game::runGame()
	{
		while (!WindowShouldClose() && getRunning())
		{
			switch (sceneManager->getCurrentScene())
			{
			case Scenes::GAMEPLAY:
				
				gameplay->input();
				gameplay->update();
				gameplay->draw();
				break;
			case Scenes::MAIN_MENU:

				mainMenu->input(sceneManager, mainMenuChangeScenes);
				mainMenu->draw();
				break;
			case Scenes::OPTIONS:

				temporalUnuseScenes();
				break;
			case Scenes::CREDITS:

				temporalUnuseScenes();
				break;
			case Scenes::EXIT:

				setRunning(false);
				break;
			default:
				break;
			}			
		}		
	}

	void Game::temporalUnuseScenes() 
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			sceneManager->setCurrentScene(Scenes::MAIN_MENU);
		}

		BeginDrawing();
		ClearBackground(WHITE);
		EndDrawing();
	}
}