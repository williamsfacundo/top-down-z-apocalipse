#include "zombie.h"

#include <cmath>

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	short Zombie::zombiesCreated = 0;

	Zombie::Zombie(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap, short level) : Character(characterColor, position, radius, gameplayMap)
	{
		setDamageTaken(initialDamageTaken);
		setDamageToDie(initialDamageToDie);
		setVelocity(initialVelocity);
		setLevel(level);

		zombiesCreated += 1;
	}	

	Zombie::~Zombie() 
	{
		zombiesCreated -= 1;
	}

	void Zombie::setDamageTaken(float damageTaken) 
	{
		this->damageTaken = damageTaken;
	}

	void Zombie::addDamageTaken(float damage) 
	{
		damageTaken += damage;
	}

	void Zombie::setDamageToDie(float damageToDie)
	{
		this->damageToDie = damageToDie;
	}

	void Zombie::setVelocity(float velocity) 
	{
		this->velocity = velocity;
	}

	void Zombie::setLevel(short level) 
	{
		this->level = level;
	}

	float Zombie::getDamageTaken()
	{
		return damageTaken;
	}

	float Zombie::getDamageToDie() 
	{
		return damageToDie;
	}

	float Zombie::getVelocity()
	{
		return velocity;
	}

	short Zombie::getLevel() 
	{
		return level;
	}

	Vector2 Zombie::getZombieDirection(Vector2 playerPosition) 
	{
		float distanceX = playerPosition.x - getPosition().x;
		float distanceY = playerPosition.y - getPosition().y;
		double module = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
		distanceX /= static_cast<float>(module);
		distanceY /= static_cast<float>(module);
		Vector2 direction = { distanceX, distanceY };

		return direction;
	}

	short Zombie::getZombiesCreated() 
	{
		return zombiesCreated;
	}

	void Zombie::update(Vector2 playerPosition)
	{
		movementUpdate(playerPosition);
	}
	
	void Zombie::movementUpdate(Vector2 playerPosition)
	{
		move({ getZombieDirection(playerPosition).x * velocity * GetFrameTime(),
			getZombieDirection(playerPosition).y * velocity * GetFrameTime()});
	}
	
	void Zombie::draw() 
	{
		DrawCircleV(getPosition(), getRadius(), getCharacterColor());		
	}

	bool Zombie::isZombieDead() 
	{
		return (damageTaken >= damageToDie);
	}
}