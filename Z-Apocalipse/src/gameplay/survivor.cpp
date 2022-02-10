#include "survivor.h"

namespace Z_APOCALIPSE 
{
	Survivor::Survivor(Color color, Vector2 position, float radius) : Character(color, position, radius)
	{
		setLives(initialLives);
		setMoney(initialMoney);
	}

	void Survivor::setLives(short lives) 
	{
		this->lives = lives;
	}

	void Survivor::setMoney(short money) 
	{
		this->money = money;
	}
	
	short Survivor::getLives() 
	{
		return lives;
	}
	
	short Survivor::getMoney() 
	{
		return money;
	}

	void Survivor::input() 
	{

	}
	
	void Survivor::update() 
	{

	}
}