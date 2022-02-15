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
		const float hudHeightPercentage = 0.36f;		
		const float playerOneRadius = 30.0f;
		const float zombiesRadius = 22.5f;
		const float initialtimeToSpawnZombie = 2.0f;
		static const short maxZombies = 5;
		static const short maxSpawners = 4;		

		Vector2 gameplaySpacePos;
		Vector2 zombiesSpawnsPositions[maxSpawners];
		float gameplaySpaceHeight;	
		float timerToSpawnZombie;
		
		Survivor* playerOne;
		Zombie* zombies[maxZombies];
	public:
		Gameplay();
		~Gameplay();
				
		void setZombiesSpawnsPositions();
		void setTimerToSpawnZombie(float timer);

		float getTimerToSpawnZombie();
		Vector2 getRandomZombieSpawnPosition();

		void init();
		void input();
		void update();
		void draw();
		void deinit();

		void drawHudSpace();
		void updateHudSpace();
		void drawZombies();

		void zombiesUpdate();
		void bulletsCollisionWithZombies();
		void zombiesCollisionWithPlayer();
		void zombiesDeath();

		void updateZombieSpawnTimer();
		void createZombie();
		short findEmptyZombieIndex();
	};
}

#endif
