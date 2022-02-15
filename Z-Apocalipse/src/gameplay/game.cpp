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
		
	}

	void Game::setScreenWidth(int screenWidth)
	{
		this->screenWidth = screenWidth;
	}

	void Game::setScreenHeight(int screenHeight)
	{
		this->screenHeight = screenHeight;
	}

	void Game::init()
	{
		InitWindow(screenWidth, screenHeight, title);

		SetTargetFPS(fps);

		sceneManager = new SceneManager(Scenes::GAMEPLAY);
		gameplay = new Gameplay();
	}	

	void Game::deinit()
	{
		CloseWindow();

		delete sceneManager;
		delete gameplay;
	}

	void Game::runGame()
	{
		while (!WindowShouldClose())
		{
			switch (sceneManager->getCurrentScene())
			{
			case Scenes::GAMEPLAY:
				
				gameplay->input();
				gameplay->update();
				gameplay->draw();
				break;
			default:
				break;
			}			
		}

		deinit();
	}
}