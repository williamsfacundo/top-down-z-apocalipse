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
		const float initialDamage = 10.0f;
		const float invulnerabilityTime = 1.8f;

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
		float damage;
		float invulnerabilityTimer;

		Bullet* bullets[maxBullets];
		Rectangle gameplayMap;
	public:
		Survivor(Color color, Vector2 position, float radius, Rectangle gameplayMap);
		~Survivor();

		void setLives(short lives);
		void subtractLive();
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
		void setDamage(float damage);
		void setInvulnerabilityTimer(float invulnerabilityTimer);

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
		short getMaxBullets();
		float getDamage();
		float getInvulnerabilityTimer();

		void input();
		void inputShooting();
		void update(Rectangle gameplayDimensions);
		void movementUpdate();
		void updateBullets();
		virtual void draw();
		void movementInput();
		void addAceleration();
		void decreasAceleration();
		void moveDependingCoordinate(bool xCoordinate);
		void decreaseShootingTimer();
		void destroyBulletsOutsideMap(Rectangle map);
		bool isBulletOutsideMap(short index, Rectangle map);
		bool isBulletNull(short index);
		Bullet* getBullet(short index);
		void destroyBullet(short index);
		void hitByZombie();
		void decreaseInvulnerabilityTimer();
		bool isSurvivorInvulnerable();
	};
}

#endif
