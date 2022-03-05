#include "game.h"

#include <raylib.h>

#include "scene_manager.h"
#include "gameplay.h"
#include "..\game\main_menu.h"
#include "..\game\credits.h"
#include "..\gameplay\upgrader.h"
#include "..\gameplay\tutorial.h"

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
		mainMenuChangeScenes[0] = Scenes::TUTORIAL;
		mainMenuChangeScenes[1] = Scenes::OPTIONS;
		mainMenuChangeScenes[2] = Scenes::CREDITS;
		mainMenuChangeScenes[3] = Scenes::EXIT;
	}

	void Game::setPauseMenuChangeScenes()
	{
		pauseMenuChangeScenes[0] = Scenes::GAMEPLAY;
		pauseMenuChangeScenes[1] = Scenes::RESTART_GAMEPLAY;
		pauseMenuChangeScenes[2] = Scenes::OPTIONS;
		pauseMenuChangeScenes[3] = Scenes::MAIN_MENU_RESTART_GAMEPLAY;
	}

	void Game::setversionTextPosition(Vector2 versionTextPosition) 
	{
		this->versionTextPosition = versionTextPosition;
	}

	void Game::setRunning(bool running) 
	{
		this->running = running;
	}

	Vector2 Game::getversionTextPosition() 
	{
		return versionTextPosition;
	}

	bool Game::getRunning() 
	{
		return running;
	}

	void Game::init()
	{
		InitWindow(screenWidth, screenHeight, title);

		SetTargetFPS(fps);

		setPauseMenuChangeScenes();

		sceneManager = new SceneManager(initialScene);
		gameplay = new Gameplay();
		mainMenu = new MainMenu(mainMenuTexts);
		credits = new Credits();
		upgrader = new Upgrader();
		tutorial = new Tutorial();
		endGame = new EndGame();
		pauseMenu = new PauseMenu(pauseMenuChangeScenes);

		setversionTextPosition( { static_cast<float>(GetScreenWidth() * 0.85f ), static_cast<float>(GetScreenHeight() * 0.85f) } );
		setRunning(true);
		setMainMenuChangeScenes();		
	}	

	void Game::deinit()
	{
		CloseWindow();

		delete sceneManager;
		delete gameplay;
		delete mainMenu;
		delete credits;
		delete upgrader;
		delete tutorial;
		delete endGame;
		delete pauseMenu;
	}

	void Game::drawVersion() 
	{
		DrawText(versionText, static_cast<int>(getversionTextPosition().x), (getversionTextPosition().y), versionTextSize, versionTextColor);
					
		EndDrawing();
	}

	void Game::runGame()
	{
		while (!WindowShouldClose() && getRunning())
		{
			switch (sceneManager->getCurrentScene())
			{
			case Scenes::GAMEPLAY:
				
				gameplay->input(sceneManager);

				gameplay->update(sceneManager, endGame, upgrader);

				gameplay->draw();
				break;
			case Scenes::MAIN_MENU:

				mainMenu->input(sceneManager, mainMenuChangeScenes);

				mainMenu->draw();

				drawVersion();
				break;
			case Scenes::OPTIONS:

				temporalUnuseScenes();
				break;
			case Scenes::CREDITS:

				credits->input(sceneManager);

				credits->draw(mainMenu);

				drawVersion();
				break;
			case Scenes::EXIT:

				setRunning(false);
				break;			
			case Scenes::UPGRADER:

				upgrader->input(gameplay->getPlayer(), sceneManager);

				upgrader->draw(gameplay->getPlayer());
				break;
			case Scenes::TUTORIAL:

				tutorial->input(sceneManager);

				tutorial->draw();
				break;
			case Scenes::END_GAME:

				endGame->input(sceneManager);

				endGame->draw();
				break;
			case Scenes::PAUSE_MENU:

				pauseMenu->input(sceneManager);
				
				pauseMenu->draw();

				drawVersion();
				break;
			case Scenes::RESTART_GAMEPLAY:
				
				gameplay->restartGameplay(sceneManager, endGame, upgrader, restartGameplayScene);
				break;
			case Scenes::MAIN_MENU_RESTART_GAMEPLAY:

				gameplay->restartGameplay(sceneManager, endGame, upgrader, mainMenuRestartGameplayScene);
				break;
			default:

				setRunning(false);
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

		DrawText("PRESS 'SPACE' TO GO BACK", 1, 1, 50, BLACK);
		EndDrawing();
	}	
}