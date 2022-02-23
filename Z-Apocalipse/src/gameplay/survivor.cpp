#include "survivor.h"

#include <iostream>
#include <cmath>
#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Survivor::Survivor(Color color, Vector2 position, float radius, Rectangle gameplayMap) : Character(color, position, radius, gameplayMap)
	{
		setLives(initialLives);
		setMoney(initialMoney);
		setInitialRoundMoney(initialMoney);
		setMovementStatus(MovementStatus::NONE);
		setDirection(MovementStatus::UP);
		setMoveUpKey(initialMoveUpKey);
		setMoveDownKey(initialMoveDownKey);
		setMoveRightKey(initialMoveRightKey);
		setMoveLeftKey(initialMoveLeftKey);
		setShootButton(initialShootButton);
		setVelocity(50.5f);
		setAceleration(0.0f);
		setDirectionNumberMultiplyer(1);	
		setShootingTimer(startingShootingTimer);
		setDamage(initialDamage);
		setInvulnerabilityTimer(0.0f);
		setMaxBulletsInCharger(initialBulletsInCharger);
		setBulletsInCharger(maxBulletsInCharger);
		setRemainingBullets(initialMaxBullets - maxBulletsInCharger);
		setReloadKey(initialReloadKey);		
		setBulletsToNull();
		setReloadTimer(0.0f);		
	}

	Survivor::~Survivor() 
	{
		for (short i = 0; i < maxBullets; i++) 
		{
			if(bullets[i] != NULL)
			{
				delete bullets[i];				
			}
		}
	}

#pragma region SETTERS

	void Survivor::setLives(short lives)
	{
		this->lives = lives;
	}

	void Survivor::subtractLive()
	{
		lives -= 1;
	}

	void Survivor::setMoney(int money)
	{
		this->money = money;
	}

	void Survivor::addMoney(float money) 
	{
		this->money += money;
	}

	void Survivor::setInitialRoundMoney(float initialRoundMoney) 
	{
		this->initialRoundMoney = initialRoundMoney;
	}	

	void Survivor::setMovementStatus(MovementStatus movementStatus)
	{
		this->movementStatus = movementStatus;
	}

	void Survivor::setDirection(MovementStatus direction)
	{
		this->direction = direction;
	}

	void Survivor::setMoveUpKey(KeyboardKey key)
	{
		this->moveUpKey = key;
	}

	void Survivor::setMoveDownKey(KeyboardKey key)
	{
		this->moveDownKey = key;
	}

	void Survivor::setMoveRightKey(KeyboardKey key)
	{
		this->moveRightKey = key;
	}

	void Survivor::setMoveLeftKey(KeyboardKey key)
	{
		this->moveLeftKey = key;
	}

	void Survivor::setReloadKey(KeyboardKey key)
	{
		this->reloadKey = key;
	}

	void Survivor::setShootButton(MouseButton shootButton)
	{
		this->shootButton = shootButton;
	}

	void Survivor::setVelocity(float velocity)
	{
		this->velocity = velocity;
	}

	void Survivor::setAceleration(float aceleration)
	{
		this->aceleration = aceleration;
	}

	void Survivor::setDirectionNumberMultiplyer(float directionNumberMultiplyer)
	{
		this->directionNumberMultiplyer = directionNumberMultiplyer;
	}

	void Survivor::setShootingTimer(float shootingTimer)
	{
		this->shootingTimer = shootingTimer;
	}

	void Survivor::setDamage(float damage)
	{
		this->damage = damage;
	}

	void Survivor::setInvulnerabilityTimer(float invulnerabilityTimer)
	{
		this->invulnerabilityTimer = invulnerabilityTimer;
	}

	void Survivor::setReloadTimer(float reloadTimer) 
	{
		this->reloadTimer = reloadTimer;
	}	

	void Survivor::setMaxBulletsInCharger(short maxBulletsInCharger)
	{
		this->maxBulletsInCharger = maxBulletsInCharger;
	}

	void Survivor::setBulletsInCharger(short bulletsInCharger)
	{
		this->bulletsInCharger = bulletsInCharger;
	}

	void Survivor::setRemainingBullets(short remainingBullets)
	{
		this->remainingBullets = remainingBullets;
	}	

	void Survivor::setBulletsToNull()
	{
		for (short i = 0; i < maxBullets; i++)
		{
			bullets[i] = NULL;
		}
	}	

#pragma endregion

