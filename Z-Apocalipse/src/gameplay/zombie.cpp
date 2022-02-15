#include "zombie.h"

namespace Z_APOCALIPSE 
{
	Zombie::Zombie(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap, short level) : Character(characterColor, position, radius, gameplayMap)
	{
		setDamageTaken(0.0f);
		setDamageToDie(20.0f);
		setLevel(level);
	}

	Zombie::~Zombie() 
	{

	}

	void Zombie::setDamageTaken(float damageTaken)
	{
		this->damageTaken = damageTaken;
	}

	void Zombie::setDamageToDie(float damageToDie)
	{
		this->damageToDie = damageToDie;
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

	short Zombie::getLevel() 
	{
		return level;
	}

	void Zombie::update(Rectangle gameplayDimensions) 
	{

	}
	
	void Zombie::movementUpdate()
	{

	}
	
	void Zombie::draw() 
	{
		DrawCircleV(getPosition(), getRadius(), getCharacterColor());
	}
}