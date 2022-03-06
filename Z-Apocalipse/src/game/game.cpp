#include "game.h"

#include <raylib.h>

#include "main_menu.h"
#include "credits.h"
#include "options_menu.h"
#include "..\gameplay\scene_manager.h"
#include "..\gameplay\gameplay.h"
#include "..\gameplay\upgrader.h"
#include "..\gameplay\tutorial.h"
#include "..\gameplay\end_game.h"
#include "..\gameplay\pause_menu.h"
#include "..\math\math.h"

namespace Z_APOCALIPSE

{	Game::Game()
	{
		setScreenWidth(static_cast<int>(initialResolution.x));
		setScreenHeight(static_cast<int>(initialResolution.y));

		SetConfigFlags(FLAG_WINDOW_RESIZABLE);
		InitWindow(getScreenWidth(), getScreenHeight(), title);		

		setWindowPosition();

		SetTargetFPS(fps);

		setResolution(initialResolution);
		setRunning(true);
		setPauseMenuChangeScenes();
		setMainMenuChangeScenes();

		init();
	}

	Game::~Game()
	{
		CloseWindow();

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
		mainMenuChangeScenes[1] = Scenes::OPTIONS_MENU;
		mainMenuChangeScenes[2] = Scenes::CREDITS;
		mainMenuChangeScenes[3] = Scenes::EXIT;
	}

	void Game::setPauseMenuChangeScenes()
	{
		pauseMenuChangeScenes[0] = Scenes::GAMEPLAY;
		pauseMenuChangeScenes[1] = Scenes::RESTART_GAMEPLAY;
		pauseMenuChangeScenes[2] = Scenes::MAIN_MENU_RESTART_GAMEPLAY;
	}

	void Game::setVersionTextSize() 
	{
		versionTextSize = vectorMath::getScreenHypotenuse() / versionSizeDivider;
	}

	void Game::setversionTextPosition(Vector2 versionTextPosition) 
	{
		this->versionTextPosition = versionTextPosition;
	}

	void Game::setResolution(Vector2 resolution) 
	{
		this->resolution = resolution;
	}

	void Game::setRunning(bool running) 
	{
		this->running = running;
	}

	int Game::getScreenWidth() 
	{
		return screenWidth;
	}

	int Game::getScreenHeight() 
	{
		return screenHeight;
	}

	Vector2 Game::getversionTextPosition() 
	{
		return versionTextPosition;
	}

	Vector2 Game::getResolution() 
	{
		return resolution;
	}

	int Game::getVersionTextSize() 
	{
		return versionTextSize;
	}

	bool Game::getRunning() 
	{
		return running;
	}

	void Game::init()
	{	
		setVersionTextSize();
		setversionTextPosition({ static_cast<float>(GetScreenWidth() * versionXPercentage), static_cast<float>(GetScreenHeight() * versionYPercentage) });			

		sceneManager = new SceneManager(initialScene);
		gameplay = new Gameplay();
		mainMenu = new MainMenu(mainMenuTexts);
		credits = new Credits();
		upgrader = new Upgrader();
		tutorial = new Tutorial();
		endGame = new EndGame();
		pauseMenu = new PauseMenu(pauseMenuChangeScenes);			
		optionsMenu = new OptionsMenu(optionsMenuText);
	}	

	void Game::deinit()
	{
		delete sceneManager;
		delete gameplay;
		delete mainMenu;
		delete credits;
		delete upgrader;
		delete tutorial;
		delete endGame;
		delete pauseMenu;
		delete optionsMenu;
	}

	void Game::drawVersion() 
	{
		DrawText(versionText, static_cast<int>(getversionTextPosition().x), (getversionTextPosition().y), getVersionTextSize(), versionTextColor);
					
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
			case Scenes::OPTIONS_MENU:

				optionsMenu->input(sceneManager, resolution);

				optionsMenu->draw();

				drawVersion();
				break;
			default:

				setRunning(false);
				break;
			}	

			resolutionUpdate();
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

	void Game::resolutionUpdate() 
	{
		if (resolutionChanged())
		{
			setScreenWidth(static_cast<int>(getResolution().x));
			setScreenHeight(static_cast<int>(getResolution().y));

			SetWindowSize(static_cast<int>(getScreenWidth()), static_cast<int>(getScreenHeight()));
			setWindowPosition();

			deinit();
			init();
		}
	}

	bool Game::resolutionChanged() 
	{
		return getScreenWidth() != static_cast<int>(getResolution().x) || getScreenHeight() != static_cast<int>(getResolution().y);
	}

	void Game::setWindowPosition() 
	{
		SetWindowPosition((GetMonitorWidth(GetMonitorCount() - 1) / 2) - (GetScreenWidth() / 2), (GetMonitorHeight(GetMonitorCount() - 1) / 2) - (GetScreenHeight() / 2));
	}
}