#pragma region GETTERS

	short Survivor::getLives()
	{
		return lives;
	}

	int Survivor::getMoney()
	{
		return money;
	}

	MovementStatus Survivor::getMovementStatus()
	{
		return movementStatus;
	}

	MovementStatus Survivor::getDirection()
	{
		return direction;
	}

	KeyboardKey Survivor::getMoveUpKey()
	{
		return moveUpKey;
	}

	KeyboardKey Survivor::getMoveDownKey()
	{
		return moveDownKey;
	}

	KeyboardKey Survivor::getMoveRightKey()
	{
		return moveRightKey;
	}

	KeyboardKey Survivor::getMoveLeftKey()
	{
		return moveLeftKey;
	}

	KeyboardKey Survivor::getReloadKey()
	{
		return reloadKey;
	}

	MouseButton Survivor::getShootButton()
	{
		return shootButton;
	}

	float Survivor::getVelocity()
	{
		return velocity;
	}

	float Survivor::getAceleration()
	{
		return aceleration;
	}

	float Survivor::getDirectionNumberMultiplyer()
	{
		return directionNumberMultiplyer;
	}

	short Survivor::getEmptyBulletIndex()
	{
		short index = maxBullets + 1;

		for (short i = 0; i < maxBullets; i++)
		{
			if (bullets[i] == NULL)
			{
				index = i;
			}
		}

		return index;
	}

	Vector2 Survivor::getBulletDirection()
	{
		float distanceX = GetMousePosition().x - getPosition().x;
		float distanceY = GetMousePosition().y - getPosition().y;
		double module = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
		distanceX /= static_cast<float>(module);
		distanceY /= static_cast<float>(module);
		Vector2 direction = { distanceX, distanceY };

		return direction;
	}

	float Survivor::getShootingTimer()
	{
		return shootingTimer;
	}

	short Survivor::getMaxBullets()
	{
		return maxBullets;
	}

	float Survivor::getDamage()
	{
		return damage;
	}

	float Survivor::getInvulnerabilityTimer()
	{
		return invulnerabilityTimer;
	}

	float Survivor::getReloadTimer() 
	{
		return reloadTimer;
	}
	
	short Survivor::getMaxBulletsInCharger()
	{
		return maxBulletsInCharger;
	}

	short Survivor::getBulletsInCharger()
	{
		return bulletsInCharger;
	}

	short Survivor::getRemainingBullets()
	{
		return remainingBullets;
	}

	short Survivor::getInitialLives() 
	{
		return initialLives;
	}

