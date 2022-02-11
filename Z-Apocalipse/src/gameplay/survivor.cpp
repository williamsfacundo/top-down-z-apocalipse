#include "survivor.h"

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
		setVelocity(50.5f);
		setAceleration(0.0f);
		setDirectionNumberMultiplyer(1);		
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

	void Survivor::input() 
	{
		movementInput();
	}
	
	void Survivor::update() 
	{
		movementUpdate();
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
}
