#include "gameplay.h"

#include <iostream>
#include <cmath>

#include <raylib.h>

#include "survivor.h"
#include "zombie.h"
#include "scene_manager.h"
#include "end_game.h"
#include "upgrader.h"
#include "..\math\math.h"

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

	void Gameplay::setZombieInitialVelocity() 
	{
		zombieInitialVelocity = vectorMath::getScreenHypotenuse() / zombieInitialVelocityDivider;
	}

	void Gameplay::setZombieVelocity(float zombieVelocity)
	{
		this->zombieVelocity = zombieVelocity;
	}

	void Gameplay::setZombieDamageToDie(float zombieDamageToDie)
	{
		this->zombieDamageToDie = zombieDamageToDie;
	}

	void Gameplay::setTimerToCreateNewAmmo(float timerToCreateNewAmmo) 
	{
		this->timerToCreateNewAmmo = timerToCreateNewAmmo;
	}

	void Gameplay::setRound(short round)
	{
		this->round = round;
	}		

	void Gameplay::nextRound() 
	{
		round += 1;
	}

	void Gameplay::setMaxZombiesInRound(short maxZombiesInRound) 
	{
		if (this->maxZombiesInRound <= maxZombies)
		{
			this->maxZombiesInRound = maxZombiesInRound;
		}
	}

	void Gameplay::setMoneyForKillingZombie(short moneyForKillingZombie) 
	{
		this->moneyForKillingZombie = moneyForKillingZombie;
	}

	void Gameplay::setUiSmallSize()
	{
		uiSmallSize = vectorMath::getScreenHypotenuse() / uiSmallSizeDivider;
	}

	void Gameplay::setUiBigSize()
	{
		uiBigSize = vectorMath::getScreenHypotenuse() / uiBigSizeDivider;
	}

	void Gameplay::setPauseTextSize()
	{
		pauseTextSize = vectorMath::getScreenHypotenuse() / pauseTextSizeDivider;
	}

	void Gameplay::setMuteTextSize()
	{
		muteTextSize = vectorMath::getScreenHypotenuse() / muteTextSizeDivider;
	}

	void Gameplay::setZombiesKilled(int zombiesKilled) 
	{
		this->zombiesKilled = zombiesKilled;
	}	

	void Gameplay::setTimeSurvived(float timeSurvived) 
	{
		this->timeSurvived = timeSurvived;
	}

	void Gameplay::setZombiesToNull() 
	{
		for (short i = 0; i < maxZombies; i++)
		{
			zombies[i] = NULL;
		}
	}

	void Gameplay::setAmmunitionsToNull() 
	{
		for (short i = 0; i < maxAmmunitions; i++) 
		{
			ammunitions[i] = NULL;
		}
	}

	void Gameplay::addTimeToSpawnZombie(float value) 
	{
		if (timerToSpawnZombie + value > 0)
		{
			timerToSpawnZombie += value;
		}		
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
		if (maxZombiesInRound + 1 <= maxZombies)
		{ 
			this->maxZombiesInRound += value; 
		}
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

	void Gameplay::addTimeSurvived(float value) 
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

	float Gameplay::getZombieInitialVelocity() 
	{
		return zombieInitialVelocity;
	}

	float Gameplay::getZombieVelocity() 
	{
		return zombieVelocity;
	}

	float Gameplay::getZombieDamageToDie() 
	{
		return zombieDamageToDie;
	}

	float Gameplay::getTimerToCreateNewAmmo() 
	{
		return timerToCreateNewAmmo;
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

	int Gameplay::getUiSmallSize() 
	{
		return uiSmallSize;
	}

	int Gameplay::getUiBigSize() 
	{
		return uiBigSize;
	}
	
	int Gameplay::getPauseTextSize() 
	{
		return pauseTextSize;
	}
	
	int Gameplay::getMuteTextSize() 
	{
		return muteTextSize;
	}

	int Gameplay::getZombiesKilled() 
	{
		return zombiesKilled;
	}

	float Gameplay::getTimeSurvived()
	{
		return timeSurvived;
	}

	Survivor* Gameplay::getPlayer()
	{
		return playerOne;
	}

	Vector2 Gameplay::getRandomAmmoPosition(float radius, short ammoIndex)
	{
		Vector2 position = { static_cast<float>(GetRandomValue(static_cast<int>(gameplaySpacePos.x + radius), static_cast<int>(gameplaySpacePos.x + GetScreenWidth() - radius))),
			static_cast<float>(GetRandomValue(static_cast<int>(gameplaySpacePos.y + radius), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight - radius))) };	

		for (short i = 0; i < maxAmmoPositionValidations; i++)
		{
			for (short v = 0; v < maxAmmunitions; v++)
			{
				if (ammunitions[v] != NULL && i != ammoIndex)
				{
					if (CheckCollisionCircles(position, radius, ammunitions[v]->getPosition(), ammunitions[v]->getRadius()))
					{
						v = maxAmmunitions;

						Vector2 position = { static_cast<float>(GetRandomValue(static_cast<int>(gameplaySpacePos.x + radius), static_cast<int>(gameplaySpacePos.x + GetScreenWidth() - radius))),
							static_cast<float>(GetRandomValue(static_cast<int>(gameplaySpacePos.y + radius), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight - radius))) };
					}
					else if (v == maxAmmunitions - 1)
					{
						i = maxAmmoPositionValidations;
					}					
				}		
			}
		}		

		return position;
	}

	void Gameplay::init()
	{		
		playerOne = new Survivor(playerOneColor, { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, (getGameplaySize() / charactersSizeDivider) / 2.0f,
			{ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
		
		setUiSmallSize();

		setUiBigSize();
		
		setPauseTextSize();
		
		setMuteTextSize();

		setZombiesToNull();
		setAmmunitionsToNull();

		setZombiesSpawnsPositions();

		setZombieInitialVelocity();

		setPauseButtonRadius((GetScreenHeight() * (hudHeightPercentage / 3.0f)) / 2.0f);

		setPauseButtonPosition({ static_cast<float>(GetScreenWidth() * pauseButtonWidthPercentage), getPauseButtonRadius() * pauseButtonHeightPercentage });

		setMuteButtonRadius(getPauseButtonRadius());

		setMuteButtonPosition({ static_cast<float>(GetScreenWidth() * muteButtonWidthPercentage), getPauseButtonRadius() * muteButtonHeightPercentage });

		initialGameplayStats();

		setZombiesKilled(0);

		setTimeSurvived(0.0f);
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
		
		playerPickUpAmmo();
		
		decreasTimerToEndRound();

		addTimeSurvived(GetFrameTime());

		decreasTimerToCreatNewAmmo();
		
		creatNewAmmo();

		winRound(sceneManager, upgrader);
		
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

		destroyZombies();

		deleteAmmunitions();
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
				zombies[i]->update(playerOne->getPosition(), isZombieCollidingWithPlayer(i));
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
					if (isZombieCollidingWithPlayer(i))
					{
						playerOne->hitByZombie();

						i = maxZombiesInRound;
					}
				}
			}
		}		
	}

	bool Gameplay::isZombieCollidingWithPlayer(short index) 
	{
		return CheckCollisionCircles(zombies[index]->getPosition(), zombies[index]->getRadius(),
			playerOne->getPosition(), playerOne->getRadius());
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

	void Gameplay::playerPickUpAmmo() 
	{
		for (short i = 0; i < maxAmmunitions; i++) 
		{
			if (ammunitions[i] != NULL) 
			{
				if (ammunitions[i]->isCollidingWithCircle(playerOne->getPosition(), playerOne->getRadius()) && 
					playerOne->getRemainingBullets() != playerOne->getStartingRoundRemainingBullets())
				{
					playerOne->addRemainingBullets(ammunitions[i]->getBulletsForPickUp());

					delete ammunitions[i];
					ammunitions[i] = NULL;					
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

	short Gameplay::findEmptyAmmoIndex()
	{
		for (short i = 0; i < maxAmmunitions; i++)
		{
			if (ammunitions[i] == NULL)
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

			if (timerToEndRound <= 0.0f)
			{				
				timerToEndRound = 0.0f;				
			}
		}		
	}

	void Gameplay::decreasTimerToCreatNewAmmo() 
	{
		if (timerToCreateNewAmmo > 0.0f)
		{
			timerToCreateNewAmmo -= GetFrameTime();

			if (timerToCreateNewAmmo < 0.0f)
			{
				timerToCreateNewAmmo = 0.0f;				
			}
		}
	}

	void Gameplay::winRound(SceneManager* sceneManager, Upgrader* upgrader)
	{	
		if (getTimerToEndRound() == 0.0f ) 
		{
			nextRound();
			playerOne->setInitialRoundMoney(playerOne->getMoney());
			increaseStatsForNextRound();
			resetGameplayForWiningRound();

			if (!upgrader->allLevelsMaxed()) 
			{
				sceneManager->setCurrentScene(upgraderScene); 
			}		
		}		
	}

	void Gameplay::defeatCondition(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader)
	{		
		if (playerOne->getLives() <= 0) 
		{			
			restartGameplay(sceneManager, endGame, upgrader, endGameScene);
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
		//drawMuteButton();
	}

	void Gameplay::drawTimer() 
	{					
		DrawText(TextFormat("%i", static_cast<int>(timerToEndRound)), GetScreenWidth() / 2 - getUiSmallSize(), static_cast<int>((gameplaySpacePos.y / 2) - (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
	}	

	void Gameplay::drawLivesRemaining() 
	{
		DrawText(TextFormat("Lives: %i", playerOne->getLives()), getUiSmallSize(), static_cast<int>((gameplaySpacePos.y / 2) - (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
	}

	void Gameplay::drawInbulnerabilityTimer() 
	{
		if (playerOne->getInvulnerabilityTimer() > 0.0f)
		{
			DrawText(TextFormat("(INVULNERABILITY)"), getUiSmallSize() * 5, static_cast<int>((gameplaySpacePos.y / 2) - (GetScreenWidth() * (hudHeightPercentage / 16))), static_cast<int>(getUiSmallSize() * 0.55f), uiColor);
		}
	}

	void Gameplay::drawPlayerBulletsUI() 
	{
		DrawText(TextFormat("%i", playerOne->getBulletsInCharger()), static_cast<int>(GetScreenWidth() / 1.6f) - (getUiBigSize() * 4), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
		DrawText("/", static_cast<int>(GetScreenWidth() / 1.6f) - (getUiBigSize() * 3), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
		DrawText(TextFormat("%i", playerOne->getRemainingBullets()), static_cast<int>(GetScreenWidth() / 1.6f) - (getUiBigSize() * 2), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
	}

	void Gameplay::drawReloadingText() 
	{
		if(playerOne->getReloadTimer() > 0.0f)
		{
			DrawText("(RELOADING)", static_cast<int>(GetScreenWidth() / 1.6f) - (getUiBigSize() * 4),
				static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + getUiSmallSize() + (GetScreenWidth() * (hudHeightPercentage / 16))),
				static_cast<int>(getUiSmallSize() * 0.55f), uiColor);
		}		
	}

	void Gameplay::drawRoundHud() 
	{
		DrawText(TextFormat("Round %i", getRound()), getUiSmallSize(), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
	}

	void Gameplay::drawPlayerMoney() 
	{
		DrawText(TextFormat("$ %i", playerOne->getMoney()), GetScreenWidth() - (getUiBigSize() * 4), static_cast<int>(gameplaySpacePos.y + gameplaySpaceHeight + (GetScreenWidth() * (hudHeightPercentage / 16))), getUiSmallSize(), uiColor);
	}

	void Gameplay::drawGameplay() 
	{		
		drawGameplayRectangle();
		drawAmmo();
		drawZombies();
		playerOne->draw();		
	}

	void Gameplay::drawPauseButton() 
	{
		DrawCircleV(getPauseButtonPosition(), getPauseButtonRadius(), pauseButtonColor);
		
		DrawText(pauseText, static_cast<int>(getPauseButtonPosition().x - (getPauseButtonRadius() / 3.0f)), 
			static_cast<int>(getPauseButtonPosition().y - (getPauseButtonRadius() / 3.0f)), getPauseTextSize(), pauseTextColor);
	}

	void Gameplay::drawMuteButton()
	{
		DrawCircleV(getMuteButtonPosition(), getMuteButtonRadius(), muteButtonColor);

		DrawText(muteText, static_cast<int>(getMuteButtonPosition().x - (getMuteButtonRadius() / 3.0f)),
			static_cast<int>(getMuteButtonPosition().y - (getMuteButtonRadius() / 3.0f)), getMuteTextSize(), muteTextColor);
	}

	void Gameplay::drawAmmo() 
	{
		for (short i = 0; i < maxAmmunitions; i++)
		{
			if (ammunitions[i] != NULL)
			{
				ammunitions[i]->draw();
			}
		}
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
		deleteAmmunitions();

		setTimerToSpawnZombie(getRoundStartingTimerToSpawnZombie());
		setTimerToEndRound(getRoundStartingTimerToEndRound());
		setTimerToCreateNewAmmo(initialTimeToCreatNewAmmo);

		destroyZombies();

		playerOne->resetSurvivorForWiningRound({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
	}

	void Gameplay::initialGameplayStats() 
	{
		destroyZombies();
		deleteAmmunitions();

		playerOne->setPosition({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });		

		setTimerToSpawnZombie(initialtimeToSpawnZombie);
		setTimerToEndRound(initialTimeToEndRound);
		setZombieVelocity(getZombieInitialVelocity());
		setZombieDamageToDie(zombieInitialDamageToDie);
		setTimerToCreateNewAmmo(initialTimeToCreatNewAmmo);
		setRound(initialRound);
		setMaxZombiesInRound(initialMaxZombiesInRound);
		setMoneyForKillingZombie(initialMoneyForKillingZombie);
		setRoundStartingTimerToSpawnZombie(initialtimeToSpawnZombie);
		setRoundStartingTimerToEndRound(initialTimeToEndRound);		
	}

	void Gameplay::deleteAmmunitions() 
	{
		for (short i = 0; i < maxAmmunitions; i++) 
		{
			if (ammunitions[i] != NULL) 
			{
				delete ammunitions[i];
				ammunitions[i] = NULL;
			}
		}
	}

	void Gameplay::creatNewAmmo() 
	{
		short index = 0;
		float radius = (getGameplaySize() / ammoSizeDivider) / 2.0f;

		if (getTimerToCreateNewAmmo() <= 0.0f && Ammunition::getAmountOfAmmunitions() < maxAmmunitions) 
		{
			setTimerToCreateNewAmmo(initialTimeToCreatNewAmmo);

			index = findEmptyAmmoIndex();

			ammunitions[index] = new Ammunition( getRandomAmmoPosition(radius, index), radius);
		}
	}

	void Gameplay::restartGameplay(SceneManager* sceneManager, EndGame* endGame, Upgrader* upgrader, Scenes changeScene)
	{		
		std::cout << getTimeSurvived() << std::endl;
		endGame->calculateScore(getZombiesKilled(), static_cast<int>(getTimeSurvived()));

		initialGameplayStats();

		playerOne->startingSurvivorStats();

		upgrader->resetLevels();

		sceneManager->setCurrentScene(changeScene);
		
		setZombiesKilled(0);
		setTimeSurvived(0.0f);
	}
}