#pragma endregion
	
	void Survivor::input(bool mouseOnGameplay)
	{
		movementInput();
		shootingInput(mouseOnGameplay);
		reloadInput();
	}
	
	void Survivor::shootingInput(bool mouseOnGameplay)
	{		
		if (IsMouseButtonPressed(getShootButton()) && bulletsInCharger > 0 && getShootingTimer() == 0.0f && getReloadTimer() == 0.0f && mouseOnGameplay) 
		{
			shootingTimer = startingShootingTimer;

			bullets[getEmptyBulletIndex()] = new Bullet(getPosition(), getBulletDirection(), BulletsType::GUN, (getRadius() / bulletsSizeDivider) / 2.0f);
			bulletsInCharger -= 1;
		}
	}

	void Survivor::update(Rectangle gameplayDimensions)
	{
		movementUpdate();
		updateBullets();
				
		decreaseShootingTimer();
		destroyBulletsOutsideMap(gameplayDimensions);
		decreaseInvulnerabilityTimer();
		decreaseReloadTimer();
	}

	void Survivor::movementUpdate()
	{
		switch (getMovementStatus())
		{
		case MovementStatus::UP:
			
			moveDependingCoordinate(false);
			addAceleration();
			break;
		case MovementStatus::DOWN:
			
			moveDependingCoordinate(false);
			addAceleration();
			break;
		case MovementStatus::RIGHT:
			
			moveDependingCoordinate(true);
			addAceleration();
			break;
		case MovementStatus::LEFT:
			
			moveDependingCoordinate(true);
			addAceleration();
			break;
		case MovementStatus::NONE:

			decreasAceleration();
			break;
		default:
			break;
		}
	}

	void Survivor::updateBullets() 
	{
		for (short i = 0; i < maxBullets; i++) 
		{
			if (bullets[i] != NULL) 
			{
				bullets[i]->update();
			}
		}
	}

	void Survivor::draw() 
	{
		drawSurvivor();
		drawBullets();
	}

	void Survivor::movementInput() 
	{
		if (IsKeyDown(getMoveUpKey())) 
		{
			setMovementStatus(MovementStatus::UP);
			direction = MovementStatus::UP;
			setDirectionNumberMultiplyer(-1);
		}
		else if (IsKeyDown(getMoveDownKey()))
		{
			setMovementStatus(MovementStatus::DOWN);
			direction = MovementStatus::DOWN;
			setDirectionNumberMultiplyer(1);
		}
		else if (IsKeyDown(getMoveRightKey()))
		{
			setMovementStatus(MovementStatus::RIGHT);
			direction = MovementStatus::RIGHT;
			setDirectionNumberMultiplyer(1);
		}
		else if (IsKeyDown(getMoveLeftKey()))
		{
			setMovementStatus(MovementStatus::LEFT);
			direction = MovementStatus::LEFT;
			setDirectionNumberMultiplyer(-1);
		}
		else 
		{
			setMovementStatus(MovementStatus::NONE);
		}
	}

	void Survivor::addAceleration() 
	{
		if (aceleration < maxAceleration)
		{
			aceleration += GetFrameTime() * acelerationMultiplyer;
		}
	}

	void Survivor::decreasAceleration() 
	{
		if (aceleration > 0.0f)
		{
			switch (direction)
			{
			case MovementStatus::UP:

				moveDependingCoordinate(false);
				break;
			case MovementStatus::DOWN:

				moveDependingCoordinate(false);
				break;
			case MovementStatus::RIGHT:

				moveDependingCoordinate(true);
				break;
			case MovementStatus::LEFT:

				moveDependingCoordinate(true);
				break;
			default:
				break;
			}

			aceleration -= GetFrameTime() * (acelerationMultiplyer * secondsForAcelerationDecrease);

			if (aceleration < 0.0f)
			{
				aceleration = 0.0f;
			}
		}
	}

	void Survivor::moveDependingCoordinate(bool xCoordinate)
	{
		if (xCoordinate) 
		{
			move({ (directionNumberMultiplyer * (velocity + aceleration)) * GetFrameTime(), 0.0f });
		}
		else 
		{
			move({ 0.0f, (directionNumberMultiplyer * (velocity + aceleration)) * GetFrameTime() });
		}
	}

	void Survivor::decreaseShootingTimer() 
	{
		if (shootingTimer > 0.0f) 
		{
			shootingTimer -= GetFrameTime();

			if (shootingTimer < 0.0f) 
			{
				shootingTimer = 0.0f;
			}
		}
	}

	void Survivor::destroyBulletsOutsideMap(Rectangle map)
	{
		for (short i = 0; i < maxBullets; i++) 
		{
			if (isBulletOutsideMap(i, map)) 
			{
				destroyBullet(i);
			}
		}
	}

	bool Survivor::isBulletOutsideMap(short index, Rectangle map) 
	{
		if(bullets[index] != NULL)
		{
			if (CheckCollisionCircleRec(bullets[index]->getPosition(), bullets[index]->getRadius(), map))
			{
				return false;
			}
			else 
			{
				return true;
			}
		}
		else 
		{
			return false;
		}
	}

	bool Survivor::isBulletNull(short index) 
	{
		return bullets[index] == NULL;
	}

	Bullet* Survivor::getBullet(short index) 
	{
		return bullets[index];
	}

	void Survivor::destroyBullet(short index) 
	{
		if(!isBulletNull(index))
		{
			delete bullets[index];
			bullets[index] = NULL;
		}
	}

	void Survivor::hitByZombie() 
	{
		setInvulnerabilityTimer(invulnerabilityTime);
		subtractLive();
	}

	void Survivor::decreaseInvulnerabilityTimer() 
	{
		if (getInvulnerabilityTimer() > 0.0f)
		{
			invulnerabilityTimer -= GetFrameTime();

			if (getInvulnerabilityTimer() < 0.0f)
			{
				setInvulnerabilityTimer(0.0f);
			}
		}
	}

	void Survivor::decreaseReloadTimer() 
	{
		if (getReloadTimer() > 0.0f)
		{
			reloadTimer -= GetFrameTime();

			if (getReloadTimer() < 0.0f)
			{
				setReloadTimer(0.0f);
			}
		}
	}

	bool Survivor::isSurvivorInvulnerable() 
	{
		return invulnerabilityTimer > 0.0f;
	}

	void Survivor::reloadInput() 
	{
		if (IsKeyPressed(reloadKey)) 
		{
			reload();
		}
	}

	void Survivor::reload() 
	{
		short missingBullets = maxBulletsInCharger - bulletsInCharger;

		if (missingBullets != 0) 
		{
			setReloadTimer(reloadTime);

			if (remainingBullets >= missingBullets)
			{
				bulletsInCharger += missingBullets;
				remainingBullets -= missingBullets;
			}
			else if (remainingBullets > 0)
			{
				bulletsInCharger += remainingBullets;
				remainingBullets = 0;
			}
		}		
	}

	void Survivor::drawSurvivor() 
	{
		DrawCircleV(getPosition(), getRadius(), getCharacterColor());		
	}

	void Survivor::drawBullets() 
	{
		for (short i = 0; i < maxBullets; i++)
		{
			if (bullets[i] != NULL)
			{
				bullets[i]->draw();
			}
		}
	}

	void Survivor::destroyBullets() 
	{
		for (short i = 0; i < maxBullets; i++) 
		{
			if (bullets[i] != NULL) 
			{
				delete bullets[i];
				bullets[i] = NULL;
			}
		}
	}

	void Survivor::resetSurvivor(Vector2 position) 
	{
		setMoney(initialRoundMoney);
		setMovementStatus(MovementStatus::NONE);
		setDirection(MovementStatus::UP);
		setBulletsInCharger(maxBulletsInCharger);
		setRemainingBullets(initialMaxBullets - maxBulletsInCharger);
		setPosition(position);
		setAceleration(0.0f);
		setReloadTimer(0.0f);
		setInvulnerabilityTimer(0.0f);
		setShootingTimer(0.0f);
		destroyBullets();
		setLives(getInitialLives());
	}
}
