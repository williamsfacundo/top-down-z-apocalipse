#include "gameplay.h"

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

	void Gameplay::init()
	{		
		playerOne = new Survivor(playerOneColor, { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, playerOneRadius, 
			{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		
		for (short i = 0; i < maxZombies; i++) 
		{
			zombies[i] = NULL;
		}

		for (short i = 0; i < maxZombies; i++) 
		{ 
			zombies[i] = new Zombie(zombiesColor, { GetScreenWidth() / 2.0f + 300, GetScreenHeight() / 2.0f }, zombiesRadius,
				{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight }, 1);
		}
	}
	
	void Gameplay::input() 
	{
		playerOne->input();
	}
	
	void Gameplay::update() 
	{
		playerOne->update({ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		zombiesUpdate();
		bulletsCollisionWithZombies();
		zombiesDeath();
	}
	
	void Gameplay::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		drawHudSpace();
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
}