#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <raylib.h>

#include "survivor.h"
#include "zombie.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE
{
	class Gameplay
	{
	private:
		const Color backgroundColor = LIGHTGRAY;
		const Color gameplaySpaceColor = GRAY;
		const Color playerOneColor = RED;
		const Color zombiesColor = GREEN;
		const Color uiColor = BLACK;
		const Color pauseButtonColor = BLACK;
		const float hudHeightPercentage = 0.26f;		
		const float charactersSizeDivider = 24.0f;		
		const float initialtimeToSpawnZombie = 2.0f;
		const float timeToEndRound = 60.0f;
		const float moneyForKillingZombie = 20;
		const int uiSmallSize = 30;
		const int uiBigSize = 40;		
		const short initialRound = 1;
		static const short maxZombies = 5;
		static const short maxSpawners = 4;
		const Scenes pauseMenuScene = Scenes::PAUSE;
		const MouseButton pauseGameInputButton = MouseButton::MOUSE_BUTTON_LEFT;
		
		Vector2 gameplaySpacePos;
		Vector2 zombiesSpawnsPositions[maxSpawners];
		Vector2 pauseButtonPosition;
		float gameplaySpaceHeight;	
		float timerToSpawnZombie;
		float timerToEndRound;
		float pauseButtonRadius;
		short round;

		Survivor* playerOne;
		Zombie* zombies[maxZombies];
	public:
		Gameplay();
		~Gameplay();
				
		void setZombiesSpawnsPositions();
		void setPauseButtonPosition(Vector2 pauseButtonPosition);
		void setTimerToSpawnZombie(float timer);
		void setTimerToEndRound(float timer);
		void setPauseButtonRadius(float pauseButtonRadius);
		void setRound(short round);
		
		Vector2 getPauseButtonPosition();
		float getTimerToSpawnZombie();
		Vector2 getRandomZombieSpawnPosition();
		float getTimerToEndRound();
		float getPauseButtonRadius();
		short getRound();
		float getGameplaySize();

		void init();
		void input(SceneManager* sceneManager);
		void update();
		void draw();
		void deinit();

		void drawGameplayRectangle();
		void updateHudSpace();
		void drawZombies();

		void zombiesUpdate();
		void bulletsCollisionWithZombies();
		void zombiesCollisionWithPlayer();
		void zombiesDeath();
		void updateZombieSpawnTimer();
		void createZombie();
		short findEmptyZombieIndex();
		void decreasTimerToEndRound();
		void winRound();
		void defeatCondition();
		void drawHud();
		void drawTimer();
		void drawVersion();
		void drawLivesRemaining();
		void drawInbulnerabilityTimer();
		void drawPlayerBulletsUI();
		void drawRoundHud();
		void drawPlayerMoney();
		void drawGameplay();		
		void drawPauseButton();
		void pauseGameInput(SceneManager* sceneManager);
		bool isMouseOnGameplaySpace();
	};
}

#endif
