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
		const Color pauseTextColor = WHITE;
		const Color muteTextColor = YELLOW;

		const float hudHeightPercentage = 0.26f;		
		const float charactersSizeDivider = 24.0f;		
		const float ammoSizeDivider = 48.0f;
		const float initialtimeToSpawnZombie = 2.0f;
		const float initialTimeToEndRound = 30.0f; 		
		const float zombieInitialDamageToDie = 20.0f;
		const float decreasZombieSpawnerPercentage = 0.06f;
		const float addEndRoundTimePercentage = 0.3f;
		const float addMoneyRewardPercentage = 0.45f;
		const float increasedZombiesVelocity = 0.10f;
		const float increasedZombiesDamageToDie = 0.5f;
		const float initialTimeToCreatNewAmmo = 8.5f;
		const float uiSmallSizeDivider = 30.0f;  
		const float uiBigSizeDivider = 23.0f; 
		const float pauseTextSizeDivider = 44.0f;  
		const float muteTextSizeDivider = 44.0f; 
		const float pauseButtonWidthPercentage = 0.95f;
		const float pauseButtonHeightPercentage = 1.4f;
		const float muteButtonWidthPercentage = 0.85f;
		const float muteButtonHeightPercentage = 1.4f;
		const float zombieInitialVelocityDivider = 36.0f;

		const short initialRound = 1;
		const short zombiesAdditionNextRound = 1;
		const short initialMoneyForKillingZombie = 20; 
		const short maxTimeToEndRound = 300;
		const short maxAmmoPositionValidations = 300;
		const short initialMaxZombiesInRound = 5;
		
		static const short maxZombies = 20;
		static const short maxSpawners = 4;
		static const short maxAmmunitions = 24;

		const char* pauseText = "P";
		const char* muteText = "M";		

		const MouseButton inputButton = MouseButton::MOUSE_BUTTON_LEFT;

		const Scenes pauseMenuScene = Scenes::PAUSE_MENU;
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
		float zombieInitialVelocity;
		float zombieVelocity;
		float zombieDamageToDie;
		float timerToCreateNewAmmo;

		short round;
		short maxZombiesInRound;
		short moneyForKillingZombie;

		int uiSmallSize; 
		int uiBigSize; 
		int pauseTextSize; 
		int muteTextSize; 
		int zombiesKilled;
		float timeSurvived;

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

		void setZombieInitialVelocity();

		void setZombieVelocity(float zombieVelocity);
		void setZombieDamageToDie(float zombieDamageToDie);
		void setTimerToCreateNewAmmo(float timerToCreateNewAmmo);
		void setRound(short round);	
		void nextRound();
		void setMaxZombiesInRound(short maxZombiesInRound);
		void setMoneyForKillingZombie(short moneyForKillingZombie);
		void setUiSmallSize();
		void setUiBigSize(); 
		void setPauseTextSize();
		void setMuteTextSize();
		void setZombiesKilled(int zombiesKilled);		
		void setTimeSurvived(float timeSurvived);	
		void setZombiesToNull();
		void setAmmunitionsToNull();

		void addTimeToSpawnZombie(float value);
		void addTimeToEndRound(float value);
		void addMoneyForKillingZombie(float value);
		void addMaxZombiesInRound(short value);
		void addZombieVelocity(float value);
		void addZombieDamageToDie(float value);
		void addZombiesKilled(short value);
		void addTimeSurvived(float value);
		
		Vector2 getPauseButtonPosition();
		Vector2 getMuteButtonPosition();
		float getTimerToSpawnZombie();
		float getRoundStartingTimerToSpawnZombie();
		Vector2 getRandomZombieSpawnPosition();
		float getTimerToEndRound();
		float getRoundStartingTimerToEndRound();
		float getPauseButtonRadius();
		float getMuteButtonRadius();
		float getZombieInitialVelocity();
		float getZombieVelocity();
		float getZombieDamageToDie();
		float getTimerToCreateNewAmmo();
		short getRound();
		float getGameplaySize();
		short getMoneyForKillingZombie();		
		int getUiSmallSize();
		int getUiBigSize();
		int getPauseTextSize();
		int getMuteTextSize();
		int getZombiesKilled();
		float getTimeSurvived();
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
		bool isZombieCollidingWithPlayer(short index);
		void zombiesCollisionWithEachOther();

		void playerPickUpAmmo();

		void zombiesDeath();
		void destroyZombies();
		void updateZombieSpawnTimer();
		void createZombie();		
		short findEmptyZombieIndex();

		short findEmptyAmmoIndex();

		void decreasTimerToEndRound();
		void decreasTimerToCreatNewAmmo();

		void winRound(SceneManager* sceneManager, Upgrader* upgrader);
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

		void restartGameplay(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader, Scenes changeScene);
	};
}

#endif
