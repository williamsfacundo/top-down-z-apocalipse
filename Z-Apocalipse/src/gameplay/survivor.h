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
		const KeyboardKey initialMoveUpKey = KEY_W;
		const KeyboardKey initialMoveDownKey = KEY_S;
		const KeyboardKey initialMoveRightKey = KEY_D;
		const KeyboardKey initialMoveLeftKey = KEY_A;
		const KeyboardKey initialReloadKey = KEY_R;
		const MouseButton initialShootButton = MOUSE_BUTTON_LEFT;
		const short initialLives = 3;
		const short maxLives = 8;
		const short initialMoney = 200;
		const short acelerationMultiplyer = 25;		
		const short secondsForAcelerationDecrease = 3;
		const short initialBulletsInCharger = 6;
		const short maxBulletsChargerSupports = 36;
		const short initialMaxBullets = initialBulletsInCharger * 6;
		const short maxBulletsPlayerCanHave = 126;
		const float startingShootingTimer = 1.15f;
		const float minShootingTime = 0.225f;
		const float initialDamage = 10.0f;
		const float invulnerabilityTime = 1.8f;
		const float initialReloadTime = 2.2f;
		const float minReloadTime = 0.7f;
		const float bulletsSizeDivider = 3.0f;
		const float initialMaxAceleration = 50.0f;
		const float maxAceleration = 350.0f;
		const float initialVelocity = 50.5f;
		const float maxVelocity = 125.0f;
		const float maxDamage = 35.0f;

		static const short maxBullets = 36;
			
		short roundStartingLives;
		short lives;
		int money;
		int initialRoundMoney;
		short directionNumberMultiplyer;
		MovementStatus movementStatus;
		MovementStatus direction;
		KeyboardKey moveUpKey;
		KeyboardKey moveDownKey;
		KeyboardKey moveRightKey;
		KeyboardKey moveLeftKey;
		KeyboardKey reloadKey;
		MouseButton shootButton;
		float startingRoundVelocity;
		float velocity;
		float aceleration;
		float startingRoundShootingTime;
		float shootingTimer;
		float startingRoundDamage;
		float damage;
		float invulnerabilityTimer;
		float startingRoundReloadTime;
		float reloadTimer;		
		float startingRoundMaxAceleration;
		short startingRoundMaxBulletsInCharger;
		short bulletsInCharger;
		short startingRoundRemainingBullets;
		short remainingBullets;				
		Bullet* bullets[maxBullets];
		Rectangle gameplayMap;		
	public:
		Survivor(Color color, Vector2 position, float radius, Rectangle gameplayMap);
		~Survivor();

		void setRoundStartingLives(short lives);
		void addRoundStartingLive();
		void setLives(short lives);
		void addLive();
		void subtractLive();
		void setMoney(int money);
		void addMoney(float money);
		void setInitialRoundMoney(float initialRoundMoney);
		void setMovementStatus(MovementStatus movementStatus);
		void setDirection(MovementStatus direction);
		void setMoveUpKey(KeyboardKey key);
		void setMoveDownKey(KeyboardKey key);
		void setMoveRightKey(KeyboardKey key);
		void setMoveLeftKey(KeyboardKey key);
		void setReloadKey(KeyboardKey key);
		void setShootButton(MouseButton shootButton);
		void setStartingRoundVelocity(float startingRoundVelocity);
		void addStartingRoundVelocity(float value);
		void setVelocity(float velocity);
		void setAceleration(float aceleration);
		void setDirectionNumberMultiplyer(float directionNumberMultiplyer);		
		void setStartingRoundShootingTime(float startingRoundShootingTime);
		void addStartingRoundShootingTime(float time);
		void setShootingTimer(float shootingTimer);
		void setStartingRoundDamage(float startingRoundDamage);
		void addStartingRoundDamage(float value);
		void setDamage(float damage);
		void setInvulnerabilityTimer(float invulnerabilityTimer);
		void setStartingRoundReloadTime(float startingRoundReloadTime);
		void addStartingRoundReloadTime(float startingRoundReloadTime);
		void setReloadTimer(float reloadTimer);		
		void setStartingRoundMaxAceleration(float startingRoundMaxAceleration);
		void addStartingRoundMaxAceleration(float value);
		void setStartingRoundMaxBulletsInCharger(short startingRoundmaxBulletsInCharger);
		void addStartingRoundMaxBulletsInCharger(short value);
		void setBulletsInCharger(short bulletsInCharger);
		void decreasBulletsInCharger();
		void setStartingRoundRemainingBullets(short startingRoundRemainingBullets);
		void addStartingRoundRemainingBullets(short value);
		void setRemainingBullets(short remainingBullets);		
		void setBulletsToNull();		
		
		short getRoundStartingLives();
		short getLives();
		int getMoney();
		MovementStatus getMovementStatus();
		MovementStatus getDirection();
		KeyboardKey getMoveUpKey();
		KeyboardKey getMoveDownKey();
		KeyboardKey getMoveRightKey();
		KeyboardKey getMoveLeftKey();
		KeyboardKey getReloadKey();
		MouseButton getShootButton();
		float getStartingRoundVelocity();
		float getVelocity();
		float getAceleration();
		float getDirectionNumberMultiplyer();
		short getEmptyBulletIndex();
		Vector2 getBulletDirection();
		float getShootingTimer();
		short getMaxBullets();
		float getStartingRoundDamage();
		float getDamage();
		float getInvulnerabilityTimer();
		float getStartingRoundReloadTime();
		float getStartingRoundShootingTime();
		float getReloadTimer();		
		float getStartingRoundMaxAceleration();
		short getStartingRoundMaxBulletsInCharger();
		short getBulletsInCharger();	
		short getStartingRoundRemainingBullets();
		short getRemainingBullets();	
		short getInitialLives();
		short getMaxLives();
		float getMinReloadTime();
		float getMinShootingTime();
		short getMaxBulletsChargerSupports();
		short getMaxBulletsPlayerCanHave();
		float getMaxAceleration();
		float getMaxVelocity();
		float getMaxDamage();

		void input(bool mouseOnGameplay);
		void shootingInput(bool mouseOnGameplay);
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
		void decreaseReloadTimer();
		bool isSurvivorInvulnerable();
		void reloadInput();
		void reload();
		void drawSurvivor();
		void drawBullets();
		void destroyBullets();
		void resetSurvivor(Vector2 position);
	};
}

#endif
