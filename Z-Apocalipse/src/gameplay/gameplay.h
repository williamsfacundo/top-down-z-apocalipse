#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "survivor.h"
#include "zombie.h"

#include <raylib.h>

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
		
		Vector2 gameplaySpacePos;
		Vector2 zombiesSpawnsPositions[maxSpawners];
		float gameplaySpaceHeight;	
		float timerToSpawnZombie;
		float timerToEndRound;
		short round;

		Survivor* playerOne;
		Zombie* zombies[maxZombies];
	public:
		Gameplay();
		~Gameplay();
				
		void setZombiesSpawnsPositions();
		void setTimerToSpawnZombie(float timer);
		void setTimerToEndRound(float timer);
		void setRound(short round);

		float getTimerToSpawnZombie();
		Vector2 getRandomZombieSpawnPosition();
		float getTimerToEndRound();
		short getRound();
		float getGameplaySize();

		void init();
		void input();
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
	};
}

#endif
