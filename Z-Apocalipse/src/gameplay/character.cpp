#include "character.h"

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Character::Character(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap)
	{
		setCharacterColor(characterColor);
		setPosition(position);
		setRadius(radius);
		setGameplayMap(gameplayMap);
	}

	void Character::setCharacterColor(Color characterColor) 
	{
		this->characterColor = characterColor;
	}

	void Character::setPosition(Vector2 position) 
	{
		this->position = position;
	}
	
	void Character::move(Vector2 distance) 
	{
		float a = getGameplayMap().y;

		if (distance.x > 0) 
		{
			if (position.x + getRadius() + distance.x < getGameplayMap().x + getGameplayMap().width)
			{
				position.x += distance.x;
			}			
		}
		else 
		{
			if (position.x - getRadius() - distance.x > getGameplayMap().x)
			{
				position.x += distance.x;
			}			
		}

		if (distance.y > 0) 
		{
			if (position.y + getRadius() + distance.y < getGameplayMap().height + getGameplayMap().y) 
			{
				position.y += distance.y;
			}			
		}		
		else 
		{
			if (position.y - getRadius() - distance.y > getGameplayMap().y) 
			{
				position.y += distance.y;
			}			
		}
	}

	void Character::setRadius(float radius)
	{
		this->radius = radius;
	}

	void Character::setGameplayMap(Rectangle gameplayMap) 
	{
		this->gameplayMap = gameplayMap;
	}
	
	Color Character::getCharacterColor()
	{
		return characterColor;
	}

	Vector2 Character::getPosition() 
	{
		return position;
	}
	
	float Character::getRadius() 
	{
		return radius;
	}

	Rectangle Character::getGameplayMap() 
	{
		return gameplayMap;
	}
}