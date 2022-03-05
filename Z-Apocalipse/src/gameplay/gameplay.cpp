#include "gameplay.h"

#include <iostream>
#include <cmath>

#include <raylib.h>
#include "..\math\math.h"

#include "survivor.h"
#include "zombie.h"
#include "scene_manager.h"
#include "end_game.h"
#include "upgrader.h"

namespace Z_APOCALIPSE 
{
	using namespace vectorMath;

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

	void Gameplay::setMuteButtonPosition(Vector2 muteButtonPosition) 
	{
		this->muteButtonPosition = muteButtonPosition;
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

	void Gameplay::setMuteButtonRadius(float muteButtonRadius) 
	{
		this->muteButtonRadius = muteButtonRadius;
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

	void Gameplay::setZombiesKilled(int zombiesKilled) 
	{
		this->zombiesKilled = zombiesKilled;
	}	

	void Gameplay::setTimeSurvived(int timeSurvived) 
	{
		this->timeSurvived = timeSurvived;
	}

	void Gameplay::setZombiesToNull() 
	{
		for (short i = 0; i < maxZombiesInRound; i++)
		{
			zombies[i] = NULL;
		}
	}

	void Gameplay::addTimeToSpawnZombie(float value) 
	{
		timerToSpawnZombie += value;
	}

	void Gameplay::addTimeToEndRound(float value) 
	{
		if (getTimerToEndRound() + value < maxTimeToEndRound) 
		{
			timerToEndRound += value;
		}		
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

	void Gameplay::addZombiesKilled(short value)
	{
		zombiesKilled += value;
	}

	void Gameplay::addTimeSurvived(short value) 
	{
		timeSurvived += value;
	}

	Vector2 Gameplay::getPauseButtonPosition()
	{
		return pauseButtonPosition;
	}

	Vector2 Gameplay::getMuteButtonPosition() 
	{
		return muteButtonPosition;
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

	float Gameplay::getMuteButtonRadius() 
	{
		return muteButtonRadius;
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

	int Gameplay::getZombiesKilled() 
	{
		return zombiesKilled;
	}

	int Gameplay::getTimeSurvived()
	{
		return timeSurvived;
	}

	Survivor* Gameplay::getPlayer()
	{
		return playerOne;
	}

	void Gameplay::init()
	{		
		playerOne = new Survivor(playerOneColor, { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, (getGameplaySize() / charactersSizeDivider) / 2.0f,
			{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		
		setZombiesToNull();

		setZombiesSpawnsPositions();
		setPauseButtonRadius((GetScreenHeight() * (hudHeightPercentage / 3.0f)) / 2.0f);
		setPauseButtonPosition({ static_cast<float>(GetScreenWidth() * 0.95f), getPauseButtonRadius() * 1.4f });
		setMuteButtonRadius(getPauseButtonRadius());
		setMuteButtonPosition({ static_cast<float>(GetScreenWidth() * 0.85f), getPauseButtonRadius() * 1.4f });

		initialGameplayStats();

		setZombiesKilled(0);
		setTimeSurvived(0);
	}
	
	void Gameplay::input(SceneManager* sceneManager)
	{
		playerOne->input(isMouseOnGameplaySpace());

		pauseGameInput(sceneManager);
		//muteGameInput();
	}
	
	void Gameplay::update(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader)
	{			
		playerOne->update({ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		updateZombieSpawnTimer();
		zombiesUpdate();
		bulletsCollisionWithZombies();
		zombiesDeath();
		zombiesCollisionWithPlayer();	
		zombiesCollisionWithEachOther();
		decreasTimerToEndRound();
		winRound(sceneManager);
		defeatCondition(sceneManager, endGame, upgrader);
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

	void Gameplay::zombiesCollisionWithEachOther() 
	{
		Vector2 normal;
		float depth;

		for (short i = 0; i < maxZombiesInRound; i++) 
		{
			if (zombies[i] != NULL) 
			{
				for (short v = 0; v < maxZombiesInRound; v++) 
				{
					if (zombies[v] != NULL) 
					{
						if (circlesCollision(zombies[i]->getPosition(), zombies[i]->getRadius(), zombies[v]->getPosition(), zombies[v]->getRadius(), normal, depth))
						{
							normal = { normal.x * (depth / 2), normal.y * (depth / 2) };							
							zombies[i]->move(normal);
							normal = { normal.x * -1, normal.y * -1 };
							zombies[v]->move(normal);
						}
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
					addZombiesKilled(1);

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
				addTimeSurvived(1);
			}
		}		
	}

	void Gameplay::winRound(SceneManager* sceneManager) 
	{	
		if (getTimerToEndRound() == 0.0f ) 
		{
			nextRound();
			playerOne->setInitialRoundMoney(playerOne->getMoney());
			increaseStatsForNextRound();
			resetGameplayForWiningRound();
			sceneManager->setCurrentScene(upgraderScene);
		}		
	}

	void Gameplay::defeatCondition(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader)
	{		
		if (playerOne->getLives() <= 0) 
		{			
			initialGameplayStats();

			playerOne->startingSurvivorStats();

			upgrader->resetLevels();
			
			sceneManager->setCurrentScene(endGameScene);
			endGame->calculateScore(getZombiesKilled(), getTimeSurvived());

			setZombiesKilled(0);
			setTimeSurvived(0);
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
		drawMuteButton();
	}

	void Gameplay::drawTimer() 
	{					
		DrawText(TextFormat("%i", static_cast<int>(timerToEndRound)), GetScreenWidth() / 2 - uiSmallSize, static_cast<int>((gameplaySpacePos.y / 2) - (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
	}	

	void Gameplay::drawLivesRemaining() 
	{
		DrawText(TextFormat("Lives: %i", playerOne->getLives()), uiSmallSize, static_cast<int>((gameplaySpacePos.y / 2) - (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
	}

	void Gameplay::drawInbulnerabilityTimer() 
	{
		if (playerOne->getInvulnerabilityTimer() > 0.0f)
		{
			DrawText(TextFormat("(INVULNERABILITY)"), uiSmallSize * 5, static_cast<int>((gameplaySpacePos.y / 2) - (GetScreenWidth() * (hudHeightPercentage / 16))), static_cast<int>(uiSmallSize * 0.55f), uiColor);
		}
	}

	void Gameplay::drawPlayerBulletsUI() 
	{
		DrawText(TextFormat("%i", playerOne->getBulletsInCharger()), static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 4), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
		DrawText("/", static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 3), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
		DrawText(TextFormat("%i", playerOne->getRemainingBullets()), static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 2), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
	}

	void Gameplay::drawReloadingText() 
	{
		if(playerOne->getReloadTimer() > 0.0f)
		{
			DrawText("(RELOADING)", static_cast<int>(GetScreenWidth() / 1.6f) - (uiBigSize * 4),
				static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + uiSmallSize + (GetScreenWidth() * (hudHeightPercentage / 16))),
				static_cast<int>(uiSmallSize * 0.55f), uiColor);
		}		
	}

	void Gameplay::drawRoundHud() 
	{
		DrawText(TextFormat("Round %i", getRound()), uiSmallSize, static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
	}

	void Gameplay::drawPlayerMoney() 
	{
		DrawText(TextFormat("$ %i", playerOne->getMoney()), GetScreenWidth() - (uiBigSize * 4), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), uiSmallSize, uiColor);
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

	void Gameplay::drawMuteButton()
	{
		DrawCircleV(getMuteButtonPosition(), getMuteButtonRadius(), muteButtonColor);
	}

	void Gameplay::pauseGameInput(SceneManager* sceneManager)
	{
		if (CheckCollisionPointCircle(GetMousePosition(), getPauseButtonPosition(), getPauseButtonRadius())
			&& IsMouseButtonPressed(inputButton))
		{
			sceneManager->setCurrentScene(pauseMenuScene);
		}
	}

	void Gameplay::muteGameInput() 
	{
		if (CheckCollisionPointCircle(GetMousePosition(), getMuteButtonPosition(), getMuteButtonRadius()) 
			&& IsMouseButtonPressed(inputButton))
		{
			
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

	void Gameplay::resetGameplayForWiningRound() 
	{
		setTimerToSpawnZombie(getRoundStartingTimerToSpawnZombie());
		setTimerToEndRound(getRoundStartingTimerToEndRound());
				
		destroyZombies();

		playerOne->resetSurvivorForWiningRound({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
	}

	void Gameplay::initialGameplayStats() 
	{
		destroyZombies();

		playerOne->setPosition({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });		

		setTimerToSpawnZombie(initialtimeToSpawnZombie);
		setTimerToEndRound(initialTimeToEndRound);
		setZombieVelocity(zombieInitialVelocity);
		setZombieDamageToDie(zombieInitialDamageToDie);
		setRound(initialRound);
		setMoneyForKillingZombie(initialMoneyForKillingZombie);
		setRoundStartingTimerToSpawnZombie(initialtimeToSpawnZombie);
		setRoundStartingTimerToEndRound(initialTimeToEndRound);		
	}
}