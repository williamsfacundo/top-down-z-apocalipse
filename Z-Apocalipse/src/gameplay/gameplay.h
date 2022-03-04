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
		const Color muteButtonColor = RED;
		const float hudHeightPercentage = 0.26f;		
		const float charactersSizeDivider = 24.0f;		
		const float initialtimeToSpawnZombie = 2.0f;
		const float initialTimeToEndRound = 60.0f;		
		const float zombieInitialVelocity = 35.0f;
		const float zombieInitialDamageToDie = 20.0f;
		const float decreasZombieSpawnerPercentage = 0.11f;
		const float addEndRoundTimePercentage = 0.3f;
		const float addMoneyRewardPercentage = 0.45f;
		const float increasedZombiesVelocity = 0.15f;
		const float increasedZombiesDamageToDie = 0.5f;
		const int uiSmallSize = 30;
		const int uiBigSize = 40;		
		const short initialRound = 1;
		const short zombiesAdditionNextRound = 1;
		const short initialMoneyForKillingZombie = 20;
		const short maxTimeToEndRound = 300;
		static const short maxZombies = 10;
		static const short maxSpawners = 4;
		const Scenes pauseMenuScene = Scenes::PAUSE;
		const MouseButton inputButton = MouseButton::MOUSE_BUTTON_LEFT;
		const Scenes upgraderScene = Scenes::UPGRADER;
			
		Vector2 gameplaySpacePos;
		Vector2 zombiesSpawnsPositions[maxSpawners];
		Vector2 pauseButtonPosition;
		Vector2 muteButtonPosition;
		float gameplaySpaceHeight;	
		float timerToSpawnZombie;
		float roundStartingTimerToSpawnZombie;
		float timerToEndRound;
		float roundStartingTimerToEndRound;
		float pauseButtonRadius;		
		float muteButtonRadius;
		float zombieVelocity;
		float zombieDamageToDie;
		short round;
		short maxZombiesInRound = 5;
		short moneyForKillingZombie;

		Survivor* playerOne;
		Zombie* zombies[maxZombies];
	public:
		Gameplay();
		~Gameplay();
				
		void setZombiesSpawnsPositions();
		void setPauseButtonPosition(Vector2 pauseButtonPosition);
		void setMuteButtonPosition(Vector2 muteButtonPosition);
		void setTimerToSpawnZombie(float timer);
		void setRoundStartingTimerToSpawnZombie(float roundStartingTimerToSpawnZombie);
		void setTimerToEndRound(float timer);
		void setRoundStartingTimerToEndRound(float roundStartingTimerToEndRound);
		void setPauseButtonRadius(float pauseButtonRadius);
		void setMuteButtonRadius(float muteButtonRadius);
		void setZombieVelocity(float zombieVelocity);
		void setZombieDamageToDie(float zombieDamageToDie);
		void setRound(short round);	
		void nextRound();
		void setMoneyForKillingZombie(short moneyForKillingZombie);

		void addTimeToSpawnZombie(float value);
		void addTimeToEndRound(float value);
		void addMoneyForKillingZombie(float value);
		void addMaxZombiesInRound(short value);
		void addZombieVelocity(float value);
		void addZombieDamageToDie(float value);
		
		Vector2 getPauseButtonPosition();
		Vector2 getMuteButtonPosition();
		float getTimerToSpawnZombie();
		float getRoundStartingTimerToSpawnZombie();
		Vector2 getRandomZombieSpawnPosition();
		float getTimerToEndRound();
		float getRoundStartingTimerToEndRound();
		float getPauseButtonRadius();
		float getMuteButtonRadius();
		float getZombieVelocity();
		float getZombieDamageToDie();
		short getRound();
		float getGameplaySize();
		short getMoneyForKillingZombie();
		Survivor* getPlayer();

		void init();
		void input(SceneManager* sceneManager);
		void update(SceneManager* sceneManager);
		void draw();
		void deinit();

		void drawGameplayRectangle();
		void updateHudSpace();
		void drawZombies();

		void zombiesUpdate();
		void bulletsCollisionWithZombies();
		void zombiesCollisionWithPlayer();
		void zombiesCollisionWithEachOther();
		void zombiesDeath();
		void destroyZombies();
		void updateZombieSpawnTimer();
		void createZombie();
		short findEmptyZombieIndex();
		void decreasTimerToEndRound();
		void winRound(SceneManager* sceneManager);
		void defeatCondition();
		void drawHud();
		void drawTimer();		
		void drawLivesRemaining();
		void drawInbulnerabilityTimer();
		void drawPlayerBulletsUI();
		void drawReloadingText();
		void drawRoundHud();
		void drawPlayerMoney();
		void drawGameplay();		
		void drawPauseButton();
		void drawMuteButton();
		void pauseGameInput(SceneManager* sceneManager);
		void muteGameInput();
		bool isMouseOnGameplaySpace();
		void increaseStatsForNextRound();
		void resetGameplay();
	};
}

#endif
