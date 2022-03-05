#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <raylib.h>

#include "survivor.h"
#include "zombie.h"
#include "scene_manager.h"
#include "end_game.h"
#include "upgrader.h"
#include "ammunition.h"

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
		const float ammoSizeDivider = 48.0f;
		const float initialtimeToSpawnZombie = 2.0f;
		const float initialTimeToEndRound = 20.0f;		
		const float zombieInitialVelocity = 35.0f;
		const float zombieInitialDamageToDie = 20.0f;
		const float decreasZombieSpawnerPercentage = 0.11f;
		const float addEndRoundTimePercentage = 0.3f;
		const float addMoneyRewardPercentage = 0.45f;
		const float increasedZombiesVelocity = 0.15f;
		const float increasedZombiesDamageToDie = 0.5f;
		const float initialTimeToCreatNewAmmo = 8.5f;

		const int uiSmallSize = 30;
		const int uiBigSize = 40;		

		const short initialRound = 1;
		const short zombiesAdditionNextRound = 1;
		const short initialMoneyForKillingZombie = 20;
		const short maxTimeToEndRound = 300;
		const short maxAmmoPositionValidations = 300;

		static const short maxZombies = 10;
		static const short maxSpawners = 4;
		static const short maxAmmunitions = 24;

		const Scenes pauseMenuScene = Scenes::PAUSE;

		const MouseButton inputButton = MouseButton::MOUSE_BUTTON_LEFT;

		const Scenes upgraderScene = Scenes::UPGRADER;
		const Scenes endGameScene = Scenes::END_GAME;
			
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
		float timerToCreateNewAmmo;

		short round;
		short maxZombiesInRound = 5;
		short moneyForKillingZombie;

		int zombiesKilled;
		int timeSurvived;

		Survivor* playerOne;
		Zombie* zombies[maxZombies];
		Ammunition* ammunitions[maxAmmunitions];
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
		void setTimerToCreateNewAmmo(float timerToCreateNewAmmo);
		void setRound(short round);	
		void nextRound();
		void setMoneyForKillingZombie(short moneyForKillingZombie);
		void setZombiesKilled(int zombiesKilled);		
		void setTimeSurvived(int timeSurvived);		
		void setZombiesToNull();
		void setAmmunitionsToNull();

		void addTimeToSpawnZombie(float value);
		void addTimeToEndRound(float value);
		void addMoneyForKillingZombie(float value);
		void addMaxZombiesInRound(short value);
		void addZombieVelocity(float value);
		void addZombieDamageToDie(float value);
		void addZombiesKilled(short value);
		void addTimeSurvived(short value);
		
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
		float getTimerToCreateNewAmmo();
		short getRound();
		float getGameplaySize();
		short getMoneyForKillingZombie();
		int getZombiesKilled();
		int getTimeSurvived();
		Survivor* getPlayer();
		Vector2 getRandomAmmoPosition(float ammoRadius, short ammoIndex);

		void init();
		void input(SceneManager* sceneManager);
		void update(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader);
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
		short findEmptyAmmoIndex();
		void decreasTimerToEndRound();
		void decreasTimerToCreatNewAmmo();
		void winRound(SceneManager* sceneManager);
		void defeatCondition(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader);
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
		void drawAmmo();
		void pauseGameInput(SceneManager* sceneManager);
		void muteGameInput();
		bool isMouseOnGameplaySpace();
		void increaseStatsForNextRound();
		void resetGameplayForWiningRound();
		void initialGameplayStats();
		void deleteAmmunitions();
		void creatNewAmmo();		
	};
}

#endif
