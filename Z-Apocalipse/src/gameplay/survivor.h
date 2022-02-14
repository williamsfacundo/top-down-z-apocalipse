#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "character.h"
#include "bullet.h"

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
		const MouseButton initialShootButton = MOUSE_BUTTON_LEFT;
		const short acelerationMultiplyer = 40.0f;
		const short maxAceleration = 200.0f;
		const short secondsForAcelerationDecrease = 3;
		static const short maxBullets = 3;
		const float startingShootingTimer = 1.15f;

		short lives;
		short money;
		short directionNumberMultiplyer;
		MovementStatus movementStatus;
		MovementStatus direction;
		KeyboardKey moveUpKey;
		KeyboardKey moveDownKey;
		KeyboardKey moveRightKey;
		KeyboardKey moveLeftKey;
		MouseButton shootButton;
		float velocity;
		float aceleration;
		float shootingTimer;

		Bullet* bullets[maxBullets];
	public:
		Survivor(Color color, Vector2 position, float radius);
		~Survivor();

		void setLives(short lives);
		void setMoney(short money);
		void setMovementStatus(MovementStatus movementStatus);
		void setDirection(MovementStatus direction);
		void setMoveUpKey(KeyboardKey key);
		void setMoveDownKey(KeyboardKey key);
		void setMoveRightKey(KeyboardKey key);
		void setMoveLeftKey(KeyboardKey key);
		void setShootButton(MouseButton shootButton);
		void setVelocity(float velocity);
		void setAceleration(float aceleration);
		void setDirectionNumberMultiplyer(float directionNumberMultiplyer);		
		void setShootingTimer(float shootingTimer);

		short getLives();
		short getMoney();
		MovementStatus getMovementStatus();
		MovementStatus getDirection();
		KeyboardKey getMoveUpKey();
		KeyboardKey getMoveDownKey();
		KeyboardKey getMoveRightKey();
		KeyboardKey getMoveLeftKey();
		MouseButton getShootButton();
		float getVelocity();
		float getAceleration();
		float getDirectionNumberMultiplyer();
		short getEmptyBulletIndex();
		Vector2 getBulletDirection();
		float getShootingTimer();

		void input();
		void inputShooting();
		virtual void update(Rectangle gameplayDimensions);
		virtual void movementUpdate();
		void updateBullets();
		virtual void draw();
		void movementInput();
		void addAceleration();
		void decreasAceleration();
		void moveDependingCoordinate(bool xCoordinate);
		void decreaseShootingTimer();
		void destroyBulletsOutsideMap(Rectangle map);
		bool isBulletOutsideMap(short index, Rectangle map);
	};
}

#endif
