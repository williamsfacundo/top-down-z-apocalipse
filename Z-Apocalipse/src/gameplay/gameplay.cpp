#include "gameplay.h"

#include <iostream>
#include <cmath>

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
		float zombiesRadius = getGameplaySize() / charactersSizeDivider;
		
		zombiesSpawnsPositions[0] = { zombiesRadius / 2.0f, gameplaySpacePos.y + (zombiesRadius / 2.0f) };
		zombiesSpawnsPositions[1] = { static_cast<float>(GetScreenWidth()) - (zombiesRadius / 2.0f), gameplaySpacePos.y + (zombiesRadius / 2.0f) };
		zombiesSpawnsPositions[2] = { zombiesRadius / 2.0f, gameplaySpacePos.y + gameplaySpaceHeight - (zombiesRadius / 2.0f) };
		zombiesSpawnsPositions[3] = { static_cast<float>(GetScreenWidth()) - (zombiesRadius / 2.0f), gameplaySpacePos.y + gameplaySpaceHeight - (zombiesRadius / 2.0f) };
	}

	void Gameplay::setPauseButtonPosition(Vector2 pauseButtonPosition)
	{
		this->pauseButtonPosition = pauseButtonPosition;
	}

	void Gameplay::setTimerToSpawnZombie(float timer) 
	{
		this->timerToSpawnZombie = timer;
	}

	void Gameplay::setRoundStartingTimerToSpawnZombie(float roundStartingTimerToSpawnZombie) 
	{
		this->roundStartingTimerToSpawnZombie = roundStartingTimerToSpawnZombie;
	}

	void Gameplay::setTimerToEndRound(float timer) 
	{
		this->timerToEndRound = timer;
	}

	void Gameplay::setRoundStartingTimerToEndRound(float roundStartingTimerToEndRound) 
	{
		this->roundStartingTimerToEndRound = roundStartingTimerToEndRound;
	}

	void Gameplay::setPauseButtonRadius(float pauseButtonRadius)
	{
		this->pauseButtonRadius = pauseButtonRadius;
	}

	void Gameplay::setZombieVelocity(float zombieVelocity)
	{
		this->zombieVelocity = zombieVelocity;
	}

	void Gameplay::setZombieDamageToDie(float zombieDamageToDie)
	{
		this->zombieDamageToDie = zombieDamageToDie;
	}

	void Gameplay::setRound(short round)
	{
		this->round = round;
	}		

	void Gameplay::nextRound() 
	{
		round += 1;
	}

	void Gameplay::setMoneyForKillingZombie(short moneyForKillingZombie) 
	{
		this->moneyForKillingZombie = moneyForKillingZombie;
	}

	void Gameplay::addTimeToSpawnZombie(float value) 
	{
		timerToSpawnZombie += value;
	}

	void Gameplay::addTimeToEndRound(float value) 
	{
		timerToEndRound += value;
	}

	void Gameplay::addMoneyForKillingZombie(float value)
	{
		this->moneyForKillingZombie += value;
	}

	void Gameplay::addMaxZombiesInRound(short value) 
	{
		this->maxZombiesInRound += value;
	}

	void Gameplay::addZombieVelocity(float value) 
	{
		this->zombieVelocity += value;
	}

	void Gameplay::addZombieDamageToDie(float value) 
	{
		this->zombieDamageToDie += value;
	}

	Vector2 Gameplay::getPauseButtonPosition()
	{
		return pauseButtonPosition;
	}

	float Gameplay::getTimerToSpawnZombie() 
	{
		return timerToSpawnZombie;
	}

	float Gameplay::getRoundStartingTimerToSpawnZombie() 
	{
		return roundStartingTimerToSpawnZombie;
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

	float Gameplay::getRoundStartingTimerToEndRound() 
	{
		return roundStartingTimerToEndRound;
	}

	float Gameplay::getPauseButtonRadius()
	{
		return pauseButtonRadius;
	}

	float Gameplay::getZombieVelocity() 
	{
		return zombieVelocity;
	}

	float Gameplay::getZombieDamageToDie() 
	{
		return zombieDamageToDie;
	}

	short Gameplay::getRound() 
	{
		return round;
	}

	float Gameplay::getGameplaySize() 
	{
		float width = GetScreenWidth();
		float height = GetScreenHeight() - (GetScreenHeight() * hudHeightPercentage);
		float h = sqrtf(powf(width, 2) + powf(height, 2));

		return h;
	}

	short Gameplay::getMoneyForKillingZombie() 
	{
		return moneyForKillingZombie;
	}

	void Gameplay::init()
	{		
		playerOne = new Survivor(playerOneColor, { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, (getGameplaySize() / charactersSizeDivider) / 2.0f,
			{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		
		for (short i = 0; i < maxZombiesInRound; i++) 
		{
			zombies[i] = NULL;
		}

		setZombiesSpawnsPositions();
		setPauseButtonRadius((GetScreenHeight() * (hudHeightPercentage / 3.0f)) / 2.0f);
		setPauseButtonPosition({ static_cast<float>(GetScreenWidth() - (GetScreenWidth() / 15)), getPauseButtonRadius() * 1.4f});
		setTimerToSpawnZombie(initialtimeToSpawnZombie);		
		setTimerToEndRound(initialTimeToEndRound);		
		setZombieVelocity(zombieInitialVelocity);
		setZombieDamageToDie(zombieInitialDamageToDie);
		setRound(initialRound);		
		setMoneyForKillingZombie(initialMoneyForKillingZombie);
		setRoundStartingTimerToSpawnZombie(initialtimeToSpawnZombie);
		setRoundStartingTimerToEndRound(initialTimeToEndRound);
	}
	
	void Gameplay::input(SceneManager* sceneManager)
	{
		playerOne->input(isMouseOnGameplaySpace());

		pauseGameInput(sceneManager);
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
				
		drawGameplay();
		drawHud();
		
		EndDrawing();
	}
	
	void Gameplay::deinit() 
	{
		delete playerOne;

		for (short i = 0; i < maxZombiesInRound; i++) 
		{
			if (zombies[i] != NULL)
			{
				delete zombies[i];
				zombies[i] = NULL;
			}
		}
	}

	void Gameplay::drawGameplayRectangle() 
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
		for (short i = 0; i < maxZombiesInRound; i++) 
		{
			if (zombies[i] != NULL) 
			{
				zombies[i]->draw();
			}
		}
	}

	void Gameplay::zombiesUpdate() 
	{
		for (short i = 0; i < maxZombiesInRound; i++)
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
				for (short v = 0; v < maxZombiesInRound; v++) 
				{
					if (zombies[v] != NULL) 
					{
						if (CheckCollisionCircles(playerOne->getBullet(i)->getPosition(), playerOne->getBullet(i)->getRadius(),
							zombies[v]->getPosition(), zombies[v]->getRadius())) 
						{
							zombies[v]->addDamageTaken(playerOne->getDamage());							

							playerOne->destroyBullet(i);
							v = maxZombiesInRound;
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
			for (short i = 0; i < maxZombiesInRound; i++)
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
		for(short i = 0; i < maxZombiesInRound; i++)
		{
			if (zombies[i] != NULL) 
			{
				if (zombies[i]->isZombieDead()) 
				{
					playerOne->addMoney(moneyForKillingZombie);

					delete zombies[i];
					zombies[i] = NULL;
				}
			}
		}
	}

	void Gameplay::destroyZombies() 
	{
		for (short i = 0; i < maxZombies; i++)
		{
			if (zombies[i] != NULL)
			{
				delete zombies[i];
				zombies[i] = NULL;
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
		if (Zombie::getZombiesCreated() < maxZombiesInRound) 
		{			
			zombies[findEmptyZombieIndex()] = new Zombie(zombiesColor, getRandomZombieSpawnPosition(), (getGameplaySize() / charactersSizeDivider) / 2.0f,
				{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight }, getZombieDamageToDie(), getZombieVelocity());
		}		
	}

	short Gameplay::findEmptyZombieIndex() 
	{
		for (short i = 0; i < maxZombiesInRound; i++) 
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
		nextRound();
		playerOne->setInitialRoundMoney(playerOne->getMoney());
		increaseStatsForNextRound();
		resetGameplay();
	}

	void Gameplay::defeatCondition() 
	{
		if (playerOne->getLives() <= 0) 
		{			
			resetGameplay();
		}
	}

	void Gameplay::drawHud() 
	{
		drawTimer();		
		drawLivesRemaining();
		drawInbulnerabilityTimer();
		drawPlayerBulletsUI();
		drawReloadingText();
		drawRoundHud();
		drawPlayerMoney();
		drawPauseButton();		
	}

	void Gameplay::drawTimer() 
	{					
		DrawText(TextFormat("%i", static_cast<int>(timerToEndRound)), GetScreenWidth() / 2 - uiSmallSize, static_cast<int>(gameplaySpacePos.y / 2), uiSmallSize, uiColor);
	}

	void Gameplay::drawVersion() 
	{
		DrawText("v 0.1", GetScreenWidth() - ((uiBigSize / 2) * 5), GetScreenHeight() - uiBigSize, uiBigSize, uiColor);
	}

	void Gameplay::drawLivesRemaining() 
	{
		DrawText(TextFormat("Lives: %i", playerOne->getLives()), uiSmallSize, static_cast<int>(gameplaySpacePos.y / 2), uiSmallSize, uiColor);
	}

	void Gameplay::drawInbulnerabilityTimer() 
	{
		if (playerOne->getInvulnerabilityTimer() > 0.0f)
		{
			DrawText(TextFormat("(INVULNERABILITY)"), uiSmallSize * 5, static_cast<int>(gameplaySpacePos.y / 2), static_cast<int>(uiSmallSize * 0.55f), uiColor);
		}
	}

	void Gameplay::drawPlayerBulletsUI() 
	{
		DrawText(TextFormat("%i", playerOne->getBulletsInCharger()), static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 4), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight), uiSmallSize, uiColor);
		DrawText("/", static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 3), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight), uiSmallSize, uiColor);
		DrawText(TextFormat("%i", playerOne->getRemainingBullets()), static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 2), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight), uiSmallSize, uiColor);
	}

	void Gameplay::drawReloadingText() 
	{
		if(playerOne->getReloadTimer() > 0.0f)
		{
			DrawText("(RELOADING)", static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 4),
				static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + uiSmallSize),
				static_cast<int>(uiSmallSize * 0.55f), uiColor);
		}		
	}

	void Gameplay::drawRoundHud() 
	{
		DrawText(TextFormat("Round %i", getRound()), uiSmallSize, static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight), uiSmallSize, uiColor);
	}

	void Gameplay::drawPlayerMoney() 
	{
		DrawText(TextFormat("$ %i", playerOne->getMoney()), GetScreenWidth() - (uiBigSize * 4), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight), uiSmallSize, uiColor);
	}

	void Gameplay::drawGameplay() 
	{
		drawGameplayRectangle();
		drawZombies();
		playerOne->draw();
	}

	void Gameplay::drawPauseButton() 
	{
		DrawCircleV(getPauseButtonPosition(), getPauseButtonRadius(), pauseButtonColor);
	}

	void Gameplay::pauseGameInput(SceneManager* sceneManager)
	{
		if (CheckCollisionPointCircle(GetMousePosition(), getPauseButtonPosition(), getPauseButtonRadius())
			&& IsMouseButtonPressed(pauseGameInputButton))
		{
			sceneManager->setCurrentScene(pauseMenuScene);
		}
	}

	bool Gameplay::isMouseOnGameplaySpace()
	{		
		float y = GetScreenHeight() * (hudHeightPercentage / 2.0f);
		float height = GetScreenHeight() - (GetScreenHeight() * hudHeightPercentage);

		return CheckCollisionPointRec(GetMousePosition(), { 0.0f, y, static_cast<float>(GetScreenWidth()), height });
	}

	void Gameplay::increaseStatsForNextRound()
	{
		setTimerToSpawnZombie(getRoundStartingTimerToSpawnZombie());
		setTimerToEndRound(getRoundStartingTimerToEndRound());
		addTimeToSpawnZombie(-(getRoundStartingTimerToSpawnZombie() * decreasZombieSpawnerPercentage));
		addTimeToEndRound(getRoundStartingTimerToEndRound() * addEndRoundTimePercentage);
		setRoundStartingTimerToSpawnZombie(getTimerToSpawnZombie());
		setRoundStartingTimerToEndRound(getTimerToEndRound());
		
		addMoneyForKillingZombie(getMoneyForKillingZombie() * addMoneyRewardPercentage);
		addMaxZombiesInRound(zombiesAdditionNextRound);
		addZombieVelocity(getZombieVelocity() * increasedZombiesVelocity);
		addZombieDamageToDie(getZombieDamageToDie() * increasedZombiesDamageToDie);
				
	}

	void Gameplay::resetGameplay() 
	{
		setTimerToSpawnZombie(getRoundStartingTimerToSpawnZombie());
		setTimerToEndRound(getRoundStartingTimerToEndRound());
				
		destroyZombies();

		playerOne->resetSurvivor({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
	}
}