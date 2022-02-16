#include "gameplay.h"

#include <iostream>
#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Gameplay::Gameplay()
	{
		updateHudSpace();
		init();		
	}

	Gameplay::~Gameplay() 
	{
		deinit();
	}

	void Gameplay::setZombiesSpawnsPositions()
	{
		zombiesSpawnsPositions[0] = { zombiesRadius / 2.0f, gameplaySpacePos.y + (zombiesRadius / 2.0f) };
		zombiesSpawnsPositions[1] = { static_cast<float>(GetScreenWidth()) - (zombiesRadius / 2.0f), gameplaySpacePos.y + (zombiesRadius / 2.0f) };
		zombiesSpawnsPositions[2] = { zombiesRadius / 2.0f, gameplaySpacePos.y + gameplaySpaceHeight - (zombiesRadius / 2.0f) };
		zombiesSpawnsPositions[3] = { static_cast<float>(GetScreenWidth()) - (zombiesRadius / 2.0f), gameplaySpacePos.y + gameplaySpaceHeight - (zombiesRadius / 2.0f) };
	}

	void Gameplay::setTimerToSpawnZombie(float timer) 
	{
		this->timerToSpawnZombie = timer;
	}

	void Gameplay::setTimerToEndRound(float timer) 
	{
		this->timerToEndRound = timer;
	}

	float Gameplay::getTimerToSpawnZombie() 
	{
		return timerToSpawnZombie;
	}

	Vector2 Gameplay::getRandomZombieSpawnPosition() 
	{
		Vector2 pos = { 0.0f, 0.0f };
		short random = GetRandomValue(1, 4); 

		switch (random)
		{
		case 1:
			pos = zombiesSpawnsPositions[0];
			break;
		case 2:
			pos = zombiesSpawnsPositions[1];
			break;
		case 3:
			pos = zombiesSpawnsPositions[2];
			break;
		case 4:
			pos = zombiesSpawnsPositions[3];
			break;
		default:
			pos = zombiesSpawnsPositions[0];
			break;
		}

		return pos;
	}

	float Gameplay::getTimerToEndRound() 
	{
		return timerToEndRound;
	}

	void Gameplay::init()
	{		
		playerOne = new Survivor(playerOneColor, { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, playerOneRadius, 
			{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		
		for (short i = 0; i < maxZombies; i++) 
		{
			zombies[i] = NULL;
		}

		setZombiesSpawnsPositions();
		setTimerToSpawnZombie(initialtimeToSpawnZombie);		
		setTimerToEndRound(timeToEndRound);
	}
	
	void Gameplay::input() 
	{
		playerOne->input();
	}
	
	void Gameplay::update() 
	{			
		playerOne->update({ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		updateZombieSpawnTimer();
		zombiesUpdate();
		bulletsCollisionWithZombies();
		zombiesDeath();
		zombiesCollisionWithPlayer();		
		decreasTimerToEndRound();
		defeatCondition();
	}
	
	void Gameplay::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);
				
		drawHudSpace();
		drawTimer();
		drawVersion();
		drawLivesRemaining();
		drawInbulnerabilityTimer();
		drawZombies();
		playerOne->draw();

		EndDrawing();
	}
	
	void Gameplay::deinit() 
	{
		delete playerOne;

		for (short i = 0; i < maxZombies; i++) 
		{
			if (zombies[i] != NULL)
			{
				delete zombies[i];
				zombies[i] = NULL;
			}
		}
	}

	void Gameplay::drawHudSpace() 
	{
		DrawRectangleV(gameplaySpacePos, {static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight}, gameplaySpaceColor);
	}

	void Gameplay::updateHudSpace()
	{
		gameplaySpaceHeight = GetScreenHeight() - (GetScreenHeight() * hudHeightPercentage);
		gameplaySpacePos.y = GetScreenHeight() * (hudHeightPercentage / 2.0f);
	}

	void Gameplay::drawZombies() 
	{
		for (short i = 0; i < maxZombies; i++) 
		{
			if (zombies[i] != NULL) 
			{
				zombies[i]->draw();
			}
		}
	}

	void Gameplay::zombiesUpdate() 
	{
		for (short i = 0; i < maxZombies; i++)
		{
			if (zombies[i] != NULL)
			{
				zombies[i]->update(playerOne->getPosition());
			}
		}
	}

	void Gameplay::bulletsCollisionWithZombies() 
	{
		for (short i = 0; i < playerOne->getMaxBullets(); i++) 
		{
			if (!playerOne->isBulletNull(i)) 
			{
				for (short v = 0; v < maxZombies; v++) 
				{
					if (zombies[v] != NULL) 
					{
						if (CheckCollisionCircles(playerOne->getBullet(i)->getPosition(), playerOne->getBullet(i)->getRadius(),
							zombies[v]->getPosition(), zombies[v]->getRadius())) 
						{
							zombies[v]->addDamageTaken(playerOne->getDamage());							

							playerOne->destroyBullet(i);
							v = maxZombies;
						}
					}
				}
			}
		}
	}

	void Gameplay::zombiesCollisionWithPlayer() 
	{
		if (!playerOne->isSurvivorInvulnerable()) 
		{
			for (short i = 0; i < maxZombies; i++)
			{
				if (zombies[i] != NULL)
				{
					if (CheckCollisionCircles(zombies[i]->getPosition(), zombies[i]->getRadius(),
						playerOne->getPosition(), playerOne->getRadius()))
					{
						playerOne->hitByZombie();
					}
				}
			}
		}		
	}

	void Gameplay::zombiesDeath() 
	{
		for(short i = 0; i < maxZombies; i++)
		{
			if (zombies[i] != NULL) 
			{
				if (zombies[i]->isZombieDead()) 
				{
					delete zombies[i];
					zombies[i] = NULL;
				}
			}
		}
	}

	void Gameplay::updateZombieSpawnTimer() 
	{
		if (timerToSpawnZombie > 0.0f)
		{
			timerToSpawnZombie -= GetFrameTime();

			if (timerToSpawnZombie < 0.0f)
			{
				timerToSpawnZombie = 0.0f;
			}
		}
		else 
		{
			createZombie();
			timerToSpawnZombie = initialtimeToSpawnZombie;
		}
	}

	void Gameplay::createZombie() 
	{
		if (Zombie::getZombiesCreated() < maxZombies) 
		{			
			zombies[findEmptyZombieIndex()] = new Zombie(zombiesColor, getRandomZombieSpawnPosition(), zombiesRadius,
				{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight }, 1);
		}		
	}

	short Gameplay::findEmptyZombieIndex() 
	{
		for (short i = 0; i < maxZombies; i++) 
		{
			if (zombies[i] == NULL) 
			{
				return i;
			}
		}

		return 0;
	}

	void Gameplay::decreasTimerToEndRound() 
	{
		if (timerToEndRound > 0.0f)
		{
			timerToEndRound -= GetFrameTime();

			if (timerToEndRound < 0.0f)
			{
				timerToEndRound = 0.0f;
			}
		}	
		else 
		{
			winRound();
		}
	}

	void Gameplay::winRound() 
	{
		deinit();
		init();
	}

	void Gameplay::defeatCondition() 
	{
		if (playerOne->getLives() <= 0) 
		{			
			deinit();
			init();
		}
	}

	void Gameplay::drawTimer() 
	{					
		DrawText(TextFormat("%i", static_cast<int>(timerToEndRound)), GetScreenWidth() / 2 - uiSmallSize, static_cast<int>(gameplaySpacePos.y), uiSmallSize, uiColor);
	}

	void Gameplay::drawVersion() 
	{
		DrawText("v 0.1", GetScreenWidth() - ((uiBigSize / 2) * 5), GetScreenHeight() - uiBigSize, uiBigSize, uiColor);
	}

	void Gameplay::drawLivesRemaining() 
	{
		DrawText(TextFormat("Lives: %i", playerOne->getLives()), uiSmallSize, static_cast<int>(gameplaySpacePos.y), uiSmallSize, uiColor);
	}

	void Gameplay::drawInbulnerabilityTimer() 
	{
		
	}
}