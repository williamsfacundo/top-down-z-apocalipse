#include "character.h"

namespace Z_APOCALIPSE 
{
	Character::Character() 
	{
		setPosition({0,0});
		setRadius(20);
	}

	void Character::setPosition(Vector2 position) 
	{
		this->position = position;
	}
	
	void Character::setRadius(float radius)
	{
		this->radius = radius;
	}
	
	Vector2 Character::getPosition() 
	{
		return position;
	}
	
	float Character::getRadius() 
	{
		return radius;
	}	
	
	void Character::draw() 
	{
		DrawCircleV(position, radius, characterColor);
	}
}