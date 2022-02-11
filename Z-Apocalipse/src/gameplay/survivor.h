#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "character.h"

namespace Z_APOCALIPSE 
{
	enum class MovementStatus {UP, DOWN, RIGHT, LEFT, NONE};

	class Survivor : public Character
	{
	private:
		const short initialLives = 3;
		const short initialMoney = 200;		
		const KeyboardKey initialMoveUpKey = KEY_W;
		const KeyboardKey initialMoveDownKey = KEY_S;
		const KeyboardKey initialMoveRightKey = KEY_D;
		const KeyboardKey initialMoveLeftKey = KEY_A;
		const short acelerationMultiplyer = 40.0f;
		const short maxAceleration = 200.0f;
		const short secondsForAcelerationDecrease = 3;

		short lives;
		short money;
		MovementStatus movementStatus;
		MovementStatus direction;
		KeyboardKey moveUpKey;
		KeyboardKey moveDownKey;
		KeyboardKey moveRightKey;
		KeyboardKey moveLeftKey;
		float velocity;
		float aceleration;
		short directionNumberMultiplyer;
	public:
		Survivor(Color color, Vector2 position, float radius);

		void setLives(short lives);
		void setMoney(short money);
		void setMovementStatus(MovementStatus movementStatus);
		void setDirection(MovementStatus direction);
		void setMoveUpKey(KeyboardKey key);
		void setMoveDownKey(KeyboardKey key);
		void setMoveRightKey(KeyboardKey key);
		void setMoveLeftKey(KeyboardKey key);
		void setVelocity(float velocity);
		void setAceleration(float aceleration);
		void setDirectionNumberMultiplyer(float directionNumberMultiplyer);		
	
		short getLives();
		short getMoney();
		MovementStatus getMovementStatus();
		MovementStatus getDirection();
		KeyboardKey getMoveUpKey();
		KeyboardKey getMoveDownKey();
		KeyboardKey getMoveRightKey();
		KeyboardKey getMoveLeftKey();
		float getVelocity();
		float getAceleration();
		float getDirectionNumberMultiplyer();

		void input();
		virtual void update();
		virtual void movementUpdate();
		void movementInput();
		void addAceleration();
		void decreasAceleration();
		void moveDependingCoordinate(bool xCoordinate);
	};
}

#endif
