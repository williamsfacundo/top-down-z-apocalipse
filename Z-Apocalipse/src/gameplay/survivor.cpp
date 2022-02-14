#include "survivor.h"

#include <iostream>
#include <cmath>
#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Survivor::Survivor(Color color, Vector2 position, float radius) : Character(color, position, radius)
	{
		setLives(initialLives);
		setMoney(initialMoney);
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

		for (short i = 0; i < maxBullets; i++)
		{
			bullets[i] = NULL;
		}
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

	void Survivor::setLives(short lives) 
	{
		this->lives = lives;
	}

	void Survivor::setMoney(short money) 
	{
		this->money = money;
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

	short Survivor::getLives() 
	{
		return lives;
	}
	
	short Survivor::getMoney() 
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
			if(bullets[i] == NULL)
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

	void Survivor::input() 
	{
		movementInput();
		inputShooting();
	}
	
	void Survivor::inputShooting() 
	{		
		if (IsMouseButtonPressed(getShootButton()) && Bullet::getBulletsCreated() < maxBullets && getShootingTimer() == 0.0f) 
		{
			shootingTimer = startingShootingTimer;

			bullets[getEmptyBulletIndex()] = new Bullet(getPosition(), getBulletDirection(), BulletsType::GUN);
		}
	}

	void Survivor::update() 
	{
		movementUpdate();
		updateBullets();
				
		decreaseShootingTimer();
		system("cls");
		std::cout << "Shooting timer: " << shootingTimer << ".";
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
		DrawCircleV(getPosition(), getRadius(), getCharacterColor());

		for (short i = 0; i < maxBullets; i++) 
		{
			if (bullets[i] != NULL) 
			{
				bullets[i]->draw();
			}
		}
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
}
