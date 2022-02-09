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

	void Game::init()
	{
		InitWindow(screenWidth, screenHeight, title);

		SetTargetFPS(fps);

		sceneManager = new SceneManager(Scenes::gameplay);
	}

	void Game::input()
	{

	}

	void Game::update()
	{

	}

	void Game::draw()
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Z-APOCALIPSE", 190, 200, 20, RED);

		EndDrawing();
	}

	void Game::deinit()
	{
		CloseWindow();

		delete sceneManager;
	}

	void Game::runGame()
	{
		while (!WindowShouldClose())
		{
			switch (sceneManager->getCurrentScene())
			{
			case Scenes::gameplay:
				
				input();
				update();
				draw();
				break;
			default:
				break;
			}			
		}
	}
}